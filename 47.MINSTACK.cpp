#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> s1;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s1.push(val);
    }

    void pop()
    {
        s1.pop(val);
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        if (s1.empty())
        {
            return -1;
        }
        int minEle = INT_MIN;
        while (s1.size() > 0))
            {
                if (minEle > s1.top())
                {
                    minEle = s1.top();
                }
                s2.push(s1.top());
                s1.pop();
            }
        while (s2.size() > 0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{

    return 0;
}