#include <iostream>
#include "utility.h"
#include "directory_handler.h"
#define SORTFOLDER "SortFolder.exe"

int main(int argc, char* argv[])
{
    DirectoryHandler object("C:/dev/SortFolder");
    object.getObjects();

    if (argc < 2)
    {
        println("Hello");
        return EXIT_FAILURE;
    }

    std::filesystem::path path(argv[1]);

    std::cout << "Hello World!" << std::endl;
    return EXIT_SUCCESS;
}