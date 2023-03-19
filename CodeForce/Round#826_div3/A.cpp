#include <iostream>
#include <vector>
#include <string>
using namespace std;

void compare(string a, string b)
{
    auto a_type_idx = a.find_first_not_of('X');
    auto b_type_idx = b.find_first_not_of('X');
    if(a[a_type_idx] == b[b_type_idx])
    {
        if(a_type_idx == b_type_idx)
        {
            cout << "=";
            return;
        }
        else if(a[a_type_idx] == 'S')
        {
            if(a_type_idx < b_type_idx) cout << ">";
            else    cout << "<";
            return;
        }
        else
        {
            if(a_type_idx < b_type_idx) cout << "<";
            else    cout << ">";
            return;
        }
    }
    else if(a[a_type_idx] == 'S')
    {
        cout << "<";
        return;
    }
    else if(a[a_type_idx] == 'L')
    {
        cout << ">";
        return;
    }
    else
    {
        if(b[b_type_idx] == 'S')    cout <<">";
        else    cout << "<";
        return;
    }
}

vector<pair<string,string>> v;

void input()
{
  int t;
  cin >> t;
  while(t--)
  {
    pair<string, string> p;
    cin >> p.first >> p.second;
    v.emplace_back(p);
  }
}

int main()
{

    input();
    for(auto v_i : v)
    {
      compare(v_i.first, v_i.second);
      cout << "\n";
    }

    return 0;
}
