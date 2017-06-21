/*
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ��
��,������Ҫ��������������������,������ȫΪ������
ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ��
����ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},
����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��᲻�ᱻ������ס��(�������ĳ���������1)
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