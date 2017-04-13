using namespace std;
namespace NumberOf1 {
	class Solution {
	public:
		int  NumberOf1(int n) {
			int mask = 0x00000001;
			int count = 0;
			while (mask != 0) {
				if ((n & mask) != 0)count++;
				mask = mask << 1;
			}
			return count;
		}
	};
}