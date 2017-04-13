#include <vector>
using namespace std;

namespace JumpFloorII {
	class Solution {
	public:
		Solution() {
			res.resize(3);
			res[0] = 0;
			res[1] = 1;
			res[2] = 2;
		}
		int jumpFloorII(int number) {
			if (number >= res.size())
			{
				int m = res.size();
				res.resize(number + 1);
				for (int i = m; i <= number; i++) {
					res[i] = 2*res[i - 1];
				}
			}
			return res[number];
		}
		vector<int> res;
	};
}