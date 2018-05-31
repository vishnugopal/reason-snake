open Webapi.Dom;
open Webapi.Canvas;

type t = {
  canvasWidth: int,
  canvasHeight: int,
  canvasEl: Dom.element,
  ctx: Webapi.Canvas.Canvas2d.t,
};

let create = (elementID: string) => {
  let canvasEl =
    Document.getElementById(elementID, document)
    |> Ext.Option.unsafelyUnwrapOption;
  let ctx = CanvasElement.getContext2d(canvasEl);
  let canvasWidth =
    canvasEl
    |> Element.asHtmlElement
    |> Ext.Option.map(HtmlElement.offsetWidth)
    |> Ext.Option.unsafelyUnwrapOption;
  ();
  let canvasHeight =
    canvasEl
    |> Element.asHtmlElement
    |> Ext.Option.map(HtmlElement.offsetHeight)
    |> Ext.Option.unsafelyUnwrapOption;
  {canvasWidth, canvasHeight, canvasEl, ctx};
};

let clear = t =>
  t.ctx
  |> Canvas2d.clearRect(
       ~x=0.,
       ~y=0.,
       ~w=float_of_int(t.canvasWidth),
       ~h=float_of_int(t.canvasHeight),
     );

let cellWidth = 10;
let cellHeight = 10;

let drawCell = (t, fillColor, cell) => {
  Canvas2d.setFillStyle(t.ctx, String, fillColor);
  Canvas2d.setStrokeStyle(t.ctx, String, "white");
  Canvas2d.fillRect(
    ~x=float(Cell.x(cell)) *. float_of_int(cellWidth),
    ~y=float(Cell.y(cell)) *. float_of_int(cellHeight),
    ~w=float_of_int(cellWidth),
    ~h=float_of_int(cellHeight),
    t.ctx,
  );
  Canvas2d.strokeRect(
    ~x=float(Cell.x(cell)) *. float_of_int(cellWidth),
    ~y=float(Cell.y(cell)) *. float_of_int(cellHeight),
    ~w=float_of_int(cellWidth),
    ~h=float_of_int(cellHeight),
    t.ctx,
  );
};

let width = t => t.canvasWidth / cellWidth;

let height = t => t.canvasHeight / cellHeight;

let drawSnakeCell = t => drawCell(t, "#1179BF");

let drawFoodCell = t => drawCell(t, "#af2010");

let drawSnake = (t, snake) =>
  List.iter(drawSnakeCell(t), Snake.body(snake));

let drawFood = (t, food) => drawFoodCell(t, Food.position(food));