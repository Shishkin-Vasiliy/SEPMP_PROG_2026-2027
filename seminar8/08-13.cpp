#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& str)
{
    std::vector<std::string> result;
    std::string current;

    for (char c : str)
    {
        current += c;
        result.push_back(current);
    }

    return result;
}

int main()
{
    std::vector<std::string> v = prefixes("Mouse");

    print(v);

    return 0;
}
