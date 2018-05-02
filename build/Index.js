/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, {
/******/ 				configurable: false,
/******/ 				enumerable: true,
/******/ 				get: getter
/******/ 			});
/******/ 		}
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "/Users/vishnugopal/Developer/vishnugopal/reason-snake-starter/build/";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 5);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



var out_of_memory = /* tuple */[
  "Out_of_memory",
  0
];

var sys_error = /* tuple */[
  "Sys_error",
  -1
];

var failure = /* tuple */[
  "Failure",
  -2
];

var invalid_argument = /* tuple */[
  "Invalid_argument",
  -3
];

var end_of_file = /* tuple */[
  "End_of_file",
  -4
];

var division_by_zero = /* tuple */[
  "Division_by_zero",
  -5
];

var not_found = /* tuple */[
  "Not_found",
  -6
];

var match_failure = /* tuple */[
  "Match_failure",
  -7
];

var stack_overflow = /* tuple */[
  "Stack_overflow",
  -8
];

var sys_blocked_io = /* tuple */[
  "Sys_blocked_io",
  -9
];

var assert_failure = /* tuple */[
  "Assert_failure",
  -10
];

var undefined_recursive_module = /* tuple */[
  "Undefined_recursive_module",
  -11
];

out_of_memory.tag = 248;

sys_error.tag = 248;

failure.tag = 248;

invalid_argument.tag = 248;

end_of_file.tag = 248;

division_by_zero.tag = 248;

not_found.tag = 248;

match_failure.tag = 248;

stack_overflow.tag = 248;

sys_blocked_io.tag = 248;

assert_failure.tag = 248;

undefined_recursive_module.tag = 248;

exports.out_of_memory = out_of_memory;
exports.sys_error = sys_error;
exports.failure = failure;
exports.invalid_argument = invalid_argument;
exports.end_of_file = end_of_file;
exports.division_by_zero = division_by_zero;
exports.not_found = not_found;
exports.match_failure = match_failure;
exports.stack_overflow = stack_overflow;
exports.sys_blocked_io = sys_blocked_io;
exports.assert_failure = assert_failure;
exports.undefined_recursive_module = undefined_recursive_module;
/*  Not a pure module */


/***/ }),
/* 1 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var Caml_array = __webpack_require__(6);

function app(_f, _args) {
  while(true) {
    var args = _args;
    var f = _f;
    var arity = f.length;
    var arity$1 = arity ? arity : 1;
    var len = args.length;
    var d = arity$1 - len | 0;
    if (d) {
      if (d < 0) {
        _args = Caml_array.caml_array_sub(args, arity$1, -d | 0);
        _f = f.apply(null, Caml_array.caml_array_sub(args, 0, arity$1));
        continue ;
        
      } else {
        return (function(f,args){
        return function (x) {
          return app(f, args.concat(/* array */[x]));
        }
        }(f,args));
      }
    } else {
      return f.apply(null, args);
    }
  };
}

function curry_1(o, a0, arity) {
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[a0]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          return o(a0);
      case 2 : 
          return (function (param) {
              return o(a0, param);
            });
      case 3 : 
          return (function (param, param$1) {
              return o(a0, param, param$1);
            });
      case 4 : 
          return (function (param, param$1, param$2) {
              return o(a0, param, param$1, param$2);
            });
      case 5 : 
          return (function (param, param$1, param$2, param$3) {
              return o(a0, param, param$1, param$2, param$3);
            });
      case 6 : 
          return (function (param, param$1, param$2, param$3, param$4) {
              return o(a0, param, param$1, param$2, param$3, param$4);
            });
      case 7 : 
          return (function (param, param$1, param$2, param$3, param$4, param$5) {
              return o(a0, param, param$1, param$2, param$3, param$4, param$5);
            });
      
    }
  }
}

function _1(o, a0) {
  var arity = o.length;
  if (arity === 1) {
    return o(a0);
  } else {
    return curry_1(o, a0, arity);
  }
}

function __1(o) {
  var arity = o.length;
  if (arity === 1) {
    return o;
  } else {
    return (function (a0) {
        return _1(o, a0);
      });
  }
}

