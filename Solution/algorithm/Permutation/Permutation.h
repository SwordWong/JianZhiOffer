#include<vector>
#include <string>
using namespace std;
namespace Permutation {
	class Solution {
	public:

		vector<string> Permutation(string str) {
			vector<string> res;
			vector<int> table(52, 0);
			for (int i = 0; i < str.length(); i++)
				table[str[i] - 'A']++;
			Permutation(table, "", str.length(), res);
			return res;
		}
		void Permutation(vector<int> table, string str, int length_remain, vector<string> &res) {
			if (length_remain == 0 && !str.empty())
				res.push_back(str);
			for (int i = 0; i < table.size(); i++) {
				if (table[i] > 0) {
					table[i]--;
					string s = str;
					string c = "a";
					c[0] = 'A' + i;
					s.append(c);
					Permutation(table, s, length_remain - 1, res);
					table[i]++;
				}
			}
		}
	};
}