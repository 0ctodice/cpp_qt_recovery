#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage:\n"
                  << argv[0] << " <text path>" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    std::ifstream file(path);
    if (!file)
        return 1;

    std::string line;
    int global_line_count = 0;
    std::string word = "banana";
    int word_line_count = 0;
    while (getline(file, line))
    {
        global_line_count++;

        std::string lower = line;

        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        if (lower.find(word) != std::string::npos)
            word_line_count++;
    }

    std::cout << "total line : " << global_line_count << std::endl;
    std::cout << "total line with the word " << word << " : " << word_line_count << std::endl;

    return 0;
}