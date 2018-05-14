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

let initialWorld =
  World.create(
    ~snake=initialSnake,
    ~food=initialFood,
    ~direction=initialDirection,
  );

let state = ref(initialWorld);

let getKey = evt =>
  switch (KeyboardEvent.key(evt)) {
  | "ArrowUp" => Key.ArrowUp
  | "ArrowRight" => Key.ArrowRight
  | _ => Ignored
  };

let handleTick = () => {
  let oldWorld = state^;
  let newWorld =
    World.create(
      ~snake=Snake.move(World.snake(oldWorld)),
      ~food=World.food(oldWorld),
      ~direction=World.direction(oldWorld),
    );
  state := newWorld;
  Draw.clearCanvas();
  Draw.drawSnake(World.snake(state^));
  Draw.drawFood(World.food(state^));
};

Js.Global.setInterval(handleTick, 300);

let handleEvent = evt => {
  let oldWorld = state^;
  let newDirection =
    switch (getKey(evt)) {
    | Key.ArrowUp => Direction.Up
    | Key.ArrowRight => Direction.Right
    | Key.Ignored => World.direction(oldWorld)
    };
  let newWorld =
    World.create(
      ~snake=World.snake(oldWorld),
      ~food=World.food(oldWorld),
      ~direction=newDirection,
    );
  state := newWorld;
};

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);