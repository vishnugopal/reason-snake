type t = list(Cell.t);

let create = xs => List.map(Cell.create, xs);

let move = t =>
  List.map(cell => Cell.create((Cell.x(cell) + 1, Cell.y(cell))), t);

let convertToCells: t => list(Cell.t) = t => t;