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
rm -rf buildcmake
mkdir buildcmake && cd buildcmake
cmake -DCMAKE_INSTALL_PREFIX:PATH=C:/Users/IEUser/Desktop/wxWidgets -DwxBUILD_MONOLITHIC:BOOL=ON -DwxBUILD_SHARED:BOOL=ON ..
cmake --build . --target=INSTALL --config=release
