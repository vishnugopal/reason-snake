type t;

let create: ((int, int)) => t;

let position: t => Cell.t;

let randomWithinBounds: (~maxWidth: int, ~maxHeight: int) => t;