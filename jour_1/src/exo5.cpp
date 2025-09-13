#include <iostream>
#include <vector>
#include <memory>
#include <optional>
#include <algorithm>

struct FileInfo
{
    std::string name;
    std::string ext;
};

std::optional<FileInfo> find_by_ext(const std::vector<FileInfo> &files, const std::string &ext)
{
    auto it = std::find_if(files.begin(), files.end(), [&ext](const FileInfo &file)
                           { return file.ext == ext; });

    if (it != files.end())
    {
        return *it;
    }
    else
    {
        return std::nullopt;
    }
}

int main(int argc, char *argv[])
{
    std::vector<FileInfo> files;
    files.emplace_back("yolo", "png");
    files.emplace_back("yala", "jpeg");
    files.emplace_back("yulu", "mp3");

    auto res = find_by_ext(files, "mp3");

    if (res)
        std::cout << res->name << std::endl;

    return 0;
}