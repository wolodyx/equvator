# sudo apt-get install libgtk-3-dev
# sudo apt-get install libcurl4-openssl-dev
# --sudo apt-get install libwebkit2gtk-4.0-dev--
# sudo apt-get install libgl1-mesa-devlibglu1-mesa-dev
# sudo apt-get install libgstreamer-plugins-base1.0-dev

cd ~
if [[ ! -d wxWidgets ]]
then
	git clone https://github.com/wxWidgets/wxWidgets .
fi
cd wxWidgets
git checkout v3.1.6-final
git submodule update --init 3rdparty/pcre
git submodule update --init 3rdparty/catch
git submodule update --init 3rdparty/nanosvg
git submodule update --init src/png
git submodule update --init src/jpeg
git submodule update --init src/tiff
git submodule update --init src/expat
git submodule update --init src/zlib
rm -rf buildgtk
mkdir buildgtk && cd buildgtk
../configure --with-gtk --prefix=$HOME
make
checkinstall --install=no --pkgname=wxWidgets --pkgversion=3.1.6 --default
# dpkg -i wxwidgets_3.1.6-1_amd64.deb
