#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    deque<int> Q;
    
    while(m--)
    {
        int op, id;
        cin >> op;
        if(op == 0) // join
        {
            cin >> id;
            Q.push_back(id);
        }
        else if(op == 1) // pop and cout
        {
            if(!Q.empty())
            {
                cout << Q.front() << "\n";
                Q.pop_front();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else // op == 2, left the queue
        {
            cin >> id;
            auto it = Q.begin();
            while(*it != id)
            {
                it++;
            }
            Q.erase(it);
        }
    }
    return 0;
}