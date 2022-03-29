#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    
    vector<vector<int>> q(m);
    
    string str;
    stringstream ss;
        
    getline(cin, str);  
    for(int i = 0; i < m; ++i)
    {
        getline(cin, str); // ignore endl from previous cin (first cin will leave an "\n" in the buffer)
        int tmp;
        ss << str;
        while(ss >> tmp)
        {
            q[i].push_back(tmp);
        }
        ss.clear();
    }
    
    vector<deque<int>> barrels(n);
    
    for(int i = 0; i < m; ++i)
    {
        if(q[i][0] == 0) // push 
        {
            if(q[i][2] == 0) // push front
            {
                barrels[q[i][3]-1].push_front(q[i][1]);    
            }
            else // push back
            {
                barrels[q[i][3]-1].push_back(q[i][1]);
            }
        }
        else // retrive
        {
            if(q[i][1] == 0) // pop front
            {
                int out_val = barrels[q[i][2]-1].front();
                cout << out_val << "\n";
                barrels[q[i][2]-1].pop_front();
            }
            else // pop back
            { 
                int out_val = barrels[q[i][2]-1].back();
                cout << out_val << "\n";
                barrels[q[i][2]-1].pop_back();
            }
        }
    }

    return 0;
}