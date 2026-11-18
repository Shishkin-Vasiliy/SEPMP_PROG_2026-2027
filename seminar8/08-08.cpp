#include <iostream>
#include <string>
#include <cctype>

void countLetters(
    const std::string& str,
    int& numLetters,
    int& numDigits
)
{
    numLetters = 0;
    numDigits = 0;

    for (char c : str)
    {
        if (std::isalpha(static_cast<unsigned char>(c)))
            numLetters++;

        if (std::isdigit(static_cast<unsigned char>(c)))
            numDigits++;
    }
}

int main()
{
    std::string str = "Hello123 World45!";

    int letters;
    int digits;

    countLetters(str, letters, digits);

    std::cout << "Letters: " << letters << std::endl;
    std::cout << "Digits: " << digits << std::endl;

    return 0;
}
