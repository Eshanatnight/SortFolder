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

}


void DirectoryHandler::checkFiles()
{
	for (auto file : m_files)
	{
		std::string extension = getExtension(file);
		if (!extension.empty())
		{
			std::cout << "Extension: " << extension << "	File: " << file.path().string() << std::endl;
		}
	}
}


// One Function to just activate the Functionality
// TOBE Written
void DirectoryHandler::activate()
{

}
