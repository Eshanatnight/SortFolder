#pragma once
#include <filesystem>
#include <string>
#include <vector>


#define DEBUG


class DirectoryHandler
{
    private:
        std::filesystem::path m_directoryPath;
        std::vector<std::filesystem::directory_entry> m_files;
        std::vector<std::filesystem::directory_entry> m_directories;

    public:

        #ifdef RELEASE
            DirectoryHandler(); // Constructor To be Defined
        #endif
        

        #ifdef DEBUG
            DirectoryHandler(const std::string& path);
        #endif

        void getObjects();
        

};
