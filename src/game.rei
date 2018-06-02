type t;

let create: (~drawingCanvasElement: string, ~scorerElement: string) => t;
let reset: t => unit;

let world: t => World.t;
let setWorld: (t, World.t) => unit;

let isGameOver: t => bool;
let runTick: t => unit;