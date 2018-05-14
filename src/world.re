type t = {
  snake: Snake.t,
  food: Food.t,
  direction: Direction.t,
};

let create = (~snake, ~food, ~direction) => {snake, food, direction};

let snake = t => t.snake;

let food = t => t.food;

let direction = t => t.direction;