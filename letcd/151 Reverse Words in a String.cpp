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
	void reverseWords(string &s) {
		int start_idx = 0;
		int end_idx = s.length() - 1;
		while (s[start_idx]==' ')
		{
			++start_idx;
		}
		while (s[end_idx] == ' ')
		{
			--end_idx;
		}
		string str(s, start_idx, end_idx - start_idx + 1);
		s = str;
		start_idx = 0;
		end_idx =0;
		str.clear();
		string temp="";
		while (end_idx<s.length() && s[end_idx] != ' ')
		{
			while (end_idx<s.length() && s[end_idx] != ' ')
			{
				++end_idx;
			}
			if (end_idx==s.length())
			{
				string str(s, start_idx, end_idx - start_idx);
				temp += str;
			}
			else
			{
				string str(s, start_idx, end_idx - start_idx);
				temp += str;
				temp += ' ';
			}
			while (end_idx < s.length() && s[end_idx] == ' ')
			{
				++end_idx;
			}
			start_idx = end_idx;
		}
		s = temp;
	    start_idx = 0;
		end_idx = s.length() - 1;
		while (start_idx<end_idx)
		{
			char ctemp = s[start_idx];
			s[start_idx] = s[end_idx];
			s[end_idx] = ctemp;
			++start_idx;
			--end_idx;
		}
		start_idx = 0;
		end_idx =0;
		while ( end_idx<s.length() && s[end_idx] != ' ' )
		{
			while (end_idx<s.length() && s[end_idx] != ' ' )
			{
				++end_idx;
			}
			int end_id = end_idx-1;
			while (start_idx < end_id)
			{
				char ctemp = s[start_idx];
				s[start_idx] = s[end_id];
				s[end_id] = ctemp;
				++start_idx;
				--end_id;
			}
			while (end_idx < s.length() && s[end_idx] == ' ')
			{
				++end_idx;
			}
			start_idx = end_idx;
		}
	}	
};

int main()
{
	Solution sol;
	string str=" 1 33   4   ";
	//cin >> str;
	sol.reverseWords(str);
	cout << str;
	return 0;
}