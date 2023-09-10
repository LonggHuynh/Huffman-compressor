# Compressor
MyZip is a simple command-line data compression and decompression tool that utilizes a custom compression algorithm based on Huffman coding. This tool is designed to compress text files into a smaller binary representation, making them easier to store and transfer.

## Features
- Compress and decompress files using a custom Huffman-based compression algorithm
- Use canonical code instead of original one to make the header size fixed and much smaller (at least 4 times)
- Support for .myzip file extension to indicate compressed files


## Getting Started
### Prerequisites
- C++ compiler that supports C++11 or later
- CMake 3.10 or later
- GNU Make 4.1 or later

### Building
Clone this repository to your local machine:

``` 
git clone https://github.com/LonggHuynh/Huffman-compressor.git
```

Go to the project directory:
``` 
cd Huffman-compressor 
```





Build the project:

```
rm -rf build && \
mkdir build && \
cd build && \
cmake -DBUILD_TESTS=OFF .. && \
make && \
cd ..
```


### Usage
After building the project, you can use the myzip binary to compress or decompress files.

To compress a file, run:


```
./build/Compressor compress /input_path/input_file /output_path
```

This will create a compressed file named input_file.cpred.

To decompress a file, run:

```
./build/Compressor decompress /input_path/input_file.cpred /output_path
```

This will decompress the contents of input_file.cpred into a file named input_file stored in /output_path.

### Testing
To run the unit tests, run:
```
rm -rf build && \
mkdir build && \
cd build && \
cmake .. -DBUILD_TESTS=ON && \
make && \
make test
```


or for more details:

```
make test ARGS=-V
```
### Running with Docker
Build image :
```
docker build -t image-name .
```


Run a container with volume:

```
docker run -v ./your_input_folder:/data compressor compress /data/input.txt /data
```

For example:
```
docker run -v ./data:/data compressor compress /data/input.txt /data
```




