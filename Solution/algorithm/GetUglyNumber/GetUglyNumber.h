/*
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的
顺序的第N个丑数。
*/
#include<vector>
#include<set>
using namespace std;
namespace GetUglyNumber{
	class Solution {
	public:
		int GetUglyNumber_Solution(int index) {
			vector<int> ugly;
			ugly.push_back(1);
			vector<int> plus_idx(3, 0);
			int n = 1;
			while (ugly.size() < index) {
				int n[3];
				n[0] = ugly[plus_idx[0]] * 2;
				n[1] = ugly[plus_idx[1]] * 3;
				n[2] = ugly[plus_idx[2]] * 5;
				int idx = min_num_idx(n);
				int next_ugly = n[idx];
				for (int i = 0; i < 3; i++) {
					if (n[i] == next_ugly)
						plus_idx[i]++;
				}
				ugly.push_back(next_ugly);
			}
			return ugly[index - 1];
		}
	private:
		int min_num_idx(int n[]) {
			int v_max = n[0];
			int i_max = 0;
			for (int i = 1; i < 3; i++) {
				if (n[i] < v_max) {
					i_max = i;
					v_max = n[i];
				}
			}
			return i_max;
		}
	};
}