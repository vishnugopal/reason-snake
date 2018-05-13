open Webapi.Dom;

open Webapi.Canvas;

let canvasEl =
  Document.getElementById("snake-game", document)
  |> Ext.Option.unsafelyUnwrapOption;

let ctx = CanvasElement.getContext2d(canvasEl);

let canvasWidth =
  canvasEl
  |> Element.asHtmlElement
  |> Ext.Option.map(HtmlElement.offsetWidth)
  |> Ext.Option.unsafelyUnwrapOption;

let canvasHeight =
  canvasEl
  |> Element.asHtmlElement
  |> Ext.Option.map(HtmlElement.offsetHeight)
  |> Ext.Option.unsafelyUnwrapOption;

let clearCanvas = () =>
  ctx
  |> Canvas2d.clearRect(
       ~x=0.,
       ~y=0.,
       ~w=float_of_int(canvasWidth),
       ~h=float_of_int(canvasHeight),
     );

let drawCell = (fillColor, cell) => {
  Canvas2d.setFillStyle(ctx, String, fillColor);
  Canvas2d.setStrokeStyle(ctx, String, "white");
  Canvas2d.fillRect(
    ~x=float(Cell.x(cell)) *. 10.,
    ~y=float(Cell.y(cell)) *. 10.,
    ~w=10.,
    ~h=10.,
    ctx,
  );
  Canvas2d.strokeRect(
    ~x=float(Cell.x(cell)) *. 10.,
    ~y=float(Cell.y(cell)) *. 10.,
    ~w=10.,
    ~h=10.,
    ctx,
  );
};

let drawSnakeCell = drawCell("#1179BF");

let drawFoodCell = drawCell("#af2010");

let drawSnake = snake => List.iter(drawSnakeCell, snake);

let drawFood = food => drawFoodCell(food);