function curry_2(o, a0, a1, arity) {
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          return app(o(a0), /* array */[a1]);
      case 2 : 
          return o(a0, a1);
      case 3 : 
          return (function (param) {
              return o(a0, a1, param);
            });
      case 4 : 
          return (function (param, param$1) {
              return o(a0, a1, param, param$1);
            });
      case 5 : 
          return (function (param, param$1, param$2) {
              return o(a0, a1, param, param$1, param$2);
            });
      case 6 : 
          return (function (param, param$1, param$2, param$3) {
              return o(a0, a1, param, param$1, param$2, param$3);
            });
      case 7 : 
          return (function (param, param$1, param$2, param$3, param$4) {
              return o(a0, a1, param, param$1, param$2, param$3, param$4);
            });
      
    }
  }
}

function _2(o, a0, a1) {
  var arity = o.length;
  if (arity === 2) {
    return o(a0, a1);
  } else {
    return curry_2(o, a0, a1, arity);
  }
}

function __2(o) {
  var arity = o.length;
  if (arity === 2) {
    return o;
  } else {
    return (function (a0, a1) {
        return _2(o, a0, a1);
      });
  }
}

function curry_3(o, a0, a1, a2, arity) {
  var exit = 0;
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1,
                a2
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          exit = 1;
          break;
      case 2 : 
          return app(o(a0, a1), /* array */[a2]);
      case 3 : 
          return o(a0, a1, a2);
      case 4 : 
          return (function (param) {
              return o(a0, a1, a2, param);
            });
      case 5 : 
          return (function (param, param$1) {
              return o(a0, a1, a2, param, param$1);
            });
      case 6 : 
          return (function (param, param$1, param$2) {
              return o(a0, a1, a2, param, param$1, param$2);
            });
      case 7 : 
          return (function (param, param$1, param$2, param$3) {
              return o(a0, a1, a2, param, param$1, param$2, param$3);
            });
      
    }
  }
  if (exit === 1) {
    return app(o(a0), /* array */[
                a1,
                a2
              ]);
  }
  
}

function _3(o, a0, a1, a2) {
  var arity = o.length;
  if (arity === 3) {
    return o(a0, a1, a2);
  } else {
    return curry_3(o, a0, a1, a2, arity);
  }
}

function __3(o) {
  var arity = o.length;
  if (arity === 3) {
    return o;
  } else {
    return (function (a0, a1, a2) {
        return _3(o, a0, a1, a2);
      });
  }
}

function curry_4(o, a0, a1, a2, a3, arity) {
  var exit = 0;
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1,
                a2,
                a3
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          exit = 1;
          break;
      case 2 : 
          return app(o(a0, a1), /* array */[
                      a2,
                      a3
                    ]);
      case 3 : 
          return app(o(a0, a1, a2), /* array */[a3]);
      case 4 : 
          return o(a0, a1, a2, a3);
      case 5 : 
          return (function (param) {
              return o(a0, a1, a2, a3, param);
            });
      case 6 : 
          return (function (param, param$1) {
              return o(a0, a1, a2, a3, param, param$1);
            });
      case 7 : 
          return (function (param, param$1, param$2) {
              return o(a0, a1, a2, a3, param, param$1, param$2);
            });
      
    }
  }
  if (exit === 1) {
    return app(o(a0), /* array */[
                a1,
                a2,
                a3
              ]);
  }
  
}

function _4(o, a0, a1, a2, a3) {
  var arity = o.length;
  if (arity === 4) {
    return o(a0, a1, a2, a3);
  } else {
    return curry_4(o, a0, a1, a2, a3, arity);
  }
}

function __4(o) {
  var arity = o.length;
  if (arity === 4) {
    return o;
  } else {
    return (function (a0, a1, a2, a3) {
        return _4(o, a0, a1, a2, a3);
      });
  }
}

function curry_5(o, a0, a1, a2, a3, a4, arity) {
  var exit = 0;
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1,
                a2,
                a3,
                a4
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          exit = 1;
          break;
      case 2 : 
          return app(o(a0, a1), /* array */[
                      a2,
                      a3,
                      a4
                    ]);
      case 3 : 
          return app(o(a0, a1, a2), /* array */[
                      a3,
                      a4
                    ]);
      case 4 : 
          return app(o(a0, a1, a2, a3), /* array */[a4]);
      case 5 : 
          return o(a0, a1, a2, a3, a4);
      case 6 : 
          return (function (param) {
              return o(a0, a1, a2, a3, a4, param);
            });
      case 7 : 
          return (function (param, param$1) {
              return o(a0, a1, a2, a3, a4, param, param$1);
            });
      
    }
  }
  if (exit === 1) {
    return app(o(a0), /* array */[
                a1,
                a2,
                a3,
                a4
              ]);
  }
  
}

