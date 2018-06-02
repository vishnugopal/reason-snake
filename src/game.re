type t = {
  state: ref(World.t), /* This holds all game state */
  drawingCanvas: Canvas.t, /* The canvas to draw to */
  /* To draw the score */
  scorer: Scorer.t,
  scoreMultiplier: int,
  /* Initial states, used when we want to reset game */
  initialSnake: Snake.t,
  initialFood: Food.t,
  initialDirection: Direction.t,
  initialKeys: list(Key.t),
  initialFoodAte: int,
  initialGameOver: bool,
  initialScore: int,
};

let create = (~drawingCanvasElement: string, ~scorerElement: string) => {
  let initialSnake =
    Snake.create([(13, 10), (12, 10), (11, 10), (10, 10)]);
  let initialFood = Food.create((30, 20));
  let initialDirection = Direction.Right;
  let initialKeys = [Key.Ignored];
  let initialFoodAte = 0;
  let initialGameOver = false;
  let initialScore = 0;

  let initialWorld =
    World.create(
      ~snake=initialSnake,
      ~food=initialFood,
      ~direction=initialDirection,
      ~keys=initialKeys,
      ~foodAte=initialFoodAte,
      ~gameOver=initialGameOver,
    );

  let drawingCanvas = Canvas.create(drawingCanvasElement);
  let scorer = Scorer.create(~elementID=scorerElement, ~initialScore);
  let initialScoreMultipler = 1;

  {
    state: ref(initialWorld),
    drawingCanvas,
    scorer,
    scoreMultiplier: initialScoreMultipler,
    initialSnake,
    initialFood,
    initialDirection,
    initialKeys,
    initialFoodAte,
    initialGameOver,
    initialScore,
  };
};

let world = (game: t) => game.state^;
let setWorld = (game: t, newWorld: World.t) => game.state := newWorld;
let canvas = (game: t) => game.drawingCanvas;

let reset = (game: t) => {
  let resetWorld =
    World.create(
      ~snake=game.initialSnake,
      ~food=game.initialFood,
      ~direction=game.initialDirection,
      ~keys=game.initialKeys,
      ~foodAte=game.initialFoodAte,
      ~gameOver=game.initialGameOver,
    );
  setWorld(game, resetWorld);
  ();
};

let isGameOver = (game: t) => {
  let world = world(game);
  let snake = World.snake(world);

  World.isGameOver(world)
  || Snake.bitesTail(snake)
  || Snake.crashesIntoWall(
       snake,
       ~maxHeight=Canvas.height(canvas(game)),
       ~maxWidth=Canvas.width(canvas(game)),
     );
};

let processKeys = (game: t) : (list(Key.t), Direction.t) => {
  let world = world(game);
  let latestKey =
    try (List.hd(World.keys(world))) {
    | Failure("hd") => Key.Ignored
    };
  let newKeys =
    try (List.tl(World.keys(world))) {
    | Failure("tl") => World.keys(world)
    };

  let newDirection =
    Direction.findDirection(
      ~key=latestKey,
      ~oldDirection=World.direction(world),
    );

  (newKeys, newDirection);
};

let moveSnake = (game: t) => {
  let world = world(game);
  Snake.move(World.snake(world), ~direction=World.direction(world));
};

/**
Detect a snake colliding with food, when it does:
1. Lengthen the snake
2. Return a new food in a random position
3. Returns +1 for foodAte
*/
let processSnakeEatingFood =
    (
      game: t,
      ~snake: Snake.t,
      ~food: Food.t,
      ~direction: Direction.t,
      ~foodAte: int,
    )
    : (Snake.t, Food.t, int) => {
  let (newSnake, newFood, newFoodAte) =
    if (Snake.findsFood(snake, ~food)) {
      (
        Snake.lengthen(snake, ~direction),
        Food.randomWithinBounds(
          ~maxHeight=Canvas.height(canvas(game)),
          ~maxWidth=Canvas.width(canvas(game)),
          ~outsideCells=Snake.body(snake),
        ),
        foodAte + 1,
      );
    } else {
      (snake, food, foodAte);
    };
  (newSnake, newFood, newFoodAte);
};

let setScore = (game: t) =>
  Scorer.update(
    game.scorer,
    game.scoreMultiplier * World.foodAte(world(game)),
  );

let drawCanvas = (game: t) => {
  Canvas.clear(canvas(game));
  Canvas.drawSnake(canvas(game), World.snake(world(game)));
  Canvas.drawFood(canvas(game), World.food(world(game)));
};

/**
 * Responsible for updating the game world state on each tick:
 * 1. Processes keys
 * 2. Moves the snake in the current direction.
 * 3. Checks if game is over (snake has bitten its tail)
 * 4. Checks if snake has eaten a food, if so makes a longer snake & a new food
 * 5. Sets a new game world based on previous conditions.
 * 6. Sets a score based on food eaten.
 * 7. and finally, draws the game world to canvas.
 */
let runTick = (snakeGame: t) => {
  let (newKeys, newDirection) = processKeys(snakeGame);
  let movedSnake = moveSnake(snakeGame);
  let newGameOver = isGameOver(snakeGame);
  let (newSnake, newFood, newFoodAte) =
    processSnakeEatingFood(
      snakeGame,
      ~snake=movedSnake,
      ~food=World.food(world(snakeGame)),
      ~direction=newDirection,
      ~foodAte=World.foodAte(world(snakeGame)),
    );

  let newWorld =
    World.create(
      ~snake=newSnake,
      ~food=newFood,
      ~direction=newDirection,
      ~keys=newKeys,
      ~foodAte=newFoodAte,
      ~gameOver=newGameOver,
    );
  setWorld(snakeGame, newWorld);

  setScore(snakeGame);
  drawCanvas(snakeGame);
};