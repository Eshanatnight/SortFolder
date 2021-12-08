#pragma once
#include <filesystem>
#include <string>
#include <vector>

class DirectoryHandler
{
private:
	std::filesystem::path m_directoryPath;
	std::filesystem::path m_movePath;
	std::vector<std::filesystem::directory_entry> m_files;
	std::vector<std::filesystem::directory_entry> m_directories;
    const std::vector<std::string> m_list = { "c", "cxx", "cpp", "h", "hxx", "hpp" };

public:
	/*
		Constructor will take in a path given through argv[1] and movePath given through argv[2]
	*/
	DirectoryHandler(const std::string& path, const std::string& movePath);

	/*
		TODO: Probably Move to Private Section Before Release Build
	*/
	void getContents();
	void checkFiles();

	// One function to activate the Program
	void activate();


private:

	void moveFile(const std::filesystem::directory_entry& file);
	std::string getExtension(const std::filesystem::path& filePath);
	bool extensionInList(const std::string& extension);






};


