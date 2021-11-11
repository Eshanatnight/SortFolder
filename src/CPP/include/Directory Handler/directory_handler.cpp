#include "directory_handler.h"
#include <iostream>
namespace fs = std::filesystem;

#ifdef DEBUG
DirectoryHandler::DirectoryHandler(const std::string& path)
	: m_directoryPath(path)
{}
#endif

#ifdef RELEASE
DirectoryHandler::DirectoryHandler()
{}
#endif

void DirectoryHandler::getObjects()
{
	for (auto entry : fs::directory_iterator(this->m_directoryPath))
	{
		if (entry.is_directory())
			this->m_directories.emplace_back(std::move(entry));
		else
			this->m_files.emplace_back(std::move(entry));
	}
	

}
