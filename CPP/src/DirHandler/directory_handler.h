#pragma once
#include <filesystem>
#include <string>
#include <vector>


class DirectoryHandler
{
private:
	std::filesystem::path m_directoryPath;
	std::vector<std::filesystem::directory_entry> m_files;
	std::vector<std::filesystem::directory_entry> m_directories;
	std::size_t m_pathLength = 0;


public:
	/*
		Constructor will take in a path given through argv[1]
	*/
	DirectoryHandler(const std::string& path);

	/*
		TODO: Probably Move to Private Section Before Release Build
	*/
	void getContents();
	void checkFiles();

	// One function to activate the Program
	void activate();


private:

	void moveFile(const std::filesystem::directory_entry& file, const std::filesystem::path& newPath);
	std::string getExtension(const std::filesystem::path& filePath);;






};


