#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Swing(vector<int>& A)
{
    sort(A.begin(), A.end()); // increasing order 
    while(!A.empty())
    {
        auto it = A.begin();
        while(it != A.end())
        {
            if(next(it) != A.end())
            {
                if(*it == *next(it))
                {
                    it++;
                }
                else
                {
                    cout << *it << " ";
                    it = A.erase(it);
                }
            }
            else
            {
                cout << *it << " ";
                it = A.erase(it);
            }
        }
        auto rit = A.rbegin();
        while(rit != A.rend())
        {
            if(next(rit) != A.rend())
            {
                if(*rit == *next(rit))
                {
                    rit++;
                }
                else
                {
                    cout << *rit << " ";
                    rit = vector<int>::reverse_iterator(A.erase((++rit).base()));
                }
            }
            else
            {
                cout << *rit << " ";
                rit = vector<int>::reverse_iterator(A.erase((++rit).base()));
            }
        }
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    while(n--)
    {
        int len;
        cin >> len;
        vector<int> A(len);
        for(auto& A_i : A){ cin >> A_i; }
        Swing(A);
    }
    return 0;
}