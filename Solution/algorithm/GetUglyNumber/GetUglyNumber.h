/*
��ֻ��������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ����������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����
˳��ĵ�N��������
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