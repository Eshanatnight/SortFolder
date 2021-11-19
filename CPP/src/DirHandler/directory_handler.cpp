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


// Logic for movig a file
void DirectoryHandler::moveFile(const fs::directory_entry& file, const fs::path& newPath)
{

	if (fs::copy_file(file.path(), newPath))
	{
		fs::remove(file.path());
	}

	else
	{
		std::cerr << "Move Failed\n";
		return;
	}
}


void DirectoryHandler::checkFiles()
{
	// Have to define some kind of var newPath
	// or use an rval move?
	for (const auto& file : m_files)
	{
		std::string extension = getExtension(file.path());
		if (!extension.empty())
		{
			moveFile(file, newPath);
		}
	}
}


// One Function to just activate the Functionality
// TOBE Written
void DirectoryHandler::activate()
{

}
