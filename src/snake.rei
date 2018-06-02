type t;

let create: list((int, int)) => t;

let move: (t, ~direction: Direction.t) => t;

let findsFood: (t, ~food: Food.t) => bool;

let lengthen: (t, ~direction: Direction.t) => t;

let bitesTail: t => bool;

let body: t => list(Cell.t);