type t;

let create: list((int, int)) => t;

let move: (t, ~fromDirection: Direction.t, ~toDirection: Direction.t) => t;

let convertToCells: t => list(Cell.t);