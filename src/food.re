type t = Cell.t;

let create: ((int, int)) => t = Cell.create;

let position = t => Cell.create((Cell.x(t), Cell.y(t)));

let randomWithinBounds = (~maxWidth: int, ~maxHeight: int) => {
  let randomX = Random.int(maxWidth - 1) + 1;
  let randomY = Random.int(maxHeight - 1) + 1;
  create((randomX, randomY));
};