/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别
中,常常需要计算连续子向量的最大和,当向量全为正数的
时候,问题很好解决。但是,如果向量中包含负数,是否应该
包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)
*/
#include <vector>
#include <limits>
using namespace std;

namespace FindGreatestSumOfSubArray{
    class Solution {
    public:
        int FindGreatestSumOfSubArray(vector<int> array) {
			int idx_max = 0;
			int val_max = numeric_limits<int>::min();
			int n = array.size();
			vector<int> sum_end_with(n);
			sum_end_with[0] = array[0];
			for (int i = 1; i < n; i++) {
				if (sum_end_with[i - 1] > 0) {
					sum_end_with[i] = sum_end_with[i - 1] + array[i];
				}
				else {
					sum_end_with[i] = array[i];
				}
				if (sum_end_with[i] > val_max) {
					val_max = sum_end_with[i];
					idx_max = i;
				}
			}
			return val_max;
        }
    };
}