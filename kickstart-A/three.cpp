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
#define tc() int t; cin >> t ; while (t--)

using namespace std;

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("err.txt","w",stderr);
    #endif
    
    int cnt=1;
    tc(){
        int n,k;cin>>n>>k;

        vii mrr(n,0);
        int prev=0,cur=0,maxdiff=0;
        forn(i,n) {
            cin>>mrr[i];
            cur = mrr[i];

            if(cur-prev > maxdiff){
                maxdiff = cur-prev;
            }

            prev = mrr[i];
        }
        cout<<"Case #"<<cnt<<": "<<maxdiff/2<<"\n";
        cnt++;
    }
}