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
#define endl "\n"

#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

#define mst(A) memset( (A) , 0 , sizeof(A) );
#define tc() int t; cin >> t ; while (t--)

using namespace std;

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    tc(){
        int n,goingup=-1;cin>>n;
        vii arr(n);
        forn(i,n){
            cin>>arr[i];
            if(i>0 and goingup==-1)
                if(arr[i]<arr[i-1])
                    goingup=0;
                else if(arr[i]>arr[i-1])
                    goingup=1;
        }
        int prev=arr[0],cur;
        vii ans;
        ans.push_back(prev);
        
        for1(i,n-1){
            cur=arr[i];
            // cout<<"going "<<goingup<<"\n";
            if(goingup){
                if(cur<prev){
                    ans.push_back(prev);
                    goingup = 1-goingup;
                }
            }
            else{
                if(cur>prev){
                    ans.push_back(prev);
                    goingup = 1-goingup; 
                }
            }
            prev=cur;
        }
        if(ans.back()!=arr[n-1]) ans.push_back(arr[n-1]);
        cout<<ans.size()<<"\n";

        forn(i,ans.size()) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}