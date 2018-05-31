type t;

let create: list((int, int)) => t;

let move: (~deleteLast: bool=?, t, ~direction: Direction.t) => t;

let collidesWith: (t, ~food: Food.t) => bool;

let lengthen: (t, ~direction: Direction.t) => t;

let body: t => list(Cell.t);