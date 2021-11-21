#include "directory_handler.h"
#include <iostream>

namespace fs = std::filesystem;


DirectoryHandler::DirectoryHandler(const std::string& path)
	: m_directoryPath(path), m_pathLength(path.length())
{}


// Logic that iterates through the directory and logs the contents of the directory
void DirectoryHandler::getContents()
{
	for (auto entry : fs::directory_iterator(this->m_directoryPath))
	{
		// If the entry is a directory then log the entry to m_directories
		if (entry.is_directory())
		{
			this->m_directories.emplace_back(std::move(entry));
		}
		// Else the entry is logged into m_files
		else
		{
			this->m_files.emplace_back(std::move(entry));
		}
	}
}

<<<<<<< HEAD
=======
<<<<<<< HEAD

>>>>>>> 58429a7aa7a8c831517ae00f57da5ed8f3de2bac
// Logic to Check if a file has an extension or not
std::string DirectoryHandler::getExtension(const fs::path& filePath)
{
	// We will temporarily store a string file name for each file
	std::string fileName = filePath.string().erase(0, this->m_directoryPath.string().length() + 1);

	// We get the Position of the '.' character from the end
	// As long that Position is not npos or the starting index
	// Then we return the extension substring
	auto extentionDelimeterPos = fileName.find_last_of('.');
	// the second condition just checks if the file is not an extention-less hidden file
	if (extentionDelimeterPos == std::string::npos || extentionDelimeterPos == 0)
	{
		return {};
	}

	return fileName.substr(++extentionDelimeterPos);
}


<<<<<<< HEAD
// Logic for moving a file
void DirectoryHandler::moveFile(const fs::directory_entry& file, const fs::path& newPath)
{
#ifdef TEST
=======
// Logic for movig a file
void DirectoryHandler::moveFile(const fs::directory_entry& file, const fs::path& newPath)
{

>>>>>>> 58429a7aa7a8c831517ae00f57da5ed8f3de2bac
	if (fs::copy_file(file.path(), newPath))
	{
		fs::remove(file.path());
	}
<<<<<<< HEAD
#endif
=======
=======

// Logic to Check if a file has an extension or not
std::string DirectoryHandler::getExtension(const fs::directory_entry& file)
{
	// We will temporarily store a string file name for each file
	std::string fileName = file.path().string().erase(0, this->m_directoryPath.string().length() + 1);

	// We get the Position of the '.' character from the end
	// As long that Position is not npos or the starting index
	// Then we return the extension substring
	auto extentionDelimeterPos = 0;
	extentionDelimeterPos = fileName.find_last_of('.');
	std::cout << extentionDelimeterPos << std::endl;

	if (extentionDelimeterPos == std::string::npos)
	{
		return {};
	}

	else if (extentionDelimeterPos == 0)
	{
		return {};
	}

	std::cout << "FileName: ";
	std::cout << fileName << "\t";
	extentionDelimeterPos++;
	return file.path().string().substr(extentionDelimeterPos);
>>>>>>> c041a647a8ae060082d1c6d4bb0ff514af95bc99

	else
	{
		std::cerr << "Move Failed\n";
		return;
	}
>>>>>>> 58429a7aa7a8c831517ae00f57da5ed8f3de2bac
}


void DirectoryHandler::checkFiles()
{
<<<<<<< HEAD
	// Have to define some kind of var newPath
	// or use an rval move?
	for (const auto& file : m_files)
	{
		std::string extension = getExtension(file.path());
		if (!extension.empty())
		{
			moveFile(file, newPath);
=======
	for (auto file : m_files)
	{
		std::string extension = getExtension(file);
		if (!extension.empty())
		{
			std::cout << "Extension: " << extension << "	File: " << file.path().string() << std::endl;
>>>>>>> c041a647a8ae060082d1c6d4bb0ff514af95bc99
		}
	}
}


<<<<<<< HEAD
void DirectoryHandler::checkFiles()
{
	// Have to define some kind of var newPath
	// or use an rval move?
	for (const auto& file : m_files)
	{
		std::string extension = getExtension(file.path());
		if (!extension.empty())
		{
			std::cout << "File: " << file.path().string() << "\t" << "Extension" << extension << "\n";
			// moveFile(file, newPath);
		}
	}
}


=======
>>>>>>> 58429a7aa7a8c831517ae00f57da5ed8f3de2bac
// One Function to just activate the Functionality
// TOBE Written
void DirectoryHandler::activate()
{

}
