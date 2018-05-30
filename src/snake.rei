type t;

let create: list((int, int)) => t;

let move: (t, ~toDirection: Direction.t) => t;

let resize: (~snake: t, ~food: Food.t) => (t, Food.t);

let body: t => list(Cell.t);