#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include <map>  // ! To BE removed


#define DEBUG


class DirectoryHandler
{
private:
	std::filesystem::path m_directoryPath;
	std::vector<std::filesystem::directory_entry> m_files;
	std::vector<std::filesystem::directory_entry> m_directories;


public:
	/*
		Constructor will take in a path given through argv[1]
	*/
	DirectoryHandler(const std::string& path);

	/*
		TODO: Change Name To something Meaningful
		TODO: Probably Move to Private Section Before Release Build
	*/
	void getObjects();


	// One function to activate the Program
	void activate();


private:
	bool file_has_extention(const std::string& fileName);
	std::optional<std::string> getExtention(const std::string& fileName);
	std::optional<std::size_t> delimeterCheck(const std::string& fileName);




};


