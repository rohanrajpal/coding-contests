//http://codeforces.com/contest/1278/problem/C
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

    while(t--){
        map<int,int> difmap;
        int n,cur;cin>>n;
        vector<int> arr(2*n);

        for (int i = 0; i < 2*n; i++)
        {
            cin>>arr[i];
        }
        
        cur=0;
        difmap[0] = 0;
        for(int i=n;i < 2*n; i++){
            if(arr[i] == 1)
                cur++;
            else
                cur--;
            
            if(!difmap.count(cur))
                difmap[cur] = i - n + 1;
        }

        int dif = count(arr.begin(),arr.end(),1) - count(arr.begin(),arr.end(),2);
        // cout<<"dif: "<<dif<<"\n";
        cur = 0;
        int ans = 2*n;
        for(int i=n-1;i>=0;i--){
            if(arr[i] == 1)
                cur++;
            else
                cur--;
            
            if(difmap.count(dif-cur))
                ans = min(ans, n - i + difmap[dif-cur]);
        }
        if(difmap.count(dif))
            ans = min(ans,difmap[dif]);
        
        cout<<ans<<"\n";
    }
}