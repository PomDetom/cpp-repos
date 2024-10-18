class MyStack {
public:
    queue<int>myStack1;
    queue<int>myStack2;

    MyStack() {
        
    }
    
    void push(int x) {

        if (myStack1.empty() == true)
        {
            myStack2.push(x);
        }
        else
        {
            myStack1.push(x);
        }
    }
    
    int pop() {
        
        if (myStack1.empty() != true)
        {
            while (myStack1.size() != 1)
            {
                myStack2.push(myStack1.front());
                myStack1.pop();
            }
            int ret = myStack1.front();
            myStack1.pop();
            return ret;
        }
        else
        {
            while (myStack2.size() != 1)
            {
                myStack1.push(myStack2.front());
                myStack2.pop();
            }
            int ret = myStack2.front();
            myStack2.pop();
            return ret;
        }
    }
    
    int top() {
        
        if (myStack1.empty() != true)
        {
            return myStack1.back();
        }
        else
        {
            return myStack2.back();
        }
    }
    
    bool empty() {
        
        if (myStack1.empty() == true && myStack2.empty() == true)
        {
            return true;
        }
        return false;
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