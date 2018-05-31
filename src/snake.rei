type t;

let create: list((int, int)) => t;

let move: (~deleteLast: bool=?, t, ~direction: Direction.t) => t;

let resize: (t, ~food: Food.t, ~direction: Direction.t) => (t, Food.t);

let body: t => list(Cell.t);