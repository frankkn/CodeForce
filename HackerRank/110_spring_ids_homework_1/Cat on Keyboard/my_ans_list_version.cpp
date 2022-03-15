#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

void Handle_output(vector<string>& strings)
{    
    for(auto& s : strings)
    {
        list<char> my_list;
        list<char>::iterator it = my_list.begin();
        for(list<char>::size_type i = 0; i < s.size(); ++i)
        {
            if(s[i] == '[')
            {
                it = my_list.begin();
            }
            else if(s[i] == ']')
            {
                it = my_list.end();
            }
            else
            {
                my_list.insert(it, s[i]);
            }
        }
        for(auto& i : my_list)
        {
            cout << i;
        }
        cout << "\n";
    }
}

int main() {
    int64_t queries {};
    cin >> queries;
    vector<string> strings(queries);
    
    for(auto& s:strings){ cin >> s; }
    
    Handle_output(strings);
    
    return 0;
}