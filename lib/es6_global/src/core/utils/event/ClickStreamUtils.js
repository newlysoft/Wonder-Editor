

import * as Most from "most";

function bindClickStream(isSingleClick, debounceTime, clickStream) {
  var count = [0];
  return Most.tap((function () {
                count[0] = 0;
                return /* () */0;
              }), Most.filter((function () {
                    if (isSingleClick) {
                      return count[0] === 1;
                    } else {
                      return count[0] >= 2;
                    }
                  }), Most.tap((function () {
                        if (isSingleClick) {
                          if (count[0] !== 1) {
                            count[0] = 0;
                            return /* () */0;
                          } else {
                            return 0;
                          }
                        } else if (count[0] < 2) {
                          count[0] = 0;
                          return /* () */0;
                        } else {
                          return 0;
                        }
                      }), Most.debounce(debounceTime, Most.tap((function () {
                                count[0] = count[0] + 1 | 0;
                                return /* () */0;
                              }), clickStream)))));
}

export {
  bindClickStream ,
  
}
/* most Not a pure module */