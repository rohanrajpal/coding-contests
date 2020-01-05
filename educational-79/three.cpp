//https://codeforces.com/contest/1279/problem/C
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vii vector<int>
#define vvll vector< vll >
#define pll pair<ll ,ll >
#define MOD 1000000007
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define int long long
 
#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#define mst(A) memset( (A) , 0 , sizeof(A) );
 
using namespace std;

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,temp;cin>>n>>m;
        deque<int> inventory, thelist;
        for (int i = 0; i < n; i++)
        {
            cin>>temp;
            inventory.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            cin>>temp;
            thelist.push_back(temp);
        }
        int time=0;
        while(!thelist.empty()){
            set<int> buffer;
            int steps=0;
            while (true)
            {
                int num = inventory.front();
                if(num == thelist.front())
                    break;
                steps++;
                buffer.insert(num);
                inventory.pop_front();
                // cout<<"Going: "<<num<<"\n";
            }
            inventory.pop_front();
            thelist.pop_front();
            // cout<<"Reached eof while\n";
            // set<int>::iterator itr;
            vector<int> finalorder;
            //first put the required elements
            for (int i = 0; i < min(buffer.size(),thelist.size()); i++)
            {
                int elem = thelist.at(i);
                if(buffer.find(elem) != buffer.end()){
                    finalorder.push_back(elem);
                    // cout<<"adding pr: "<<elem<<"\n";
                    buffer.erase(buffer.find(elem));
                }
            }
            
            // cout<<"eof priority\n";

            for (auto elem : buffer)
            {
                // cout<<elem<<"\n";
                finalorder.push_back(elem);
            }
            // cout<<"giving order\n";
            // for (int i = finalorder.size()-1; i >= 0 ; i--)
            while (!finalorder.empty())
            {
                // cout<<finalorder[i]<<" ";
                inventory.push_front(finalorder.back());
                finalorder.pop_back();
            }
            // cout<<"\n";
            time += 2 * steps +1;
            // cout<<time<<"\n";
        }
        cout<<time<<"\n";
    }
    return 0;
}