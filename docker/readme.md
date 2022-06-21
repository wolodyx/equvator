``` bash
docker build -t equvator-sdk sdk/
docker build -t equvator-build build/
docker run -it --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix --net=host --device=/dev/video0:/dev/video0 -v $HOME/MyProjects/equvator:/equvator equvator-build /bin/bash
```

[Docker: запуск графических приложений в контейнерах](https://habr.com/ru/post/240509/)
