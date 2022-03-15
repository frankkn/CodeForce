#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void Handle_output(vector<string>& strings)
{
    deque<char> d;
    for(auto& s : strings)
    {
        for(uint64_t i {}; i < s.size(); i++)
        {
                if(s[i] == '[')
                {
                    uint64_t j {i+1};
                    stack<char> st;
                    while(s[j] != '[' && s[j] != ']' && j < s.size())
                    {  
                        st.push(s[j]);
                        j++;
                    }
                    while(!st.empty())
                    {
                        char t = st.top();
                        st.pop();
                        d.push_front(t);
                    }
                    i = j-1;
                }
                else if(s[i] == ']')
                {
                    uint64_t j {i+1};
                    queue<char> q;
                    while(s[j] != '[' && s[j] != ']' && j < s.size())
                    {
                        q.push(s[j]);
                        j++;
                    }
                    while(!q.empty())
                    {
                        char t = q.front();
                        q.pop();
                        d.push_back(t);
                    }
                    i = j-1;
                }
                else
                {
                    d.push_back(s[i]);
                }
        }
        while(!d.empty())
        {
            char c = d.front();
            d.pop_front();
            cout << c;
        }
        cout << "\n";
    }
    return;
}

int main() {
    uint64_t queries {};
    cin >> queries;
    vector<string> strings(queries);
    
    for(auto& s : strings)
    {
        cin >> s;
    }
    Handle_output(strings);
    
    return 0;
}