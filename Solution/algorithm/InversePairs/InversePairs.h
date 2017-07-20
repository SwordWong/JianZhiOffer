/*
在数组中的两个数字，如果前面一个数字
大于后面的数字，则这两个数字组成一个
逆序对。输入一个数组,求出这个数组中的
逆序对的总数P。并将P对1000000007取模
的结果输出。 即输出P%1000000007
*/
#include <vector>
using namespace std;
namespace InversePairs{
    class Solution {
    public:
        int InversePairs(vector<int> data) {
			int res = InversePairsAndMergeSort(data, 0, data.size() - 1);
			return res;
        }
		static const int MOD = 1000000007;
	private:
		int InversePairsAndMergeSort(vector<int> &data, int head, int tail) {
			if (head >= tail)
				return 0;
			int mid = (head + tail) / 2;
			int count = 0;
			count += InversePairsAndMergeSort(data, head, mid);
			count %= MOD;
			count += InversePairsAndMergeSort(data, mid + 1, tail);
			count %= MOD;
			int i = mid;
			int j = tail;
			vector<int> tmpv(tail - head + 1);
			int idx = tmpv.size() - 1;
			while (i >= head && j > mid) {
				if (data[i] > data[j]) {
					count += (j - mid) %MOD;
					count %= MOD;
					tmpv[idx--] = data[i--];
				}
				else {
					tmpv[idx--] = data[j--];
				}
			}
			while (i >= head) {
				tmpv[idx--] = data[i--];
			}
			while (j > mid) {
				tmpv[idx--] = data[j--];
			}
			idx = 0;
			for (i = head; i <= tail; i++) {
				data[i] = tmpv[idx++];
			}
			return count;
		}
    };
}