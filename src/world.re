type t = {
  snake: Snake.t,
  food: Food.t,
  direction: Direction.t,
  keys: list(Key.t),
  gameOver: bool,
};

let create = (~snake, ~food, ~direction, ~keys, ~gameOver) => {
  snake,
  food,
  direction,
  keys,
  gameOver,
};

let snake = t => t.snake;

let food = t => t.food;

let direction = t => t.direction;

let keys = t => t.keys;
let isGameOver = t => t.gameOver;