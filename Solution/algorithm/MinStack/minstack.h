#include<stack>
using namespace std;
namespace MinStack{
    class Solution {
    public:
    
        void push(int value) {
            data_s.push(value);
            if(min_s.empty() || value < min())
                min_s.push(value);
            else
                min_s.push(min());
        }
        void pop() {
            data_s.pop();
            min_s.pop();
        }
        int top() {
            return data_s.top();
        }
        int min() {
            return min_s.top();
        }
    private:
        stack<int> data_s;
        stack<int> min_s;
    };
}