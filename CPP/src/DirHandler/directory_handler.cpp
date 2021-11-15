#include "directory_handler.h"
#include <iostream>
#include <optional>
// #include <bitset>
namespace fs = std::filesystem;

#ifdef DEBUG
DirectoryHandler::DirectoryHandler(const std::string& path)
	: m_directoryPath(path)
{}
#endif

void DirectoryHandler::getObjects()
{
	for (auto entry : fs::directory_iterator(this->m_directoryPath))
	{
		if (entry.is_directory())
		{
			this->m_directories.emplace_back(std::move(entry));
		}
		else
		{
			if (file_has_extention(entry.path)
				std::cout << getExtention(entry.path().string().erase(0, this->m_directoryPath.string().length() + 1)).value() << std::endl;

				this->m_files.emplace_back(std::move(entry));
		}

	}
}

bool DirectoryHandler::file_has_extention(const fs::directory_entry& file)
{
	auto extention = getExtention(file.path().string().erase(0, ).value();

	if (!extention.empty())
		return true;

	return false;
}

std::optional<std::string> DirectoryHandler::getExtention(const std::string& fileName)
{
	auto extentionDelimeter = delimeterCheck(fileName);
	if (extentionDelimeter)
		return fileName.substr(extentionDelimeter.value() + 1);

	return "";

}


std::optional<std::size_t> DirectoryHandler::delimeterCheck(const std::string& fileName)
{
	auto extentionDelimeter = fileName.find_last_of('.');
	if (extentionDelimeter != std::string::npos)
		return extentionDelimeter;

	return {};
}



void DirectoryHandler::activate()
{

}