function _5(o, a0, a1, a2, a3, a4) {
  var arity = o.length;
  if (arity === 5) {
    return o(a0, a1, a2, a3, a4);
  } else {
    return curry_5(o, a0, a1, a2, a3, a4, arity);
  }
}

function __5(o) {
  var arity = o.length;
  if (arity === 5) {
    return o;
  } else {
    return (function (a0, a1, a2, a3, a4) {
        return _5(o, a0, a1, a2, a3, a4);
      });
  }
}

function curry_6(o, a0, a1, a2, a3, a4, a5, arity) {
  var exit = 0;
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1,
                a2,
                a3,
                a4,
                a5
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          exit = 1;
          break;
      case 2 : 
          return app(o(a0, a1), /* array */[
                      a2,
                      a3,
                      a4,
                      a5
                    ]);
      case 3 : 
          return app(o(a0, a1, a2), /* array */[
                      a3,
                      a4,
                      a5
                    ]);
      case 4 : 
          return app(o(a0, a1, a2, a3), /* array */[
                      a4,
                      a5
                    ]);
      case 5 : 
          return app(o(a0, a1, a2, a3, a4), /* array */[a5]);
      case 6 : 
          return o(a0, a1, a2, a3, a4, a5);
      case 7 : 
          return (function (param) {
              return o(a0, a1, a2, a3, a4, a5, param);
            });
      
    }
  }
  if (exit === 1) {
    return app(o(a0), /* array */[
                a1,
                a2,
                a3,
                a4,
                a5
              ]);
  }
  
}

function _6(o, a0, a1, a2, a3, a4, a5) {
  var arity = o.length;
  if (arity === 6) {
    return o(a0, a1, a2, a3, a4, a5);
  } else {
    return curry_6(o, a0, a1, a2, a3, a4, a5, arity);
  }
}

function __6(o) {
  var arity = o.length;
  if (arity === 6) {
    return o;
  } else {
    return (function (a0, a1, a2, a3, a4, a5) {
        return _6(o, a0, a1, a2, a3, a4, a5);
      });
  }
}

function curry_7(o, a0, a1, a2, a3, a4, a5, a6, arity) {
  var exit = 0;
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1,
                a2,
                a3,
                a4,
                a5,
                a6
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          exit = 1;
          break;
      case 2 : 
          return app(o(a0, a1), /* array */[
                      a2,
                      a3,
                      a4,
                      a5,
                      a6
                    ]);
      case 3 : 
          return app(o(a0, a1, a2), /* array */[
                      a3,
                      a4,
                      a5,
                      a6
                    ]);
      case 4 : 
          return app(o(a0, a1, a2, a3), /* array */[
                      a4,
                      a5,
                      a6
                    ]);
      case 5 : 
          return app(o(a0, a1, a2, a3, a4), /* array */[
                      a5,
                      a6
                    ]);
      case 6 : 
          return app(o(a0, a1, a2, a3, a4, a5), /* array */[a6]);
      case 7 : 
          return o(a0, a1, a2, a3, a4, a5, a6);
      
    }
  }
  if (exit === 1) {
    return app(o(a0), /* array */[
                a1,
                a2,
                a3,
                a4,
                a5,
                a6
              ]);
  }
  
}

function _7(o, a0, a1, a2, a3, a4, a5, a6) {
  var arity = o.length;
  if (arity === 7) {
    return o(a0, a1, a2, a3, a4, a5, a6);
  } else {
    return curry_7(o, a0, a1, a2, a3, a4, a5, a6, arity);
  }
}

function __7(o) {
  var arity = o.length;
  if (arity === 7) {
    return o;
  } else {
    return (function (a0, a1, a2, a3, a4, a5, a6) {
        return _7(o, a0, a1, a2, a3, a4, a5, a6);
      });
  }
}

