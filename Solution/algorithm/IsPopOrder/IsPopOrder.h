#include <stack>
#include <vector>
using namespace std;
namespace IsPopOrder{
	class Solution {
	public:
		bool IsPopOrder(vector<int> pushV, vector<int> popV) {
			stack<int> s;
			int idx_push = 0;
			int idx_pop = 0;
			while (idx_pop < popV.size()) {
				if (idx_push < pushV.size()) {
					s.push(pushV[idx_push++]);
					if (s.top() == popV[idx_pop]) {
						s.pop();
						idx_pop++;
					}	
				}
				else {
					if (s.top() == popV[idx_pop]) {
						s.pop();
						idx_pop++;
					}			
					else
						return false;
				}
			}
			return true;
		}
	};
}