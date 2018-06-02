type t = {
  snake: Snake.t,
  food: Food.t,
  direction: Direction.t,
  keys: list(Key.t),
  foodAte: int,
  gameOver: bool,
};

let create = (~snake, ~food, ~direction, ~keys, ~foodAte, ~gameOver) => {
  snake,
  food,
  direction,
  keys,
  foodAte,
  gameOver,
};

let snake = t => t.snake;

let food = t => t.food;

let direction = t => t.direction;

let keys = t => t.keys;
let foodAte = t => t.foodAte;
let isGameOver = t => t.gameOver;