function curry_8(o, a0, a1, a2, a3, a4, a5, a6, a7, arity) {
  var exit = 0;
  if (arity > 7 || arity < 0) {
    return app(o, /* array */[
                a0,
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                a7
              ]);
  } else {
    switch (arity) {
      case 0 : 
      case 1 : 
          exit = 1;
          break;
      case 2 : 
          return app(o(a0, a1), /* array */[
                      a2,
                      a3,
                      a4,
                      a5,
                      a6,
                      a7
                    ]);
      case 3 : 
          return app(o(a0, a1, a2), /* array */[
                      a3,
                      a4,
                      a5,
                      a6,
                      a7
                    ]);
      case 4 : 
          return app(o(a0, a1, a2, a3), /* array */[
                      a4,
                      a5,
                      a6,
                      a7
                    ]);
      case 5 : 
          return app(o(a0, a1, a2, a3, a4), /* array */[
                      a5,
                      a6,
                      a7
                    ]);
      case 6 : 
          return app(o(a0, a1, a2, a3, a4, a5), /* array */[
                      a6,
                      a7
                    ]);
      case 7 : 
          return app(o(a0, a1, a2, a3, a4, a5, a6), /* array */[a7]);
      
    }
  }
  if (exit === 1) {
    return app(o(a0), /* array */[
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                a7
              ]);
  }
  
}

function _8(o, a0, a1, a2, a3, a4, a5, a6, a7) {
  var arity = o.length;
  if (arity === 8) {
    return o(a0, a1, a2, a3, a4, a5, a6, a7);
  } else {
    return curry_8(o, a0, a1, a2, a3, a4, a5, a6, a7, arity);
  }
}

function __8(o) {
  var arity = o.length;
  if (arity === 8) {
    return o;
  } else {
    return (function (a0, a1, a2, a3, a4, a5, a6, a7) {
        return _8(o, a0, a1, a2, a3, a4, a5, a6, a7);
      });
  }
}

exports.app = app;
exports.curry_1 = curry_1;
exports._1 = _1;
exports.__1 = __1;
exports.curry_2 = curry_2;
exports._2 = _2;
exports.__2 = __2;
exports.curry_3 = curry_3;
exports._3 = _3;
exports.__3 = __3;
exports.curry_4 = curry_4;
exports._4 = _4;
exports.__4 = __4;
exports.curry_5 = curry_5;
exports._5 = _5;
exports.__5 = __5;
exports.curry_6 = curry_6;
exports._6 = _6;
exports.__6 = __6;
exports.curry_7 = curry_7;
exports._7 = _7;
exports.__7 = __7;
exports.curry_8 = curry_8;
exports._8 = _8;
exports.__8 = __8;
/* No side effect */


/***/ }),
/* 2 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var Caml_builtin_exceptions = __webpack_require__(0);

function encodeCompareHow(param) {
  return param;
}

function decodeCompareResult(param) {
  var switcher = param + 1 | 0;
  if (switcher > 2 || switcher < 0) {
    return /* Unknown */3;
  } else {
    return switcher;
  }
}

function decodeCompatMode(param) {
  switch (param) {
    case "BackCompat" : 
        return /* BackCompat */0;
    case "CSS1Compat" : 
        return /* CSS1Compat */1;
    default:
      return /* Unknown */2;
  }
}

function encodeContentEditable(param) {
  switch (param) {
    case 0 : 
        return "true";
    case 1 : 
        return "false";
    case 2 : 
        return "inherit";
    case 3 : 
        return "";
    
  }
}

function decodeContentEditable(param) {
  switch (param) {
    case "false" : 
        return /* False */1;
    case "inherit" : 
        return /* Inherit */2;
    case "true" : 
        return /* True */0;
    default:
      return /* Unknown */3;
  }
}

function decodeDeltaMode(param) {
  if (param > 2 || param < 0) {
    throw [
          Caml_builtin_exceptions.invalid_argument,
          "invalid deltaMode"
        ];
  } else {
    return param;
  }
}

function encodeDesignMode(param) {
  switch (param) {
    case 0 : 
        return "on";
    case 1 : 
        return "off";
    case 2 : 
        return "";
    
  }
}

function decodeDesignMode(param) {
  switch (param) {
    case "off" : 
        return /* Off */1;
    case "on" : 
        return /* On */0;
    default:
      return /* Unknown */2;
  }
}

function encodeDir(param) {
  switch (param) {
    case 0 : 
        return "ltr";
    case 1 : 
        return "rtl";
    case 2 : 
        return "";
    
  }
}

function decodeDir(param) {
  switch (param) {
    case "ltr" : 
        return /* Ltr */0;
    case "rtl" : 
        return /* Rtl */1;
    default:
      return /* Unknown */2;
  }
}

function decodeEventPhase(param) {
  if (param > 3 || param < 0) {
    return /* Unknown */4;
  } else {
    return param;
  }
}

