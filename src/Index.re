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
  let latestKey =
    try (List.hd(World.keys(oldWorld))) {
    | Failure("hd") => Key.Ignored
    };
  let newKeys =
    try (List.tl(World.keys(oldWorld))) {
    | Failure("tl") => World.keys(oldWorld)
    };
  let newDirection =
    switch (latestKey, World.direction(oldWorld)) {
    /* Ignore inputs opposite to the current direction */
    | (Key.ArrowUp, Direction.Down)
    | (Key.ArrowDown, Direction.Up)
    | (Key.ArrowRight, Direction.Left)
    | (Key.ArrowLeft, Direction.Right) => World.direction(oldWorld)
    /* Otherwise, change direction */
    | (Key.ArrowUp, _) => Direction.Up
    | (Key.ArrowDown, _) => Direction.Down
    | (Key.ArrowLeft, _) => Direction.Left
    | (Key.ArrowRight, _) => Direction.Right
    /* And ignore keys that are not direction keys */
    | (Key.Ignored, _) => World.direction(oldWorld)
    };
  let newWorld =
    World.create(
      ~snake=
        Snake.move(
          World.snake(oldWorld),
          ~toDirection=World.direction(oldWorld),
        ),
      ~food=World.food(oldWorld),
      ~direction=newDirection,
      ~keys=newKeys,
    );
  state := newWorld;
  Draw.clearCanvas();
  Draw.drawSnake(World.snake(state^));
  Draw.drawFood(World.food(state^));
};

Js.Global.setInterval(handleTick, 300);

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