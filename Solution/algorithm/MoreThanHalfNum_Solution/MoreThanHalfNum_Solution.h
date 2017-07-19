#include<vector>
#include<map>
using namespace std;
namespace MoreThanHalfNum_Solution {
	class Solution {
	public:
		int MoreThanHalfNum_Solution(vector<int> numbers) {
			map<int, int> table;
			int max_count = 0;
			int n = numbers.size();
			for (int i = 0; i < numbers.size(); i++) {
				int v = numbers[i];
				map<int, int>::iterator it = table.find(v);
				if (it != table.end())
					table[v]++;
				else
					table[v] = 1;
				if (table[v] > max_count)
					max_count = table[v];
				if (table[v] > n / 2)
					return v;
				else if (max_count + n - i - 1 <= n / 2)
					return 0;
			}
			return 0;
		}
	};
}