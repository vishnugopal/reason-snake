type t;

let create: ((int, int)) => t;

let position: t => Cell.t;

let randomWithinBounds:
  (~maxWidth: int, ~maxHeight: int, ~outsideCells: list(Cell.t)) => t;