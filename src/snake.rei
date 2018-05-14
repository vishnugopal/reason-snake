type t;

let create: list((int, int)) => t;

let move: t => t;

let convertToCells: t => list(Cell.t);