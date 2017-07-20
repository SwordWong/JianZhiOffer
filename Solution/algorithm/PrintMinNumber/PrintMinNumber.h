/*
输入一个正整数数组，把数组里所有数字拼
接起来排成一个数，打印能拼接出的所有数
字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
*/
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

namespace PrintMinNumber{
	class Solution {
	public:
		string PrintMinNumber(vector<int> numbers) {
			sort(numbers.begin(), numbers.end(), Solution::cmp);
			string res;
			for (int i = 0; i < numbers.size(); i++) {
				string s;
				int2string(numbers[i], s);
				res.append(s);
			}
			return res;
		}

	private:
		static void int2string(int num, string& s) {
			s.clear();
			stringstream ss;
			ss << num;
			ss >> s;
		}
		static bool cmp(int a, int b) {
			string sa, sb, sab, sba;
			int2string(a, sa);
			int2string(b, sb);
			sab = sa;
			sab.append(sb);
			sba = sb;
			sba.append(sa);
			if (sab.compare(sba) > 0)
				return false;
			else
				return true;
		}
	};
}