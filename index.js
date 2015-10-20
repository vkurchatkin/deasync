var binding = require('bindings')('deasync');

function deasync (_fn) {
  return function () {
    var self = { err: null, res: null, done: false },
        fn = Function.prototype.bind.bind(_fn, this).apply(arguments);

    fn(callback.bind(self))
    while (!done) binding.run();
    if (err) throw err;

    return res;
  }
}

function callback (err, res) {
  this.err = err;
  this.res = res;
  this.done = true;
}

module.exports = deasync;
