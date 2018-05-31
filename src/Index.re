open Webapi.Dom;

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> Ext.Option.andThen(HtmlDocument.body)
  |> Ext.Option.unsafelyUnwrapOption
  |> Element.asEventTarget;

let initialSnake = Snake.create([(10, 10), (11, 10), (12, 10), (13, 10)]);

let initialFood = Food.create((30, 20));

let initialDirection = Direction.Right;

let initialKeys = [Key.Ignored];

let initialWorld =
  World.create(
    ~snake=initialSnake,
    ~food=initialFood,
    ~direction=initialDirection,
    ~keys=initialKeys,
  );

let state = ref(initialWorld);

let getKey = evt =>
  switch (KeyboardEvent.key(evt)) {
  | "ArrowUp" => Key.ArrowUp
  | "ArrowDown" => Key.ArrowDown
  | "ArrowLeft" => Key.ArrowLeft
  | "ArrowRight" => Key.ArrowRight
  | _ => Ignored
  };

let handleTick = () => {
  let oldWorld = state^;
  let canvas = Canvas.create("snake-game");

  let latestKey =
    try (List.hd(World.keys(oldWorld))) {
    | Failure("hd") => Key.Ignored
    };
  let newKeys =
    try (List.tl(World.keys(oldWorld))) {
    | Failure("tl") => World.keys(oldWorld)
    };

  let newDirection =
    Direction.findDirection(
      ~key=latestKey,
      ~oldDirection=World.direction(oldWorld),
    );

  let movedSnake =
    Snake.move(World.snake(oldWorld), ~direction=World.direction(oldWorld));

  /*
   Detect a snake colliding with food, when it does:
   1. Lengthen the snake
   2. Return a new food in a random position
   */
  let (newSnake, newFood) =
    if (Snake.findsFood(movedSnake, ~food=World.food(oldWorld))) {
      (
        Snake.lengthen(movedSnake, ~direction=newDirection),
        Food.randomWithinBounds(
          ~maxHeight=Canvas.height(canvas),
          ~maxWidth=Canvas.width(canvas),
          ~outsideCells=Snake.body(movedSnake),
        ),
      );
    } else {
      (movedSnake, World.food(oldWorld));
    };

  let newWorld =
    World.create(
      ~snake=newSnake,
      ~food=newFood,
      ~direction=newDirection,
      ~keys=newKeys,
    );
  state := newWorld;

  Canvas.clear(canvas);
  Canvas.drawSnake(canvas, World.snake(state^));
  Canvas.drawFood(canvas, World.food(state^));
};

Js.Global.setInterval(handleTick, 200);

let handleEvent = evt => {
  let oldWorld = state^;
  let newKeys = World.keys(oldWorld) @ [getKey(evt)];
  let newWorld =
    World.create(
      ~snake=World.snake(oldWorld),
      ~food=World.food(oldWorld),
      ~direction=World.direction(oldWorld),
      ~keys=newKeys,
    );
  state := newWorld;
};

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);