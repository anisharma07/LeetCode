#include <iostream>
#include <queue>

using namespace std;

// class MyStack
// {
//     int its_top = -1;
//     int arr[100];

// public:
//     MyStack()
//     {
//     }

//     void push(int x)
//     {
//         arr[its_top + 1] = x;
//         its_top++;
//     }

//     int pop()
//     {
//         if (its_top == -1)
//         {
//             return -1;
//         }
//         int temp = arr[its_top];
//         arr[its_top] = 0;
//         its_top--;
//         return temp;
//     }

//     int top()
//     {
//         return arr[its_top];
//     }

//     bool empty()
//     {
//         if (its_top == -1)
//         {
//             return true;
//         }
//         return false;
//     }
// };

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
            q1.push(x);
        else
        {
            int sz = q1.size();
            q1.push(x);
            while (sz--)
            {
                q1.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
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

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->empty() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;

    return 0;
}