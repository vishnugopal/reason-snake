type t = list(Cell.t);

let create = xs => List.map(Cell.create, xs);

/*

 Move a snake.

 Steps:
 1. Delete last cell.
 2. Insert a new cell at the beginning which has new coordinates according to the direction.

 */
let move = (~deleteLast=true, snake: t, ~direction: Direction.t) : t => {
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

let resize = (snake: t, ~food: Food.t, ~direction: Direction.t) => {
  let headCell = List.hd(snake);
  if (headCell == Food.position(food)) {
    (move(snake, ~direction, ~deleteLast=false), food);
  } else {
    (snake, food);
  };
};

let body: t => list(Cell.t) = t => t;