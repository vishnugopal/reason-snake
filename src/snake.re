type t = list(Cell.t);

let create = xs => List.map(Cell.create, xs);

/**

 Move a snake.

 Steps:
 1. Delete last cell.
 2. Insert a new cell at the beginning which has new coordinates according to the direction.
 */
let move_ = (snake: t, ~direction: Direction.t, ~deleteLast: bool) : t => {
  let rec deleteLastCell = (snake: t) : t =>
    if (deleteLast) {
      switch (snake) {
      | [] => []
      | [_] => []
      | [first, ...tail] => [first] @ deleteLastCell(tail)
      };
    } else {
      snake;
    };
  let moveUpSingle = cell => Cell.create((Cell.x(cell), Cell.y(cell) - 1));
  let moveDownSingle = cell =>
    Cell.create((Cell.x(cell), Cell.y(cell) + 1));
  let moveLeftSingle = cell =>
    Cell.create((Cell.x(cell) - 1, Cell.y(cell)));
  let moveRightSingle = cell =>
    Cell.create((Cell.x(cell) + 1, Cell.y(cell)));
  switch (snake, direction) {
  | ([], _) => []
  | ([head, ...tail], Direction.Up) =>
    [moveUpSingle(head)] @ [head] @ deleteLastCell(tail)
  | ([head, ...tail], Direction.Down) =>
    [moveDownSingle(head)] @ [head] @ deleteLastCell(tail)
  | ([head, ...tail], Direction.Left) =>
    [moveLeftSingle(head)] @ [head] @ deleteLastCell(tail)
  | ([head, ...tail], Direction.Right) =>
    [moveRightSingle(head)] @ [head] @ deleteLastCell(tail)
  };
};

let move = (snake: t, ~direction: Direction.t) : t =>
  snake |. move_(~direction, ~deleteLast=true);

let findsFood = (snake: t, ~food: Food.t) : bool =>
  List.hd(snake) == Food.position(food);

let lengthen = (snake: t, ~direction: Direction.t) : t =>
  move_(snake, ~direction, ~deleteLast=false);

let rec bitesTail = (snake: t) : bool =>
  switch (snake) {
  | [] => false
  | [hd, ...tl] => List.exists(el => el == hd, tl) || bitesTail(tl)
  };

let crashesIntoWall = (snake: t, ~maxHeight: int, ~maxWidth: int) : bool => {
  let headCell = List.hd(snake);
  Cell.x(headCell) < 1
  || Cell.x(headCell) >= maxWidth
  - 1
  || Cell.y(headCell) < 1
  || Cell.y(headCell) >= maxHeight
  - 1;
};

let body: t => list(Cell.t) = t => t;