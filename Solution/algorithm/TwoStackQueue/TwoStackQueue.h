#pragma once
#include <stack>
using namespace std;
namespace TwoStackQueue {
	class Solution
	{
	public:
		void push(int node) {
			stack1.push(node);
		}

		int pop() {
			int val;
			if (stack2.empty()) {
				while (!stack1.empty()) {
					stack2.push(stack1.top());
					stack1.pop();
				}
				val = stack2.top();
				stack2.pop();
			}
			else {
				val = stack2.top();
				stack2.pop();
			}
			return val;
		}

	private:
		stack<int> stack1;
		stack<int> stack2;
	};
}
