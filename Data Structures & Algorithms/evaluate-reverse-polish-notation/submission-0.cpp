class Solution {
public:
    int stoint(string s) {
        int i =0;
        bool neg=false;
        if (s[0] == '-') {
            i++;
            neg = true;
        }
        int res = 0;
        for (;i<s.size();i++) {
            res = res * 10 + s[i]-'0';
        }
        return neg ? -res : res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int x, y;
        for (auto s : tokens) {
            if (s.size()==1 && s[0] == '+') {
                y = stk.top();
                stk.pop();
                x = stk.top();
                stk.pop();
                x+=y;
                stk.push(x);
            } else if (s.size()==1 && s[0] == '-') {
                y = stk.top();
                stk.pop();
                x = stk.top();
                stk.pop();
                x-=y;
                stk.push(x);
            } else if (s.size()==1 && s[0] == '*') {
                y = stk.top();
                stk.pop();
                x = stk.top();
                stk.pop();
                x*=y;
                stk.push(x);
            } else if (s.size()==1 && s[0] == '/') {
                y = stk.top();
                stk.pop();
                x = stk.top();
                stk.pop();
                x/=y;
                stk.push(x);
            } else {
                x = stoint(s);
                stk.push(x);
            }
        }
        return stk.top();
    }
};