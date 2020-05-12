
/*
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

pop、top 和 getMin 操作总是在 非空栈 上调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> data, s;
public:
    /** initialize your data structure here. */
    MinStack() {
        data = vector<int>();
        s = vector<int>();
    }

    void push(int x) {
        data.push_back(x);
        if (s.empty() || s.back() >= x) {
            s.push_back(x);
        }
    }

    void pop() {
        int t = top();
        data.pop_back();
        if (t == s.back()) {
            s.pop_back();
        }
    }

    int top() {
        if (data.empty()) {
            throw "Empty Stack.";
        }
        return data.back();
    }

    int getMin() {
        if (data.empty()) {
            throw "Empty Stack.";
        }
        return s.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */