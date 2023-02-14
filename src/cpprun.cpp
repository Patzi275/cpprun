#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <unistd.h>

void print_usage()
{
    std::cout << "Usage: cpprun [OPTIONS] source_file" << std::endl;
    std::cout << "Compile and run C++ program quickly." << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help\t\t\tDisplay this help message" << std::endl;
    std::cout << "  -o, --output=<executable_name>\tSpecify the name of the final executable (default: source_file name without suffix)" << std::endl;
    std::cout << "  -r, --run\t\t\tRun the program after compiling" << std::endl;
    std::cout << "  -c, --clean\t\t\tClean the screen before executing the program" << std::endl;
    std::cout << "  -d, --delete\t\t\tDelete the executable after executing the program" << std::endl;
    std::cout << "  -C, --compiler=<compiler>\tSpecify the compiler to use (default: g++)" << std::endl;
    std::cout << "  -O, --compiler-options=<options>\tSpecify additional compiler options" << std::endl;
    std::cout << "  -D, --debug\t\t\tGenerate debug information to help debug the compiled program" << std::endl;
    std::cout << "  -M, --check-memory\t\tCheck memory leaks and dereference errors in the compiled code" << std::endl;
    std::cout << "  -f, --output-file=<file>\tRedirect the output of the compiled program to a file instead of the console" << std::endl;
}

int main(int argc, char *argv[])
{
    std::map<std::string, std::string> args;
    args["compiler"] = "g++";
    args["compiler_options"] = "";
    args["output_file"] = "";
    std::string source_file;
    bool clean = false;
    bool delete_executable = false;
    bool run = false;

    int opt;
    while ((opt = getopt(argc, argv, "ho:rcC:O:DMf:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_usage();
            return 0;
        case 'o':
            args["output"] = optarg;
            break;
        case 'r':
            run = true;
            break;
        case 'c':
            clean = true;
            break;
        case 'C':
            args["compiler"] = optarg;
            break;
        case 'O':
            args["compiler_options"] = optarg;
            break;
        case 'D':
            args["compiler_options"] += " -g";
            break;
        case 'M':
            args["compiler_options"] += " -fsanitize=address -fsanitize=undefined";
            break;
        case 'f':
            args["output_file"] = optarg;
            break;
        case 'd':
            delete_executable = true;
            break;
        default:
            print_usage();
            return 1;
        }
    }
    if (optind >= argc)
    {
        std::cerr << "ERROR: No source file provided." << std::endl;
        print_usage();
        return 1;
    }

    source_file = argv[optind];
    if (args["output"].empty())
    {
        std::size_t pos = source_file.rfind('.');
        if (pos != std::string::npos)
        {
            args["output"] = source_file.substr(0, pos);
        }
        else
        {
            args["output"] = source_file;
        }
    }

    std::string compile_command = args["compiler"] + " " + source_file + " -o " + args["output"] + " " + args["compiler_options"];
    int ret = system(compile_command.c_str());
    if (ret != 0)
    {
        std::cerr << "ERROR: Compilation failed with exit code " << ret << std::endl;
        return ret;
    }

    if (run)
    {
        if (clean)
        {
            system("clear");
        }

        if (!args["output_file"].empty())
        {
            std::string run_command = args["output"] + " > " + args["output_file"];
            ret = system(run_command.c_str());
        }
        else
        {
            std::string run_command = "./" + args["output"];
            ret = system(run_command.c_str());
        }

        if (delete_executable)
        {
            std::string delete_command = "rm " + args["output"];
            system(delete_command.c_str());
        }

        return ret;
    }

    return 0;
}