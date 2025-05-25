#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;
    stack<char> st;

    for (auto c : x) {
        if (c == '[' || c == '(') {
            st.push(c);  // 左括号入栈
        } else if (c == ']' || c == ')') {
            if (st.empty()) {  // 栈空，缺少左括号
                cout << "lack of left parenthesis" << endl;
                return 0;
            }
            char top = st.top();
            if ((c == ']' && top == '[') || (c == ')' && top == '(')) {
                st.pop();  // 匹配成功，弹出栈顶
            } else {  // 括号类型不匹配
                cout << "isn't matched pairs" << endl;
                return 0;
            }
        }
    }

    if (st.empty()) {
        cout << "matching" << endl;
    } else {  // 栈非空，缺少右括号
        cout << "lack of right parenthesis" << endl;
    }
    return 0;
}