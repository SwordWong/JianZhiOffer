#include <vector>
using namespace std;

namespace FibonacciArray {
	class Solution {
	public:
		Solution() {
			res.resize(2);
			res[0] = res[1] = 1;
		}
		int Fibonacci(int n) {
			if (n > res.size()) {
				int m = res.size();
				res.resize(n, -1);
				for (int i = m; i < n; i++) {
					res[i] = res[i - 1] + res[i - 2];
				}
			}
			return res[n - 1];
		}
		vector<int> res;
	};
}