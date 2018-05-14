type t;

let create: (~snake: Snake.t, ~food: Food.t, ~direction: Direction.t) => t;

let snake: t => Snake.t;

let food: t => Food.t;

let direction: t => Direction.t;