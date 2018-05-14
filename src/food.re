type t = Cell.t;

let create: ((int, int)) => t = Cell.create;

let convertToCell = t => Cell.create((Cell.x(t), Cell.y(t)));