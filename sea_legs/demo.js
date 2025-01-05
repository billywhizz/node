const { isSea, getRawAssetMemFd } = require('node:sea');

function load_binding_from_asset(path) {
    if (isSea()) {
      const fd = getRawAssetMemFd(path);
      const mod = { exports: {} };
      process.dlopen(mod, `/proc/self/fd/${fd}`)
      return mod.exports
    }
    return require(path)
  }

const { getpid } = load_binding_from_asset('./build/Release/demo.node')

console.log(getpid())
