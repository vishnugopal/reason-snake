type t = {
  snake: Snake.t,
  food: Food.t,
  direction: Direction.t,
  keys: list(Key.t),
};

let create = (~snake, ~food, ~direction, ~keys) => {
  snake,
  food,
  direction,
  keys,
};

let snake = t => t.snake;

let food = t => t.food;

let direction = t => t.direction;

let keys = t => t.keys;