module Option = {
  let map = (f, t) =>
    switch (t) {
    | Some(v) => Some(f(v))
    | None => None
    };
  let unsafelyUnwrapOption = t =>
    switch (t) {
    | Some(v) => v
    | None =>
      raise(Invalid_argument("Passed `None` to unsafelyUnwrapOption"))
    };
  let andThen = (f: 'a => option('b)) =>
    fun
    | Some(v) => f(v)
    | None => None;
};