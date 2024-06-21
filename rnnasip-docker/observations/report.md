# RNNASIP Report

## Observations

- pulp-sdk must be cloned NOT inside vp folder (as a sibling to vp)
- pmsis must be corrected to have https://

- pulp-sdk requirements must be met:
    `yum install git python36-pip python36-devel gawk texinfo gmp-devel mpfr-devel libmpc-devel swig libjpeg-turbo-devel redhat-lsb-core doxygen python-sphinx sox GraphicsMagick-devel ImageMagick-devel SDL2-devel perl-Switch libftdi-devel cmake cmake3 scons`

- install python2 pip (`yum install python2-pip`)
- instead of `python2 -m pip install configparser` use `python2 -m pip install --trusted-host pypi.python.org configparser2` (?)
- edit scons to use python3 instead (?) `/usr/bin/scons`
- install python3's scons package (?) `python3 -m pip install scons`
- install python3's Sphinx package (?) `python3 -m pip install Sphinx`

- install Magick++ `yum install ImageMagick ImageMagick-c++-devel GraphicsMagick-c++-devel`

- clone whatever we want to run to the workspace directory and run as usual

## Errors

### config_tree referenced before assignment
```
config_tree referenced before assignment in pulp-sdk/pulp-configs/python/pulp_config.py, get_configs last else
```
![image](./images/config_tree_before_assignment.png)

