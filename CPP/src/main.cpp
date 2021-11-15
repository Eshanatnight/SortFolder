#include <iostream>
#include "directory_handler.h"
#define SORTFOLDER "SortFolder.exe"

int main(int argc, char* argv[])
{
	/*
		if (argc < 2)
		{
			std::cout << "Usage: SORTFOLDER <path>\n";
			return EXIT_FAILURE;
		}
	*/

	DirectoryHandler object("C:/Dev/SortFolder");
	object.getObjects();
	// std::cout << "This is a Test" << std::endl;



	return EXIT_SUCCESS;
}