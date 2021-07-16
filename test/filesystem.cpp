/* Standard Library */
#include <iostream>

/* Test Include Header Library */
#include <filesystem>

/* Testing with namespace */
namespace fs = std::filesystem;

/* Main for handle call main function */
int main(int argc, const char* argv[]) {
    /* Testing variable */
    fs::path testVariable { "." };

    /* I don't using parameter */
    {
    	(void)argc;
    	(void)argv;
    }
    return 0;
}