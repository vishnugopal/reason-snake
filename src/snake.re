type t = list(Cell.t);

let create = xs => List.map(Cell.create, xs);

/*

 Move up moves a snake up.

 Steps:
 1. Delete last cell.
 2. Insert a new cell at the beginning which has (x, y - 1)

 */
let moveSnake = (snake: t, direction: Direction.t) : t => {
  let rec deleteLast = (snake: t) : t =>
    switch (snake) {
    | [] => []
    | [_] => []
    | [first, ...tail] => [first] @ deleteLast(tail)
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
    [moveUpSingle(head)] @ [head] @ deleteLast(tail)
  | ([head, ...tail], Direction.Down) =>
    [moveDownSingle(head)] @ [head] @ deleteLast(tail)
  | ([head, ...tail], Direction.Left) =>
    [moveLeftSingle(head)] @ [head] @ deleteLast(tail)
  | ([head, ...tail], Direction.Right) =>
    [moveRightSingle(head)] @ [head] @ deleteLast(tail)
  };
};

let move = (t, ~fromDirection: Direction.t, ~toDirection: Direction.t) =>
  switch (fromDirection, toDirection) {
  | (Up, Up)
  | (Right, Up)
  | (Left, Up) => moveSnake(t, toDirection)
  | (Right, Right)
  | (Up, Right)
  | (Down, Right) => moveSnake(t, toDirection)
  | (Up, Left)
  | (Down, Left)
  | (Left, Left) => moveSnake(t, toDirection)
  | (Left, Down)
  | (Right, Down)
  | (Down, Down) => moveSnake(t, toDirection)
  | (Down, Up)
  | (Up, Down)
  | (Left, Right)
  | (Right, Left) => t
  };

let convertToCells: t => list(Cell.t) = t => t;