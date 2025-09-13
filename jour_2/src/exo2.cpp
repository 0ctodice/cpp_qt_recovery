#include <iostream>
#include <QString>

QString toQString(const std::string &s)
{
    return QString::fromStdString(s);
}

std::string toStdString(const QString &s)
{
    return s.toStdString();
}

int main(int argc, char *argv[])
{
    std::string s = "Hello QT Pie!";
    std::cout << s << std::endl;
    std::cout << toStdString(toQString(s)) << std::endl;
    return 0;
}
