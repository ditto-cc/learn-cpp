/**
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Example:
 *
 * MyStack stack = new MyStack();
 *
 * stack.push(1);
 * stack.push(2);
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * Notes:
 *
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/implement-stack-using-queues
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <queue>
using namespace std;


class MyStack {
private:
    queue<int> q1, q2;

    int removeTop(queue<int> &from, queue<int> &to) {
        int ret;
        while (from.size() > 1) {
            int top = from.front();
            from.pop();
            to.push(top);
        }
        ret = from.front();
        from.pop();
        return ret;
    }
public:
    /** Initialize your data structure here. */
    MyStack() {
        q1 = queue<int>();
        q2 = queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = -1;
        if (!q1.empty()) {
            ret = removeTop(q1, q2);
        } else if (!q2.empty()){
            ret = removeTop(q2, q1);
        }
        return ret;
    }

    /** Get the top element. */
    int top() {
        int ret = -1;
        if (!q1.empty()) {
            ret = removeTop(q1, q2);
            q2.push(ret);
        } else if (!q2.empty()){
            ret = removeTop(q2, q1);
            q1.push(ret);
        }
        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */