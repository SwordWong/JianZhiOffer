#include <vector>
using namespace std;
namespace RectCover {
	class Solution {
	public:
		Solution() {
			res.resize(3);
			res[0] = 0;
			res[1] = 1;
			res[2] = 2;
		}
		int rectCover(int number) {
			if (number >= res.size())
			{
				int m = res.size();
				res.resize(number + 1);
				for (int i = m; i <= number; i++) {
					res[i] = res[i - 1] + res[i - 2];
				}
			}
			return res[number];
		}
		vector<int> res;
	};
}