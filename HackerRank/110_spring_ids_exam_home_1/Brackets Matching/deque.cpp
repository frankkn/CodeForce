#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Check(string s)
{
    deque<char> stack;
    for(auto c : s)
    {
        if(c == '(')
        {
            stack.push_back('(');
        }
        else if(c == ')')
        {
            if(stack.empty())
            {
                cout << "No\n";
                return;
            }
            if(stack.back() == '(')
            {
                stack.pop_back();
            }
            else
            {
                }
        }
        else if(c == '[')
        {
            stack.push_back('[');
        }
        else
        {
            if(stack.empty())
            {
                cout << "No\n";
                return;
            }
            if(stack.back() == '[')
            {
                stack.pop_back();
            }
            else
            {
                cout << "No\n";
                return;
            }
        }
    }
    if(stack.empty())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return;
}
    
int main() {
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        Check(s);
    }
    return 0;
}