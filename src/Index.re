open Webapi.Dom;

open Webapi.Canvas;

let map = f =>
  fun
  | Some(v) => Some(f(v))
  | None => None;

let unsafelyUnwrapOption =
  fun
  | Some(v) => v
  | None => raise(Invalid_argument("Passed `None` to unsafelyUnwrapOption"));

let canvasEl =
  Document.getElementById("snake-game", document) |> unsafelyUnwrapOption;

let ctx = CanvasElement.getContext2d(canvasEl);

let canvasWidth =
  canvasEl
  |> Element.asHtmlElement
  |> map(HtmlElement.offsetWidth)
  |> unsafelyUnwrapOption;

let canvasHeight =
  canvasEl
  |> Element.asHtmlElement
  |> map(HtmlElement.offsetHeight)
  |> unsafelyUnwrapOption;

let andThen = (f: 'a => option('b)) =>
  fun
  | Some(v) => f(v)
  | None => None;

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> andThen(HtmlDocument.body)
  |> unsafelyUnwrapOption
  |> Element.asEventTarget;

type cell = {
  x: int,
  y: int,
};

type direction =
  | Up
  | Right;

type key =
  | ArrowUp
  | ArrowRight
  | Ignored;

type snake = list(cell);

type food = cell;

type world = {
  snake,
  food,
  direction,
};

let clearCanvas = ctx =>
  ctx
  |> Canvas2d.clearRect(
       ~x=0.,
       ~y=0.,
       ~w=float_of_int(canvasWidth),
       ~h=float_of_int(canvasHeight),
     );

let drawCell = (ctx, fillColor, cell) => {
  Canvas2d.setFillStyle(ctx, String, fillColor);
  Canvas2d.setStrokeStyle(ctx, String, "white");
  Canvas2d.fillRect(
    ~x=float(cell.x) *. 10.,
    ~y=float(cell.y) *. 10.,
    ~w=10.,
    ~h=10.,
    ctx,
  );
  Canvas2d.strokeRect(
    ~x=float(cell.x) *. 10.,
    ~y=float(cell.y) *. 10.,
    ~w=10.,
    ~h=10.,
    ctx,
  );
};

let drawSnakeCell = drawCell(ctx, "#1179BF");

let drawFoodCell = drawCell(ctx, "#af2010");

let drawSnake = snake => List.iter(drawSnakeCell, snake);

let drawFood = food => drawFoodCell(food);

let moveSnake = snake => List.map(cell => {...cell, x: cell.x + 1}, snake);

let initialSnake = [
  {x: 10, y: 10},
  {x: 11, y: 10},
  {x: 12, y: 10},
  {x: 13, y: 10},
];

let initialFood = {x: 30, y: 20};

let initialDirection = Right;

let initialWorld = {
  snake: initialSnake,
  food: initialFood,
  direction: initialDirection,
};

let state = ref(initialWorld);

let drawWorld = (ctx, state) => {
  clearCanvas(ctx);
  drawSnake(state.snake);
  drawFood(state.food);
};

let getKey = evt =>
  switch (KeyboardEvent.key(evt)) {
  | "ArrowUp" => ArrowUp
  | "ArrowRight" => ArrowRight
  | _ => Ignored
  };

let handleTick = () => {
  let oldWorld = state^;
  let newWorld = {...oldWorld, snake: moveSnake(oldWorld.snake)};
  state := newWorld;
  Js.log(state^.direction);
  drawWorld(ctx, newWorld);
};

Js.Global.setInterval(handleTick, 300);

let handleEvent = evt => {
  let oldWorld = state^;
  let newWorld = {
    ...oldWorld,
    direction:
      switch (getKey(evt)) {
      | ArrowUp => Up
      | ArrowRight => Right
      | Ignored => oldWorld.direction
      },
  };
  state := newWorld;
};

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);