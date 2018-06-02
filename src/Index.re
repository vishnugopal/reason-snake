open Webapi.Dom;

let snakeGame =
  Game.create(~drawingCanvasElement="snake-game", ~scorerElement="scorer");

let handleTick = () =>
  if (Game.isGameOver(snakeGame)) {
    Window.alert("Game over! Starting a new game!", window);
    Game.reset(snakeGame);
  } else {
    Game.doTick(snakeGame);
  };

let handleKey = evt => Game.processKey(snakeGame, ~key=Key.ofEvent(evt));

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> Ext.Option.andThen(HtmlDocument.body)
  |> Ext.Option.unsafelyUnwrapOption
  |> Element.asEventTarget;

Js.Global.setInterval(handleTick, 200);

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleKey,
  documentEventTarget,
);