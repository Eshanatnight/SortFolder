#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class DirectoryHandler
{
    private:
        fs::path m_directoryPath;
        std::vector<std::string> m_files;
        std::vector<std::string> m_directories;
};