function encodeFilterAction(param) {
  return param + 1 | 0;
}

function encodeInsertPosition(param) {
  switch (param) {
    case 0 : 
        return "beforebegin";
    case 1 : 
        return "afterbegin";
    case 2 : 
        return "beforeend";
    case 3 : 
        return "afterend";
    
  }
}

function encodeModifierKey(param) {
  switch (param) {
    case 0 : 
        return "Alt";
    case 1 : 
        return "AltGraph";
    case 2 : 
        return "CapsLock";
    case 3 : 
        return "Control";
    case 4 : 
        return "Fn";
    case 5 : 
        return "FnLock";
    case 6 : 
        return "Hyper";
    case 7 : 
        return "Meta";
    case 8 : 
        return "NumLock";
    case 9 : 
        return "ScrollLock";
    case 10 : 
        return "Shift";
    case 11 : 
        return "Super";
    case 12 : 
        return "Symbol";
    case 13 : 
        return "SymbolLock";
    
  }
}

function decodeNodeType(param) {
  var switcher = param - 1 | 0;
  if (switcher > 11 || switcher < 0) {
    return /* Unknown */12;
  } else {
    return switcher;
  }
}

function decodePointerType(param) {
  switch (param) {
    case "mouse" : 
        return /* Mouse */0;
    case "pen" : 
        return /* Pen */1;
    case "touch|" : 
        return /* Touch */2;
    default:
      return /* Unknown */3;
  }
}

function decodeReadyState(param) {
  switch (param) {
    case "complete" : 
        return /* Complete */2;
    case "interactive" : 
        return /* Interactive */1;
    case "loading" : 
        return /* Loading */0;
    default:
      return /* Unknown */3;
  }
}

function decodeShadowRootMode(param) {
  switch (param) {
    case "closed" : 
        return /* Closed */1;
    case "open" : 
        return /* Open */0;
    default:
      throw [
            Caml_builtin_exceptions.invalid_argument,
            "Unknown shadowRootMode"
          ];
  }
}

function decodeVisibilityState(param) {
  switch (param) {
    case "hidden" : 
        return /* Hidden */1;
    case "prerender" : 
        return /* Prerender */2;
    case "unloaded" : 
        return /* Unloaded */3;
    case "visible" : 
        return /* Visible */0;
    default:
      return /* Unknown */4;
  }
}

function many(param) {
  if (param) {
    return param[0] | many(param[1]);
  } else {
    return 0;
  }
}

var WhatToShow = /* module */[
  /* _All */-1,
  /* _Element */1,
  /* _Attribute */2,
  /* _Text */4,
  /* _CDATASection */8,
  /* _EntityReference */16,
  /* _Entity */32,
  /* _ProcessingInstruction */64,
  /* _Comment */128,
  /* _Document */256,
  /* _DocumentType */512,
  /* _DocumentFragment */1024,
  /* _Notation */2048,
  /* many */many
];

exports.encodeCompareHow = encodeCompareHow;
exports.decodeCompareResult = decodeCompareResult;
exports.decodeCompatMode = decodeCompatMode;
exports.encodeContentEditable = encodeContentEditable;
exports.decodeContentEditable = decodeContentEditable;
exports.decodeDeltaMode = decodeDeltaMode;
exports.encodeDesignMode = encodeDesignMode;
exports.decodeDesignMode = decodeDesignMode;
exports.encodeDir = encodeDir;
exports.decodeDir = decodeDir;
exports.decodeEventPhase = decodeEventPhase;
exports.encodeFilterAction = encodeFilterAction;
exports.encodeInsertPosition = encodeInsertPosition;
exports.encodeModifierKey = encodeModifierKey;
exports.decodeNodeType = decodeNodeType;
exports.decodePointerType = decodePointerType;
exports.decodeReadyState = decodeReadyState;
exports.decodeShadowRootMode = decodeShadowRootMode;
exports.decodeVisibilityState = decodeVisibilityState;
exports.WhatToShow = WhatToShow;
/* No side effect */


/***/ }),
/* 3 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



function Impl() {
  return /* module */[];
}

exports.Impl = Impl;
/* No side effect */


/***/ }),
/* 4 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



function is_nil_undef(x) {
  if (x === null) {
    return /* true */1;
  } else {
    return +(x === undefined);
  }
}

