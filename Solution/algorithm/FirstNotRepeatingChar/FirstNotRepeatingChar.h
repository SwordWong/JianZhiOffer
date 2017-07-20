/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)
中找到第一个只出现一次的字符,并返回它的位置
*/
#include<vector>
using namespace std;
namespace FirstNotRepeatingChar {
	class Solution {
	public:
		int FirstNotRepeatingChar(string str) {
			if (str.empty())
				return -1;
			vector<int> count(256, 0);
			vector<int> pos(256, -1);
			for (int i = 0; i < str.length(); i++) {
				int idx = str[i];
				if (count[idx] == 0) {
					pos[idx] = i;
				}
				count[idx]++;
			}
			int min_pos = 256;
			for (int i = 0; i < count.size(); i++) {
				if (count[i] == 1 && pos[i] < min_pos) {
					min_pos = pos[i];
				}
			}
			return min_pos;
		}
	};

}