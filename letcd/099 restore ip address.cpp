/************************************************************************/
/* 2014-6-16 21:35:36 1h20m                                             */
/* too long , should use some short functions                           */
/************************************************************************/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<int> ivec;
		vector<string> svec;
		string mid_result;
		int s_len = s.length();
		for (int i = 0; i != s_len; ++i)
		{
			ivec.push_back(s[i]-48);
		}
		for (int i = 1; i <= 3 && i <= s_len; ++i)
		{
			mid_result.clear();
			if (3!= i)
			{
				if (i==2 && ivec[0]==0)
				{
					continue;
				}
				string s_temp(s, 0, i);
				mid_result = s_temp;
			}
			else{
				if ((ivec[0]*100+ivec[1]*10+ivec[2]) <= 255 && ivec[0] > 0)
				{
					string s_temp(s, 0, i);
					mid_result = s_temp;
				}
				else{
					break;
				}
			}
			mid_result += '.';
			string s_i_remain = mid_result;
			for (int j = 1; j <= 3 && j <= s_len - i; ++j)
			{
				mid_result = s_i_remain;
				if (3 != j)
				{
					if (j == 2 && ivec[i] == 0)
					{
						continue;
					}
					string s_temp(s, i, j);
					mid_result += s_temp;
				}
				else{
					if ((ivec[i]*100+ ivec[i + 1]*10+ ivec[i + 2]) <= 255 && ivec[i] >0)
					{
						string s_temp(s, i, j);
						mid_result += s_temp;
					}
					else{
						break;
					}
				}
				mid_result += '.';
				string s_j_remain = mid_result;
				for (int t = 1; t <= 3 && t <= s_len - i-j; ++t)
				{
					mid_result = s_j_remain;
					if (3 != t)
					{
						if (t == 2 && ivec[i+j] == 0)
						{
							continue;
						}
						string s_temp(s, i+j, t);
						mid_result += s_temp;
					}
					else{
						if ((ivec[i + j] * 100 + ivec[i + 1 + j] * 10 + ivec[i + 2 + j]) <= 255 && ivec[i + j] >0)
						{
							string s_temp(s, i+j, t);
							mid_result += s_temp;
						}
						else{
							break;
						}
					}
					mid_result += '.';
					int k = s_len - i - j-t;
					if (k <= 3 && k > 0)
					{
						if (3 != k)
						{
							if (k == 2 && ivec[i+j+t] == 0)
							{
								continue;
							}
							string s_temp(s, i + j + t, k);
							mid_result += s_temp;
							svec.push_back(mid_result);
						}
						else{
							if ((ivec[i + j + t] * 100 + ivec[i + 1 + j + t] * 10 + ivec[i + 2 + j + t]) <= 255 && ivec[i + j + t] >0)
							{
								string s_temp(s, i + j+t, k);
								mid_result += s_temp;
								svec.push_back(mid_result);
							}
						}
					}
				}
				
			}
		}
		return svec;
	}
};

int main()
{
	Solution sol;
	string str;
	vector<string> svec;
	cin >> str;
	svec = sol.restoreIpAddresses(str);
	for (const string &s : svec)
	{
		cout << s << endl;
	}
	return 0;
}