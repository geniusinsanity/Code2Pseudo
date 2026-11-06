#include <catch2/catch_test_macros.hpp>

#include <filesystem>
#include <fstream>
#include <string>

#include "core/source/sourceFile.hpp"


TEST_CASE("readSourceFile reads file content")
{
    // Arrange: create a temporary file
    const auto path =
        std::filesystem::temp_directory_path() / "code2pseudo_test.cpp";

    std::ofstream output(path);

    REQUIRE(output.is_open());

    output << "int age = 22;";
    output.close();


    // Act: read the file
    SourceFile source;
    source.path = path.string();

    bool result = readSourceFile(source);


    // Assert: check the result
    CHECK(result == true);
    CHECK(source.content == "int age = 22;\n");


    // Cleanup: delete the temporary file
    std::filesystem::remove(path);
}