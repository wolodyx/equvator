FROM ubuntu:20.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt update
RUN apt-get --assume-yes install vim
RUN apt-get --assume-yes install git
RUN apt-get --assume-yes install wget
RUN apt-get --assume-yes install cmake 
RUN apt-get --assume-yes install python
RUN apt-get --assume-yes install checkinstall
RUN apt-get --assume-yes install build-essential
RUN apt-get --assume-yes install libicu-dev
RUN apt-get --assume-yes install libfreetype6-dev
RUN apt-get --assume-yes install libharfbuzz-dev
RUN apt-get --assume-yes install libxml2-dev
RUN apt-get --assume-yes install libcairo2-dev
RUN apt-get --assume-yes install libsqlite3-dev sqlite
RUN apt-get --assume-yes install libcurl4-openssl-dev
RUN apt-get --assume-yes install postgresql-12 postgresql-server-dev-12
RUN apt-get --assume-yes install qt5-default
RUN apt-get --assume-yes install libgtk-3-dev

ADD build-boost.sh /
ADD build-proj.sh /
ADD build-gdal.sh /
ADD build-mapnik.sh /
ADD build-opencv.sh /
ADD build-wxwidgets.sh /

RUN /build-boost.sh
RUN /build-proj.sh
RUN /build-gdal.sh
RUN /build-mapnik.sh
RUN /build-opencv.sh
RUN /build-wxwidgets.sh
