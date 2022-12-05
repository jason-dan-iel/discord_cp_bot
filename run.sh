cmake -B ./build
cmake --build ./build -j8
cd build
sudo make install
cd ..
clang++ -std=c++17 -o bot ./src/source.cpp -ldpp
./bot