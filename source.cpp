#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

std::string getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return std::string(*itr);
    }
    else if(itr != end)
    {
        return "";
    }
    return "";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    std::string delimiter = getCmdOption(argv, argv + argc, "--delimiter");

    if (delimiter == "\\n") {
        delimiter = "\n";
    } else if (delimiter == "\\t") {
        delimiter = "\t";
    }

    std::string input(std::istreambuf_iterator<char>(std::cin), {});

    if (!input.empty()) {
        for (char c : input) {
            std::cout << std::bitset<8>(c).to_string() << delimiter;
        }
    } else {
        std::cout << "No input was given." << std::endl;
    }

    return 0;
}

/*
To compile this program, you can use the g++ compiler. Here's the command:
g++ -o program source.cpp

This will compile the source.cpp file and create an executable named 'program'.

If you don't have the g++ compiler installed, you can install it on Debian with the following command:
sudo apt-get install build-essential

The 'build-essential' package includes the g++ compiler along with other tools necessary for building software.
*/