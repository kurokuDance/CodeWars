#include <iostream>
#include <vector>
#include <string>

std::string factorial(int n) {
    std::vector<int> result = { 1 }; 

    for (int i = 2; i <= n; i++) 
    {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) 
        {
            int prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) 
        {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    std::string fact_str;
    for (auto it = result.rbegin(); it != result.rend(); ++it)
        fact_str += std::to_string(*it);

    return fact_str;
}

int main() {
    int n = 20000;
    std::cout << "100! = " << factorial(n) << std::endl;
    return 0;
}
