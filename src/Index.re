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

let drawScene = ctx => {
  ctx
  |> Canvas2d.clearRect(
       ~x=0.,
       ~y=0.,
       ~w=float_of_int(canvasWidth),
       ~h=float_of_int(canvasHeight),
     );
  /* Snake */
  /* Canvas2d.setFillStyle(ctx, String, fillColor);
  Canvas2d.fillRect(~x, ~y, ~w, ~h, ctx);
  Canvas2d.setStrokeStyle(ctx, String, strokeColor);
  Canvas2d.strokeRect(~x, ~y, ~w, ~h, ctx); */

  Canvas2d.setFillStyle(ctx, String, "#1179BF");
  Canvas2d.setStrokeStyle(ctx, String, "white");
  /* Right */
  ctx |> Canvas2d.fillRect(~x=40., ~y=0., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=40., ~y=0., ~w=10., ~h=10.);
  ctx |> Canvas2d.fillRect(~x=50., ~y=0., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=50., ~y=0., ~w=10., ~h=10.);
  /* Down */
  ctx |> Canvas2d.fillRect(~x=50., ~y=10., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=50., ~y=10., ~w=10., ~h=10.);
  ctx |> Canvas2d.fillRect(~x=50., ~y=20., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=50., ~y=20., ~w=10., ~h=10.);
  ctx |> Canvas2d.fillRect(~x=50., ~y=30., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=50., ~y=30., ~w=10., ~h=10.);
  ctx |> Canvas2d.fillRect(~x=50., ~y=40., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=50., ~y=40., ~w=10., ~h=10.);
  ctx |> Canvas2d.fillRect(~x=50., ~y=50., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=50., ~y=50., ~w=10., ~h=10.);
  /* Right */
  ctx |> Canvas2d.fillRect(~x=60., ~y=50., ~w=10., ~h=10.);
  ctx |> Canvas2d.strokeRect(~x=60., ~y=50., ~w=10., ~h=10.);
};

ctx |> drawScene;