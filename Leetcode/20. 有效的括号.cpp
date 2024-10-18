class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> cap;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                cap.push(s[i]);
            }
            else if (cap.size() == 0)
            {
                return false;
            }
            else if ((s[i] == ')' && cap.top() == '(')
                  || (s[i] == ']' && cap.top() == '[')
                  || (s[i] == '}' && cap.top() == '{'))
            {
                cap.pop();
            }
            else
            {
                return false;
            }
        }

        if (cap.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};