function null_undefined_to_opt(x) {
  if (x === null || x === undefined) {
    return /* None */0;
  } else {
    return /* Some */[x];
  }
}

function undefined_to_opt(x) {
  if (x === undefined) {
    return /* None */0;
  } else {
    return /* Some */[x];
  }
}

function null_to_opt(x) {
  if (x === null) {
    return /* None */0;
  } else {
    return /* Some */[x];
  }
}

function option_get(x) {
  if (x) {
    return x[0];
  } else {
    return undefined;
  }
}

function option_get_unwrap(x) {
  if (x) {
    return x[0][1];
  } else {
    return undefined;
  }
}

exports.is_nil_undef = is_nil_undef;
exports.null_undefined_to_opt = null_undefined_to_opt;
exports.undefined_to_opt = undefined_to_opt;
exports.null_to_opt = null_to_opt;
exports.option_get = option_get;
exports.option_get_unwrap = option_get_unwrap;
/* No side effect */


/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE


var Curry = __webpack_require__(1);
var ElementRe = __webpack_require__(7);
var Canvas2dRe = __webpack_require__(13);
var Js_primitive = __webpack_require__(4);
var Caml_builtin_exceptions = __webpack_require__(0);

function map(f, param) {
  if (param) {
    return /* Some */[Curry._1(f, param[0])];
  } else {
    return /* None */0;
  }
}

function unsafelyUnwrapOption(param) {
  if (param) {
    return param[0];
  } else {
    throw [
          Caml_builtin_exceptions.invalid_argument,
          "Passed `None` to unsafelyUnwrapOption"
        ];
  }
}

var canvasEl = unsafelyUnwrapOption(Js_primitive.null_undefined_to_opt(document.getElementById("snake-game")));

var ctx = canvasEl.getContext("2d");

var canvasWidth = unsafelyUnwrapOption(map((function (prim) {
            return prim.offsetWidth;
          }), ElementRe.asHtmlElement(canvasEl)));

var canvasHeight = unsafelyUnwrapOption(map((function (prim) {
            return prim.offsetHeight;
          }), ElementRe.asHtmlElement(canvasEl)));

function drawScene(ctx) {
  ctx.clearRect(0, 0, canvasWidth, canvasHeight);
  Canvas2dRe.setFillStyle(ctx, /* String */0, "#1179BF");
  Canvas2dRe.setStrokeStyle(ctx, /* String */0, "white");
  ctx.fillRect(40, 0, 10, 10);
  ctx.strokeRect(40, 0, 10, 10);
  ctx.fillRect(50, 0, 10, 10);
  ctx.strokeRect(50, 0, 10, 10);
  ctx.fillRect(50, 10, 10, 10);
  ctx.strokeRect(50, 10, 10, 10);
  ctx.fillRect(50, 20, 10, 10);
  ctx.strokeRect(50, 20, 10, 10);
  ctx.fillRect(50, 30, 10, 10);
  ctx.strokeRect(50, 30, 10, 10);
  ctx.fillRect(50, 40, 10, 10);
  ctx.strokeRect(50, 40, 10, 10);
  ctx.fillRect(50, 50, 10, 10);
  ctx.strokeRect(50, 50, 10, 10);
  ctx.fillRect(60, 50, 10, 10);
  ctx.strokeRect(60, 50, 10, 10);
  return /* () */0;
}

drawScene(ctx);

exports.map = map;
exports.unsafelyUnwrapOption = unsafelyUnwrapOption;
exports.canvasEl = canvasEl;
exports.ctx = ctx;
exports.canvasWidth = canvasWidth;
exports.canvasHeight = canvasHeight;
exports.drawScene = drawScene;
/* canvasEl Not a pure module */


/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var Caml_builtin_exceptions = __webpack_require__(0);

function caml_array_sub(x, offset, len) {
  var result = new Array(len);
  var j = 0;
  var i = offset;
  while(j < len) {
    result[j] = x[i];
    j = j + 1 | 0;
    i = i + 1 | 0;
  };
  return result;
}

function len(_acc, _l) {
  while(true) {
    var l = _l;
    var acc = _acc;
    if (l) {
      _l = l[1];
      _acc = l[0].length + acc | 0;
      continue ;
      
    } else {
      return acc;
    }
  };
}

