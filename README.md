# cpprun
cpprun is a command line tool for quickly compiling and running C++ programs. It provides various options for customizing the compilation and execution process, such as specifying the compiler to use, adding compiler options, redirecting output to a file, and more.

## Requirements
cpprun requires a C++ compiler (such as g++) and the GNU Compiler Collection (GCC) to be installed on your system. It has been tested on Linux and macOS, and may also work on other Unix-like operating systems.

## Installation
To install cpprun, simply download the cpprun executable and add it to your PATH. You can also build the cpprun executable from source by running the following commands:

```bash
git clone https://github.com/username/cpprun.git
cd cpprun
make
```

## Usage
```lua
Copy code
Usage: cpprun [OPTIONS] source_file
Compile and run C++ program quickly.
Options:
  -h, --help                    Display this help message
  -o, --output=<executable_name> Specify the name of the final executable (default: source_file name without suffix)
  -r, --run                     Run the program after compiling
  -c, --clean                   Clean the screen before executing the program
  -d, --delete                  Delete the executable after executing the program
  -C, --compiler=<compiler>     Specify the compiler to use (default: g++)
  -O, --compiler-options=<options> Specify additional compiler options
  -D, --debug                   Generate debug information to help debug the compiled program
  -M, --check-memory            Check memory leaks and dereference errors in the compiled code
  -f, --output-file=<file>      Redirect the output of the compiled program to a file instead of the console
```

To compile and run a C++ program, simply run `cpprun source_file.cpp`. By default, the program will be compiled using the g++ compiler and the output file will be named after the source file. You can use the various options to customize the compilation and execution process. For example, to compile with the clang++ compiler and generate debug information, you can run `cpprun -C clang++ -D source_file.cpp`. To redirect the output of the program to a file instead of the console, you can run `cpprun -f output.txt source_file.cpp`.

## License
cpprun is released under the MIT License.
