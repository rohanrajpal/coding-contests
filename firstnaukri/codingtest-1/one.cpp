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
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    int n;cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    forn(i,n) forn(j,n) cin>>arr[i][j];
    vector<vector<pll>> dp(n,vector<pll>(n,mp(INT_MIN,0)));
    pll tot_max = mp(arr[0][0],1);
    forn(i,n){
        forn(j,n){
            vector<pll> directions = {{-1,0},{0,-1}};
            //start at i,j
            pll max_elem=mp(arr[i][j],1);
            for(auto d:directions){
                int newi = i+d.first,newj = j+d.second;
                if(newi >=0 and newj >=0){
                    pll cur_elem = mp(arr[i][j]+dp[newi][newj].first,dp[newi][newj].second);
                    if(cur_elem.first == max_elem.first)
                        max_elem = mp(max_elem.first,max_elem.second+cur_elem.second);
                    else
                        max_elem = max(max_elem,cur_elem);
                }
            }
            dp[i][j] = max_elem;
            tot_max = max(tot_max,dp[i][j]);
        }
    }

    cout<<tot_max.first<<" "<<tot_max.second<<"\n";
}