function fill(arr, _i, _l) {
  while(true) {
    var l = _l;
    var i = _i;
    if (l) {
      var x = l[0];
      var l$1 = x.length;
      var k = i;
      var j = 0;
      while(j < l$1) {
        arr[k] = x[j];
        k = k + 1 | 0;
        j = j + 1 | 0;
      };
      _l = l[1];
      _i = k;
      continue ;
      
    } else {
      return /* () */0;
    }
  };
}

function caml_array_concat(l) {
  var v = len(0, l);
  var result = new Array(v);
  fill(result, 0, l);
  return result;
}

function caml_array_set(xs, index, newval) {
  if (index < 0 || index >= xs.length) {
    throw [
          Caml_builtin_exceptions.invalid_argument,
          "index out of bounds"
        ];
  } else {
    xs[index] = newval;
    return /* () */0;
  }
}

function caml_array_get(xs, index) {
  if (index < 0 || index >= xs.length) {
    throw [
          Caml_builtin_exceptions.invalid_argument,
          "index out of bounds"
        ];
  } else {
    return xs[index];
  }
}

function caml_make_vect(len, init) {
  var b = new Array(len);
  for(var i = 0 ,i_finish = len - 1 | 0; i <= i_finish; ++i){
    b[i] = init;
  }
  return b;
}

function caml_array_blit(a1, i1, a2, i2, len) {
  if (i2 <= i1) {
    for(var j = 0 ,j_finish = len - 1 | 0; j <= j_finish; ++j){
      a2[j + i2 | 0] = a1[j + i1 | 0];
    }
    return /* () */0;
  } else {
    for(var j$1 = len - 1 | 0; j$1 >= 0; --j$1){
      a2[j$1 + i2 | 0] = a1[j$1 + i1 | 0];
    }
    return /* () */0;
  }
}

exports.caml_array_sub = caml_array_sub;
exports.caml_array_concat = caml_array_concat;
exports.caml_make_vect = caml_make_vect;
exports.caml_array_blit = caml_array_blit;
exports.caml_array_get = caml_array_get;
exports.caml_array_set = caml_array_set;
/* No side effect */


/***/ }),
/* 7 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var Curry = __webpack_require__(1);
var NodeRe = __webpack_require__(8);
var DomTypesRe = __webpack_require__(2);
var SlotableRe = __webpack_require__(9);
var ChildNodeRe = __webpack_require__(10);
var Js_primitive = __webpack_require__(4);
var ParentNodeRe = __webpack_require__(11);
var EventTargetRe = __webpack_require__(3);
var NonDocumentTypeChildNodeRe = __webpack_require__(12);

function ofNode(node) {
  var match = +(NodeRe.nodeType(node) === /* Element */0);
  if (match !== 0) {
    return /* Some */[node];
  } else {
    return /* None */0;
  }
}

function Impl() {
  var asHtmlElement = (
    function (element) {
      // BEWARE: Assumes "contentEditable" uniquely identifies an HTMLELement
      return element.contentEditable !== undefined ?  element : null;
    }
  );
  var asHtmlElement$1 = function (self) {
    return Js_primitive.null_to_opt(Curry._1(asHtmlElement, self));
  };
  var insertAdjacentElement = function (position, element, self) {
    self.insertAdjacentElement(DomTypesRe.encodeInsertPosition(position), element);
    return /* () */0;
  };
  var insertAdjacentHTML = function (position, text, self) {
    self.insertAdjacentHTML(DomTypesRe.encodeInsertPosition(position), text);
    return /* () */0;
  };
  var insertAdjacentText = function (position, text, self) {
    self.insertAdjacentText(DomTypesRe.encodeInsertPosition(position), text);
    return /* () */0;
  };
  return /* module */[
          /* asHtmlElement */asHtmlElement$1,
          /* ofNode */ofNode,
          /* insertAdjacentElement */insertAdjacentElement,
          /* insertAdjacentHTML */insertAdjacentHTML,
          /* insertAdjacentText */insertAdjacentText
        ];
}

var include = NodeRe.Impl(/* module */[]);

EventTargetRe.Impl(/* module */[]);

ParentNodeRe.Impl(/* module */[]);

NonDocumentTypeChildNodeRe.Impl(/* module */[]);

ChildNodeRe.Impl(/* module */[]);

SlotableRe.Impl(/* module */[]);

var asHtmlElement = (
    function (element) {
      // BEWARE: Assumes "contentEditable" uniquely identifies an HTMLELement
      return element.contentEditable !== undefined ?  element : null;
    }
  );

