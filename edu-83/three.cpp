//http://codeforces.com/contest/1312/problem/C
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


vii asPowerSum(int w, int m) 
{   int cnt=0;
    vii powidxs;

    while (m) { 
        if ((m + 1) % w == 0){
            m = (m + 1) / w;
            powidxs.pb(cnt);
        }
        else if (m % w == 0) 
            m = m / w;
        else
            break;
        cnt++;
    } 
  
    // If m is not zero means, it can't be  
    // represented in terms of powers of w. 
    if(m==0)
        return {-1};
    else
        return powidxs; 
} 
bool in(vii tofind, vector<vii> wholearr){
    for(vii arr: wholearr){
        int flag;
        if(tofind.size() == arr.size()){
            sort(tofind.begin(), tofind.end());
            sort(arr.begin(), arr.end());

            flag =1;
            for(int i=0;i<arr.size();i++){
                if(arr[i] != tofind[i]){
                    break;
                    flag=0;
                }
            }
        }
        if(flag == 1)
            return true;
    }
    return false;
}
signed main(){
    int t;cin>>t;
    while (t--)
    {
        int n,k;cin>>n>>k;
        vii vrr(n);

        int flag = 1;
        
        vector<vector<int>> allans;
        forn(i,n) cin>>vrr[i];

        forn(i,n) {
            vii indexes = asPowerSum(k,vrr[i]);
            if(indexes[0] == -1){
                flag=0;
                break;
            }
            cout<<"Done\n"
            if (!in(indexes,allans)){
                allans.pb(indexes);
            }
            else{
                flag=0;
                break;
            }
        }

        if(flag)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
    
}