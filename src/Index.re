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

type cell = {
  x: int,
  y: int,
};

type snake = list(cell);

type food = cell;

type world = {
  snake,
  food,
};

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

let drawFoodCell = drawCell(ctx, "af2010");

let drawSnake = snake => List.iter(drawSnakeCell, snake);

let drawFood = food => drawFoodCell(food);

let moveSnake = snake => List.map(cell => {...cell, x: cell.x + 1}, snake);

let clearCanvas = ctx =>
  ctx
  |> Canvas2d.clearRect(
       ~x=0.,
       ~y=0.,
       ~w=float_of_int(canvasWidth),
       ~h=float_of_int(canvasHeight),
     );

let initialSnake = [
  {x: 10, y: 10},
  {x: 11, y: 10},
  {x: 12, y: 10},
  {x: 13, y: 10},
];

let initialFood = {x: 30, y: 20};

let initialWorld = {snake: initialSnake, food: initialFood};

let state = ref(initialWorld);

let renderWorld = (ctx, state) => {
  clearCanvas(ctx);
  drawSnake(state.snake);
  drawFood(state.food);
  Js.log("drawing");
};

Js.Global.setInterval(
  () => {
    let oldWorld = state^;
    let newWorld = {snake: moveSnake(oldWorld.snake), food: oldWorld.food};
    state := newWorld;
    renderWorld(ctx, newWorld);
  },
  300,
);