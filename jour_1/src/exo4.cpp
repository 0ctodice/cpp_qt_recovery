#include <iostream>
#include <vector>
#include <memory>

struct FileInfo
{
    std::string name;
    FileInfo(std::string n) : name(std::move(n)) {}
};

std::unique_ptr<FileInfo> make_fileinfo(const std::string &path) { return std::make_unique<FileInfo>(path); }

int main(int argc, char *argv[])
{
    std::vector<std::unique_ptr<FileInfo>> files;
    files.emplace_back(make_fileinfo("/etc/yolo"));
    files.emplace_back(make_fileinfo("/etc/yala"));
    files.emplace_back(make_fileinfo("/etc/yulu"));

    for (const auto &file : files)
    {
        std::cout << file->name << std::endl;
    }

    return 0;
}