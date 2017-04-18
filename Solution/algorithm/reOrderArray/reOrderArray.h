#include<vector>
using namespace std;
namespace reOrderArray {
	class Solution {
	public:
		void reOrderArray(vector<int> &array) {
			int idx_last_left = -1;
			for (int i = 0; i < array.size(); i++) {
				if (array[i] % 2 == 1) {
					insert(array, i, ++idx_last_left);
				}
			}
			return;
		}
	private:
		void insert(vector<int> & array, int idx_ori, int idx_ins) {
			int val = array[idx_ori];
			for (int i = idx_ori; i > idx_ins; i--) {
				array[i] = array[i - 1];
			}
			array[idx_ins] = val;
		}
	};
}