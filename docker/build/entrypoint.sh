#!/bin/bash
set -e

if [ ! -f CMakeLists.txt ]; then
  echo "sudo docker run -e DISPLAY=$DISPLAY --net=host --volume /tmp/.X11-unix:/tmp/.X11-unix --volume ~/MyProjects/equvator:/equvator --rm -it equvator-build"
  exit 1;
fi

./build.sh
build/bin/app

exec "$@"
