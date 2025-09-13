#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>

class FileInfo
{
private:
    std::string _name;
    std::uintmax_t _size;
    std::string _extension;

public:
    FileInfo(std::string name, std::uintmax_t size, std::string extension);
    ~FileInfo();
    void print() const;
    std::string name() const;
    std::uintmax_t size() const;
    std::string extension() const;
};

FileInfo::FileInfo(std::string name, std::uintmax_t size, std::string extension) : _name{name}, _size{size}, _extension{extension}
{
}

FileInfo::~FileInfo()
{
}

std::string FileInfo::name() const { return _name; }
std::uintmax_t FileInfo::size() const { return _size; }
std::string FileInfo::extension() const { return _extension; }

void FileInfo::print() const
{
    std::cout << _name << "." << _extension << " | " << _size << " bytes" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, FileInfo fileInfo)
{
    stream << fileInfo.name() << "." << fileInfo.extension() << " | " << fileInfo.size() << " bytes" << std::endl;
    return stream;
}

int main(int argc, char *argv[])
{
    std::vector<FileInfo> files = {{"yolo", 10, "png"}, {"yala", 10000, "jpeg"}, {"your_mom", 1000000000, "pdf"}};
    std::sort(files.begin(), files.end(), [](const FileInfo &a, const FileInfo &b)
              { return a.extension() < b.extension(); });

    for (auto file : files)
    {
        std::cout << file << std::endl;
    }
    return 0;
}