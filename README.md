# MyZip
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

``` git clone https://github.com/yourusername/myzip.git```

Go to the project directory:
``` 
cd myzip 
```

and download the googletest library:
``` 
git clone https://github.com/google/googletest.git
```




Build the project:

```
mkdir build && cd build && cmake .. 
```

then use:

```
make
```

### Usage
After building the project, you can use the myzip binary to compress or decompress files.

To compress a file, run:


```
./myzip compress input.txt
```

This will create a compressed file named input.txt.myzip.

To decompress a file, run:

```
./myzip decompress input.txt.myzip
```

This will decompress the contents of input.txt.myzip into a file named input.txt.

### Testing
To run the unit tests, run:

```
cd build && make test
```

or for more details:

```
cd build && make test ARGS=-V
```

## License
This project is licensed under the MIT License. See the LICENSE file for details.





