type t;

let create: (~elementID: string, ~initialScore: int) => t;
let update: (t, int) => unit;