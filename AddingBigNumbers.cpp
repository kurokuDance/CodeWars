#include <string>
#include <iostream>

std::string add(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? a[i--] - '0' : 0;
        int digit2 = (j >= 0) ? b[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::cout << add("101", "99");
}