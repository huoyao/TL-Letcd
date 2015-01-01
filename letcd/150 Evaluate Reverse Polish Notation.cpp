/************************************************************************/
/* 2014-7-5 10:19:56 2014-7-5 12:24:23  125min                          */
/* Evaluate Reverse Polish Notation                                     */
/* pay attention to minus sign                                          */
/*                  only one number                                     */
/************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> op_num;
		queue<char> op_;
		int result_value = 0;
		for (auto const value : tokens)
		{
			stringstream ss;
			if ((value[0] >= 48 && value[0] <= 57) || value.size() >= 2)
			{
				if (value[0] == '-')
				{
					string mid_str(value, 1);
					ss << mid_str;
					int mid_result = 0;
					ss >> mid_result;
					mid_result = -mid_result;
					op_num.push(mid_result);
				}
				else{
					ss << value;
					int mid_result = 0;
					ss >> mid_result;
					op_num.push(mid_result);
				}
			}
			else{
				ss << value;
				char c;
				ss >> c;
				int value_l, value_r;
				if (op_num.empty())
					return 0;
				value_r = op_num.top();
				op_num.pop();
				if (op_num.empty())
					return value_r;
				value_l = op_num.top();
				op_num.pop();
				switch (c)
				{
				case '+':
					result_value = value_l + value_r;
					op_num.push(result_value);
					break;
				case '-':
					result_value = value_l - value_r;
					op_num.push(result_value);
					break;
				case '*':
					result_value = value_l * value_r;
					op_num.push(result_value);
					break;
				case '/':
					result_value = value_l / value_r;
					op_num.push(result_value);
					break;
				default:
					break;
				}
			}
		}
		return op_num.top();
	}
};

int main()
{
	Solution sol;
	vector<string> str = { "18" };
	//cin >> str;
	int result_int= sol.evalRPN(str);
    //int result_int = tese(str);
	/*string st = "/123";
	stringstream ss;
	ss << st;
	int mid_result=0;
	ss >> mid_result;
	if (st[0]>=48 && st[0]<=57)
	{
	cout << mid_result;
	}*/
	/*if (!ss.good())
	{
	cout << mid_result;
	}*/
	cout << result_int;
	return 0;
}