#include <vector>
using namespace std;
namespace Power {
	class Solution {
	public:
		double Power(double base, int exponent) {
			
			vector<double> p;
			p.resize(sizeof(int)*8);
			p[0] = 1;
			p[1] = base;
			bool neg = exponent < 0.0f;
			exponent = abs(exponent);
			int mask = 1;
			int i = 1;
			double res = 1.0f;
			while (mask != 0 && mask/2 < exponent) {
				if (i > 1)
					p[i] = p[i - 1] * p[i - 1];
				if ((mask & exponent) != 0)
					res *= p[i];
				i++;
				mask = mask << 1;
			}
			if (neg)
				res = 1.0f / res;
			return res;
		}
	};
}