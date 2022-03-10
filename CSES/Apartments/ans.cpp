#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
    uint64_t n {}, m {}, k {};
    cin >> n >> m >> k;
    
    vector<uint64_t> queries(n);
    for(auto& q:queries){ cin >> q; }
    
    vector<uint64_t> aparts(m);
    for(auto& a:aparts){ cin >> a; }
    
    
    sort(queries.begin(),queries.end());
    sort(aparts.begin(),aparts.end());
    
    uint64_t count {};
    
    vector<uint64_t>::iterator it = queries.begin(), ij = aparts.begin();
    while(it != queries.end() && ij != aparts.end())
    {
        int diff = *ij - *it;
        if(abs(diff) > k)
        {
            if(diff > 0)
            {
                it++;
            }
            else
            {
                ij++;
            }
        }
        else
        {
            it++;
            ij++;
            count++;    
        }
    }
    cout << count;
    
    return 0;
}