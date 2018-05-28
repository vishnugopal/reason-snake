type t =
  | Up
  | Down
  | Left
  | Right;

let findDirection = (~key: Key.t, ~oldDirection: t) =>
  switch (key, oldDirection) {
  /* Ignore inputs opposite to the current direction */
  | (Key.ArrowUp, Down)
  | (Key.ArrowDown, Up)
  | (Key.ArrowRight, Left)
  | (Key.ArrowLeft, Right) => oldDirection
  /* Otherwise, change direction */
  | (Key.ArrowUp, _) => Up
  | (Key.ArrowDown, _) => Down
  | (Key.ArrowLeft, _) => Left
  | (Key.ArrowRight, _) => Right
  /* And ignore keys that are not direction keys */
  | (Key.Ignored, _) => oldDirection
  };