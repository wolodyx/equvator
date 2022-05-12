
cd ~
if [[ ! -d opencv ]]
then
    git clone https://github.com/opencv/opencv.git
fi
cd opencv
git checkout 4.5.5
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/home/skt ..
cmake --build .
checkinstall --install=no --pkgname=OpenCV --pkgversion=4.5.5 --default
# dpkg -i opencv_4.5.5-1_amd64.deb
