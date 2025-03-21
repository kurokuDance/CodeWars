#include <string>
#include <cctype>

std::string incrementString(const std::string& str)
{
    int i = str.size() - 1;
    while (i >= 0 && std::isdigit(str[i])) --i;
    std::string non_digits = str.substr(0, i + 1), digits = str.substr(i + 1);
    if (digits.empty()) return non_digits + "1";

    int number = std::stoi(digits) + 1;
    std::string new_digits = std::to_string(number);
    if (new_digits.size() < digits.size()) {
        new_digits.insert(0, digits.size() - new_digits.size(), '0');
    }

    return non_digits + new_digits;
}
