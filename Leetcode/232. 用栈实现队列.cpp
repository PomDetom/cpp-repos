class MyQueue {
public:
    stack<int>myQueue1;
    stack<int>myQueue2;

    MyQueue() {
        
    }
    
    void push(int x) {

        if (myQueue2.empty() != true)
        {
            while (myQueue2.empty() != true)
            {
                int ret = myQueue2.top();
                myQueue1.push(ret);
                myQueue2.pop();
            }
        }

        myQueue1.push(x);
        
        while (myQueue1.empty() != true)
        {
            int ret = myQueue1.top();
            myQueue2.push(ret);
            myQueue1.pop();
        }
    }
    
    int pop() {

        int ret = myQueue2.top();
        myQueue2.pop();
        return ret;
    }
    
    int peek() {

        return myQueue2.top();
    }
    
    bool empty() {

        return myQueue2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */