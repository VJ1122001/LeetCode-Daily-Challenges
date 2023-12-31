//driver code
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
}

//TC : push O(1) pop() O(N)
//SC : O(N) extra queue
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        
        if(!q1.empty())
            q1.push(x);
        
        if(!q2.empty())
            q2.push(x);
        
        if(q1.empty() && q2.empty())
            q1.push(x);
    }
    
    int pop() {
        
        int ans=-1;
        if(q1.empty())
        {
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            
            ans= q2.front();
            q2.pop();
            return ans;
            
        }
        
        if(q2.empty())
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            ans= q1.front();
            q1.pop();
            return ans;
        }
        
        return ans;
    }
    
    int top() {
        
        int ans=-1;
        if(q1.empty())
        {
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            
            ans= q2.front();
            q1.push(q2.front());
            q2.pop();
            return ans;
            
        }
        
        if(q2.empty())
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            ans= q1.front();
            q2.push(q1.front());
            q1.pop();
            return ans;
        }
        
        return ans;
    }
    
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