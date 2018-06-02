type t = {
  state: ref(World.t), /* This holds all game state */
  drawingCanvas: Canvas.t, /* The canvas to draw to */
  /* Initial states, used when we want to reset game */
  initialSnake: Snake.t,
  initialFood: Food.t,
  initialDirection: Direction.t,
  initialKeys: list(Key.t),
  initialGameOver: bool,
};

let create = () => {
  let initialSnake =
    Snake.create([(13, 10), (12, 10), (11, 10), (10, 10)]);
  let initialFood = Food.create((30, 20));
  let initialDirection = Direction.Right;
  let initialKeys = [Key.Ignored];
  let initialGameOver = false;

  let initialWorld =
    World.create(
      ~snake=initialSnake,
      ~food=initialFood,
      ~direction=initialDirection,
      ~keys=initialKeys,
      ~gameOver=initialGameOver,
    );
  let drawingCanvas = Canvas.create("snake-game");

  {
    state: ref(initialWorld),
    initialSnake,
    initialFood,
    initialDirection,
    initialKeys,
    drawingCanvas,
    initialGameOver,
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
*/
let processSnakeEatingFood =
    (game: t, ~snake: Snake.t, ~food: Food.t, ~direction: Direction.t)
    : (Snake.t, Food.t) => {
  let (newSnake, newFood) =
    if (Snake.findsFood(snake, ~food)) {
      (
        Snake.lengthen(snake, ~direction),
        Food.randomWithinBounds(
          ~maxHeight=Canvas.height(canvas(game)),
          ~maxWidth=Canvas.width(canvas(game)),
          ~outsideCells=Snake.body(snake),
        ),
      );
    } else {
      (snake, food);
    };
  (newSnake, newFood);
};

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
 * 6. and finally, draws the game world to canvas.
 */
let runTick = (snakeGame: t) => {
  let (newKeys, newDirection) = processKeys(snakeGame);
  let movedSnake = moveSnake(snakeGame);
  let newGameOver = isGameOver(snakeGame);
  let (newSnake, newFood) =
    processSnakeEatingFood(
      snakeGame,
      ~snake=movedSnake,
      ~food=World.food(world(snakeGame)),
      ~direction=newDirection,
    );

  let newWorld =
    World.create(
      ~snake=newSnake,
      ~food=newFood,
      ~direction=newDirection,
      ~keys=newKeys,
      ~gameOver=newGameOver,
    );
  setWorld(snakeGame, newWorld);

  drawCanvas(snakeGame);
};