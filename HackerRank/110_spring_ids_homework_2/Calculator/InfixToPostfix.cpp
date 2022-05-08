#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int Priority(char& op){
    if(op == '+' || op == '-') { return 1; }
    else if(op == '*' || op == '/') { return 2; }
    return 0;
}

void InfixToPostfix(string& infix, string& postfix){
    stack<char> s;
    for(auto c:infix){
        if(c >= 'A' && c <= 'E'){
            postfix += c;
        }else if(c == '('){
            s.push('(');
        }else if(c == ')'){
            while(s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }else{
            int p = Priority(c);
            while(!s.empty() && p <= Priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
}

int Calculate(string& postfix, vector<int>& values){
    stack<int> s;
    for(auto c:postfix){
        if(c >= 'A' && c <= 'E'){
            s.push(values[c - 'A']);
        }else if(c == '+'){
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left + right);
        }else if(c == '-'){
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left - right);
        }else if(c == '*'){
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left * right);
        }else{
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(left / right);
        }
    }
    return s.top();
}

int main() {
    string infix;
    cin >> infix;
    string postfix;
    InfixToPostfix(infix, postfix);
    //cout << postfix;
    int nums_infix;
    cin >> nums_infix;
    while(nums_infix--){
        vector<int> values(5);
        for(auto& v : values){
            cin >> v;
        }
        cout << Calculate(postfix, values) << "\n";
    }

    return 0;
}
