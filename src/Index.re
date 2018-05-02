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

let drawCell = (ctx, cell) => {
  Canvas2d.setFillStyle(ctx, String, "#1179BF");
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

let snake = [
  {x: 10, y: 10},
  {x: 11, y: 10},
  {x: 12, y: 10},
  {x: 13, y: 10},
];

let drawSnake = (ctx, snake) => List.iter(drawCell(ctx), snake);

let renderSnake = drawSnake(ctx);

let clearCanvas = ctx =>
  ctx
  |> Canvas2d.clearRect(
       ~x=0.,
       ~y=0.,
       ~w=float_of_int(canvasWidth),
       ~h=float_of_int(canvasHeight),
     );

let renderScene = ctx => {
  clearCanvas(ctx);
  renderSnake(snake);
  Js.log("drawing");
};

Js.Global.setInterval(() => renderScene(ctx), 300);