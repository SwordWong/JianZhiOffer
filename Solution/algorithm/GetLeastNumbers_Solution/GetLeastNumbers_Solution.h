#include<vector>
#include<list>

using namespace std;
namespace GetLeastNumbers_Solution {
	class Solution {
	public:
		vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
			if (k > input.size())
				return vector<int>(0);
			list<int> mink;
			for (int i = 0; i < input.size(); i++) {
				if (mink.empty())
					mink.push_back(input[i]);
				else {
					list<int>::iterator it;
					for (it = mink.begin(); it != mink.end(); it++) {
						if (input[i] > *it)
							break;
					}
					mink.insert(it, input[i]);
					while (mink.size() > k)mink.erase(mink.begin());
				}
			}
			vector<int> res(k);
			list<int>::iterator it;
			int i = k - 1;
			for (it = mink.begin(); it != mink.end(); it++)
				res[i--] = *it;
			return res;
		}
	};
}