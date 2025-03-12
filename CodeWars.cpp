#include <iostream>
#include <memory.h>
using namespace std;

class Mix
{
public:
	static string mix(const string& s1, const string& s2);
};

string Mix::mix(const string& s1, const string& s2)
{
	cout << "s1: " << s1 << endl << endl << endl << endl;
	cout << "s2: " << s2 << endl;
	int alph1[26]; memset(alph1, 0, sizeof(int) * 26);
	int alph2[26]; memset(alph2, 0, sizeof(int) * 26);
	int max_length;
	string answer_str = string();
	for (int i = 0; i < s1.size(); i++)
		if ((int(s1[i]) >= 97) && (int(s1[i]) <= 122))
			alph1[int(s1[i]) - 97]++;
	for (int i = 0; i < s2.size(); i++)
		if ((int(s2[i]) >= 97) && (int(s2[i]) <= 122))
			alph2[int(s2[i]) - 97]++;
	if (s1.size() > s2.size())
		max_length = s1.size();
	else max_length = s2.size();
	while (max_length > 1)
	{
		for (int i = 0; i < 26; i++)
		{
			if ((alph1[i] == max_length) && (alph1[i] > alph2[i]))
			{
				answer_str += "1:";
				for (int num = 0; num < alph1[i]; num++)
					answer_str += char(i + 97);
				answer_str += "/";
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if ((alph2[i] == max_length) && (alph2[i] > alph1[i]))
			{
				answer_str += "2:";
				for (int num = 0; num < alph2[i]; num++)
					answer_str += char(i + 97);
				answer_str += "/";
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if ((alph1[i] == max_length) && (alph2[i] == max_length))
			{
				answer_str += "=:";
				for (int num = 0; num < alph1[i]; num++)
					answer_str += char(i + 97);
				answer_str += "/";
			}

		}
		max_length--;
	}
	if (!answer_str.empty())
		answer_str.pop_back();
	return answer_str;
}