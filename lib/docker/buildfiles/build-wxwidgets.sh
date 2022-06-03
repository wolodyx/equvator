#!/bin/bash
set -e
if [[ ! -d wxWidgets ]]
then
    git clone https://github.com/wxWidgets/wxWidgets
fi
cd wxWidgets
git checkout v3.1.6-final
git submodule update --init
rm -rf buildgtk
mkdir buildgtk && cd buildgtk
../configure --with-gtk
make
make install
#checkinstall --install=no --pkgname=wxWidgets --pkgversion=3.1.6 --default
