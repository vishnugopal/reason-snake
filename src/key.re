open Webapi.Dom;

type t =
  | ArrowUp
  | ArrowDown
  | ArrowLeft
  | ArrowRight
  | Ignored;

let ofEvent = evt =>
  switch (KeyboardEvent.key(evt)) {
  | "ArrowUp" => ArrowUp
  | "ArrowDown" => ArrowDown
  | "ArrowLeft" => ArrowLeft
  | "ArrowRight" => ArrowRight
  | _ => Ignored
  };