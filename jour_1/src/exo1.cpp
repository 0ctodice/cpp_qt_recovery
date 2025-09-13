#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage:\n"
                  << argv[0] << " <folder>" << std::endl;
        return 1;
    }

    std::string folder_path = argv[1];
    std::vector<fs::directory_entry> files;

    for (const auto &entry : fs::directory_iterator(folder_path))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry);
        }
    }

    std::sort(files.begin(), files.end(),
              [](fs::directory_entry &file1, fs::directory_entry &file2)
              { return fs::file_size(file1) > fs::file_size(file2); });

    std::for_each(files.begin(), files.end(), [](const fs::directory_entry &file)
                  { std::cout << file.path().filename().string() << " | " << file.path().extension() << " | " << fs::file_size(file) << std::endl; });
    return 0;
}