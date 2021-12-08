#include <iostream>
#include "DirHandler/directory_handler.h"

#define SORTFOLDER "SortFolder.exe"

int main(int argc, char* argv[])
{

    if (argc < 2)
    {
        std::cout << "Usage: " << SORTFOLDER << " <MoveFromPath> <MoveToPath>\n";
        return EXIT_FAILURE;
    }

    else if (argc == 3)
    {
		std::cout << "Move From Path:" << argv[1] << "\t Move To Path:" << argv[2] << "\n";
    }

	try
	{
		DirectoryHandler object(argv[1], argv[2]);
		object.getContents();
		object.checkFiles();
	}catch (std::filesystem::filesystem_error e)
	{
		std::cerr << e.what() << std::endl;
	}


	return EXIT_SUCCESS;
}