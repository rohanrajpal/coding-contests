//http://codeforces.com/contest/1311/problem/C
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
    int t;cin>>t;

    while (t--)
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vii prr(m);
        
        for(int i=0;i<m;i++)
            cin>>prr[i];
        
        vii ans(26,0);

        //compute prefix
        int prefixarr[26][n];
        mst(prefixarr);
        for(int i=0;i<n;i++){
            if(i>0)
                for(int j=0;j<26;j++){
                    prefixarr[j][i] = prefixarr[j][i-1];
                }
            prefixarr[s[i] - 'a'][i] += 1 ;
        }
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<prefixarr[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        //watch the parr and add to ans according to prefix
        for(int i=0;i<m;i++){
            int prefix_pos = prr[i]-1;
            for(int j=0;j<26;j++){
                ans[j] += prefixarr[j][prefix_pos];
            }
        }
        for(int j=0;j<26;j++){
            ans[j] += prefixarr[j][n-1];
        }
        //print ans
        for(int i=0;i<26;i++)
            cout<<ans[i]<<" ";

        cout<<"\n";
    }
    
}