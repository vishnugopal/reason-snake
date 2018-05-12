type t = {
  x: int,
  y: int,
};

let x = t => t.x;

let y = t => t.y;

let create = ((x, y)) => {x, y};