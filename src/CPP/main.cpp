#include <iostream>

#include <filesystem>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <path>" << std::endl;
        return EXIT_FAILURE;
    }

    std::filesystem::path path(argv[1]);

    std::cout << "Hello World!" << std::endl;
    return EXIT_SUCCESS;
}