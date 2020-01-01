//https://codeforces.com/contest/1279/problem/B
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
// #define int long long
 
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
    while(t--){
        // cout<<"hh\n";
        int n,s,i;cin>>n>>s;
        pll maxval = pll{0,0};
        int temps = s;
        vii arr(n);
        for (i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
                    
        for (i = 0; i < n; i++)
        {
            if(arr[i] > maxval.first){
                maxval.first = arr[i];
                maxval.second = i;
            }
            if(temps >= arr[i])
                temps -= arr[i];
            else
            {
                break;
            }
            
        }
        // cout<<"max: "<<maxval.first<<"\n";
        if(i-1==n-1){
            cout<<"0\n";continue;
        }
        int noskiplen = i-1 + 1;
        temps = s;
        for (i = 0; i < n; i++)
        {
            if(i == maxval.second)
                continue;
            if(temps >= arr[i])
                temps -= arr[i];
            else
            {
                break;
            }
        }
        int skiplen = i-1;
        // cout<<"skiplen: "<<skiplen<<" noskip: "<<noskiplen<<"\n";
        if(noskiplen > skiplen)
            cout<<"0\n";
        else
        {
            cout<<maxval.second+1<<"\n";
        }
    }
}
