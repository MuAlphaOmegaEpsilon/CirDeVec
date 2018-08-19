cd ..
echo "Initializing submodules"
git submodule init
echo "Downloading the Google Benchmark submodule"
git submodule update
echo "Downloading the Google Test submodule"
git clone https://github.com/google/googletest.git include/benchmark/googletest
cd include/benchmark
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=RELEASE
make