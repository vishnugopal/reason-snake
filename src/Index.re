open Webapi.Dom;

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> Ext.Option.andThen(HtmlDocument.body)
  |> Ext.Option.unsafelyUnwrapOption
  |> Element.asEventTarget;

let getKey = evt =>
  switch (KeyboardEvent.key(evt)) {
  | "ArrowUp" => Key.ArrowUp
  | "ArrowDown" => Key.ArrowDown
  | "ArrowLeft" => Key.ArrowLeft
  | "ArrowRight" => Key.ArrowRight
  | _ => Ignored
  };

let snakeGame =
  Game.create(~drawingCanvasElement="snake-game", ~scorerElement="scorer");

let handleTick = () =>
  if (Game.isGameOver(snakeGame)) {
    Window.alert("Game over! Starting a new game!", window);
    Game.reset(snakeGame);
  } else {
    Game.runTick(snakeGame);
  };

let handleEvent = evt => {
  let oldWorld = Game.world(snakeGame);
  let newKeys = World.keys(oldWorld) @ [getKey(evt)];
  let newWorld =
    World.create(
      ~snake=World.snake(oldWorld),
      ~food=World.food(oldWorld),
      ~direction=World.direction(oldWorld),
      ~keys=newKeys,
      ~foodAte=World.foodAte(oldWorld),
      ~gameOver=World.isGameOver(oldWorld),
    );
  Game.setWorld(snakeGame, newWorld);
};

Js.Global.setInterval(handleTick, 200);

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);