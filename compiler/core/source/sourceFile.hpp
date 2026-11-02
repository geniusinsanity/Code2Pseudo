#ifndef SOURCE_FILE_HPP
#define SOURCE_FILE_HPP

#include <string>

struct SourceFile {
    std::string path;
    std::string content;
};

bool readSourceFile(SourceFile &source);

#endif

