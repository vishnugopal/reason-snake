type t;

let create: string => t;

let clear: t => unit;

let width: t => int;

let height: t => int;

let drawSnake: (t, Snake.t) => unit;

let drawFood: (t, Food.t) => unit;