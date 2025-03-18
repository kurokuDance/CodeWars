#include <vector>
using namespace std;

vector<int> move_zeroes(vector<int> input)
{
    int size_input = input.size();
    for (int i = 0; i < size_input; i++)
    {
        if (input[i] == 0 && input[i + 1] == 0)
        {
            for (int j = i; j < size_input - 1; j++)
                swap(input[j], input[j + 1]);
            size_input--;
            i--;
        }
        else
            if (input[i] == 0)
            {
                for (int j = i; j < size_input - 1; j++)
                    swap(input[j], input[j + 1]);
                size_input--;
            }
    }
    return input;
}