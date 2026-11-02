
#include "sourceFile.hpp"
#include <fstream>

bool readSourceFile(SourceFile &source) {

    //create an object from the file path using input file stream lib
    std::ifstream file(source.path);

    //cheking if the file can be open or not
    if (!file.is_open()) {
        return false;
    }
    //creating a string variable to store one line at a time
    std::string line;

    //Initialize the content as an empty string
    source.content = "";

    //added each line to the content
    while (std::getline(file, line)) {
        source.content += line + "\n";
    }

    //Return true to indicate that the file was read successfully
    return true;
}
