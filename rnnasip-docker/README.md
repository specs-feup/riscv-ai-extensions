# RNNASIP Dockerfile

To build the image, execute the build script: `./build.sh`


To get a container inside the image, run `./run.sh`. If this command has been run before, you may need to remove the previous image. use `docker rm <hash>` on the hash provided by the error code when running the script, and if that doesn't work `docker rmi <hash>` on the image hash provided by the new error message.


A full list of observations, including errors and necessary adjustments to be able to run the tests can be found [here](./observations/README.md).