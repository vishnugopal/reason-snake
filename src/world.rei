type t;

let create:
  (
    ~snake: Snake.t,
    ~food: Food.t,
    ~direction: Direction.t,
    ~keys: list(Key.t),
    ~foodAte: int,
    ~gameOver: bool
  ) =>
  t;

let snake: t => Snake.t;
let food: t => Food.t;
let direction: t => Direction.t;
let keys: t => list(Key.t);
let foodAte: t => int;
let isGameOver: t => bool;