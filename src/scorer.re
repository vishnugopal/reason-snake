open Webapi.Dom;

type t = {
  scoreEl: Dom.element,
  score: int,
};

let create = (~elementID: string, ~initialScore: int) => {
  let scoreEl =
    Document.getElementById(elementID, document)
    |> Ext.Option.unsafelyUnwrapOption;
  {scoreEl, score: initialScore};
};

let update = (score: t, newScore: int) =>
  Element.setInnerText(score.scoreEl, "Score: " ++ string_of_int(newScore));