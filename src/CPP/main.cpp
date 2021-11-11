#include <iostream>
#include <filesystem>
#include "Directory Handler/directory_handler.h"
#define SORTFOLDER "SortFolder.exe"

int main(int argc, char** argv)
{
    DirectoryHandler object("C:/dev/SortFolder");
    object.getObjects();

    if (argc < 2)
    {
        std::cout << "Usage: " << SORTFOLDER << " <path>" << std::endl;
        return EXIT_FAILURE;
    }

    std::filesystem::path path(argv[1]);

    std::cout << "Hello World!" << std::endl;
    return EXIT_SUCCESS;
}