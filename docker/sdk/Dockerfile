FROM ubuntu:20.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt update
RUN apt-get --assume-yes install \
    vim git wget cmake python-dev \
    checkinstall build-essential\
    libicu-dev libfreetype6-dev libharfbuzz-dev libxml2-dev libcairo2-dev \
    libsqlite3-dev sqlite libcurl4-openssl-dev postgresql-12 \
    postgresql-server-dev-12 qt5-default libgtk-3-dev

ADD buildfiles/ /

RUN /build-boost.sh
RUN /build-proj.sh
RUN /build-gdal.sh
RUN /build-mapnik.sh
RUN /build-opencv.sh
RUN /build-wxwidgets.sh
