/*
求出1~13的整数中1出现的次数,
并算出100~1300的整数中1出现
的次数？为此他特别数了一下1~13中
包含1的数字有1、10、11、12、13
因此共出现6次,但是对于后面问题
他就没辙了。ACMer希望你们帮帮他,
并把问题更加普遍化,可以很快的求
出任意非负整数区间中1出现的次数。
*/
#include <vector>
#include <cmath>
using namespace std;
namespace NumberOf1Between1AndN {
    class Solution {
    public:
        int NumberOf1Between1AndN_Solution(int n)
        {
            Nv.resize(n + 1, -1);
			Nv[0] = 0;
			for (int i = 1; i <= 9 && i < n; i++)
				Nv[i] = 1;
			return Nof1_zero2n(n);
        }
        int Nof1_zero2n(int n){
			if (Nv[n] > -1)
				return Nv[n];
			int digit = 1;
			int max_n_digit = 9;
			int count = 0;
			int ten_base = 1;
			while (max_n_digit < n) {
				//cal 10^(digit - ) to 10^2 - 1
				if (digit == 1) {
					count += Nof1_zero2n(9);
				}
				else {
					
					count += Nof1_zero2n(9)*ten_base + Nof1_zero2n(ten_base - 1) * 9;
				}
				digit++;
				ten_base *= 10;
				max_n_digit = max_n_digit * 10 + 9;
			}
			//int ten_base = pow(10, digit - 1);
			int k = n / ten_base ;
			count += Nof1_zero2n(k - 1)*ten_base + Nof1_zero2n(ten_base - 1)*(k - 1);
			int r = n - k*ten_base;
			count += NumberOf1(k)* (r + 1) + Nof1_zero2n(r);
			Nv[n] = count;
			return count;
        }
        int MaxNDigit(int n){
            if(n < 1)
                return 0;
            else
                return  MaxNDigit(n - 1)*10 + 9;
        }
        int  NumberOf1(int n) {
			int mask = 0x00000001;
			int num = n;
			int count = 0;
			while (num > 0) {
				int r = num % 10;
				if (r == 1)
					count++;
				num /= 10;
			}
			return count;
		}
	private:
		vector<int> Nv;
    };
    
}
