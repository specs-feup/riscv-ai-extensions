# X-heep with CV32E40p Core Dockerfile Observations

## Necessary Changes

- Change python venv dependencies to newer versions, included in Dockerfile
- Use pulp gnu toolchain (?)


## Errors

### Verilator

The required verilator version is v4.210, however it does not compile due to an error as described [here](https://github.com/verilator/verilator/issues/5162). It is necessary to add a `#include <memory>` in `Verilator/src/V3Const.cpp`.