function asHtmlElement$1(self) {
  return Js_primitive.null_to_opt(Curry._1(asHtmlElement, self));
}

function insertAdjacentElement(position, element, self) {
  self.insertAdjacentElement(DomTypesRe.encodeInsertPosition(position), element);
  return /* () */0;
}

function insertAdjacentHTML(position, text, self) {
  self.insertAdjacentHTML(DomTypesRe.encodeInsertPosition(position), text);
  return /* () */0;
}

function insertAdjacentText(position, text, self) {
  self.insertAdjacentText(DomTypesRe.encodeInsertPosition(position), text);
  return /* () */0;
}

var nodeType = include[0];

exports.Impl = Impl;
exports.nodeType = nodeType;
exports.asHtmlElement = asHtmlElement$1;
exports.ofNode = ofNode;
exports.insertAdjacentElement = insertAdjacentElement;
exports.insertAdjacentHTML = insertAdjacentHTML;
exports.insertAdjacentText = insertAdjacentText;
/* include Not a pure module */


/***/ }),
/* 8 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var DomTypesRe = __webpack_require__(2);
var EventTargetRe = __webpack_require__(3);

function Impl() {
  var nodeType = function (self) {
    return DomTypesRe.decodeNodeType(self.nodeType);
  };
  return /* module */[/* nodeType */nodeType];
}

EventTargetRe.Impl(/* module */[]);

function nodeType(self) {
  return DomTypesRe.decodeNodeType(self.nodeType);
}

exports.Impl = Impl;
exports.nodeType = nodeType;
/*  Not a pure module */


/***/ }),
/* 9 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



function Impl() {
  return /* module */[];
}

exports.Impl = Impl;
/* No side effect */


/***/ }),
/* 10 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



function Impl() {
  return /* module */[];
}

exports.Impl = Impl;
/* No side effect */


/***/ }),
/* 11 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



function Impl() {
  return /* module */[];
}

exports.Impl = Impl;
/* No side effect */


/***/ }),
/* 12 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";



function Impl() {
  return /* module */[];
}

exports.Impl = Impl;
/* No side effect */


/***/ }),
/* 13 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


var Curry = __webpack_require__(1);
var Caml_builtin_exceptions = __webpack_require__(0);

var Composite = /* module */[
  /* sourceOver */"source-over",
  /* sourceIn */"source-in",
  /* sourceOut */"source-out",
  /* sourceAtop */"source-atop",
  /* destinationOver */"destination-over",
  /* destinationIn */"destination-in",
  /* destinationOut */"destination-out",
  /* destinationAtop */"destination-atop",
  /* lighter */"lighter",
  /* copy */"copy",
  /* xor */"xor"
];

var LineCap = /* module */[
  /* butt */"butt",
  /* round */"round",
  /* square */"square"
];

var LineJoin = /* module */[
  /* round */"round",
  /* bevel */"bevel",
  /* miter */"miter"
];

function setStrokeStyle(ctx, _, v) {
  ctx.strokeStyle = v;
  return /* () */0;
}

function setFillStyle(ctx, _, v) {
  ctx.fillStyle = v;
  return /* () */0;
}

function reifyStyle(x) {
  var instanceOf = (function(x,y) {return +(x instanceof y)});
  var tmp;
  if (typeof x === "string") {
    tmp = /* String */0;
  } else if (Curry._2(instanceOf, x, CanvasGradient)) {
    tmp = /* Gradient */1;
  } else if (Curry._2(instanceOf, x, CanvasPattern)) {
    tmp = /* Pattern */2;
  } else {
    throw [
          Caml_builtin_exceptions.invalid_argument,
          "Unknown canvas style kind. Known values are: String, CanvasGradient, CanvasPattern"
        ];
  }
  return /* tuple */[
          tmp,
          x
        ];
}

function fillStyle(ctx) {
  return reifyStyle(ctx.fillStyle);
}

function strokeStyle(ctx) {
  return reifyStyle(ctx.strokeStyle);
}

exports.Composite = Composite;
exports.LineCap = LineCap;
exports.LineJoin = LineJoin;
exports.setStrokeStyle = setStrokeStyle;
exports.setFillStyle = setFillStyle;
exports.reifyStyle = reifyStyle;
exports.fillStyle = fillStyle;
exports.strokeStyle = strokeStyle;
/* No side effect */


/***/ })
/******/ ]);