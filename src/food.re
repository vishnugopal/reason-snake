type t = Cell.t;

let create: ((int, int)) => t = Cell.create;

let position = t => Cell.create((Cell.x(t), Cell.y(t)));

let rec randomWithinBounds =
        (
          ~maxWidth: int,
          ~maxHeight: int,
          ~outsideCells as cells: list(Cell.t),
        ) => {
  let randomX = Random.int(maxWidth - 1) + 1;
  let randomY = Random.int(maxHeight - 1) + 1;
  if (List.exists(
        (cell: Cell.t) =>
          Cell.x(cell) == randomX && Cell.y(cell) == randomY,
        cells,
      )) {
    randomWithinBounds(~maxWidth, ~maxHeight, ~outsideCells=cells);
  } else {
    create((randomX, randomY));
  };
};