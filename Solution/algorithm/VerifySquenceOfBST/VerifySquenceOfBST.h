#include <vector>
using namespace std;
namespace VerifySquenceOfBST {
	class Solution {
	public:
		bool VerifySquenceOfBST(vector<int> sequence) {
			return IsBST(sequence, 0, sequence.size() - 1);
		}
		bool IsBST(vector<int> seq, int i_s, int i_e) {
			if (i_s > i_e)
				return true;
			else if (i_s == i_e)
				return true;
			int RootVal = seq[i_e];
			int idx = i_e - 1;
			while (idx >= 0) {
				if (seq[idx] < RootVal)
					break;
				else
					idx--;
			}
			int i_right_s = idx + 1;
			int i_right_e = i_e - 1;
			int i_left_s = 0;
			int i_left_e = idx;
			while (idx >= 0) {
				if (seq[idx--] > RootVal)
					return false;
			}
			bool res_right = IsBST(seq, i_right_s, i_right_e);
			bool res_left = IsBST(seq, i_left_s, i_left_e);
			return res_right && res_left;
		}
	};
}