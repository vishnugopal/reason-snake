type t;

let create: string => t;

let clear: t => unit;

let drawSnake: (t, Snake.t) => unit;

let drawFood: (t, Food.t) => unit;