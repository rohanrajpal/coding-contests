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
int n,k;

int recursivefind(vector<vector<int>> &arr,int p, \
                    int row, vector<vector<int>> &dp){
    // cout<<"Starting\n";
    if(p<=0) return 0;
    if(dp[row][p]) return dp[row][p];
    // cout<<"Started\n";
    int maxbeauty = 0;
    int i = row;
    for(;i<n;i++){
        // if(!visited[i]){
            // visited[i] = 1;
            int sumuntil=0;
            forn(j,k){
                if(j < p+1){
                    // cout<<"i:"<<i<<",j:"<<j<<" p:"<<p<<" elem:"<< \
                    // arr[i][j]<<" max_b:"<<maxbeauty<< \
                    // " sumuntil:"<<sumuntil<<"\n";
                    //checking till i-1th element
                    int max_subproblem = recursivefind(arr,p-j,i+1,dp);
                    maxbeauty = max(maxbeauty,max_subproblem+sumuntil);

                    sumuntil += arr[i][j];
                }
            }
            if(k<=p){
                // cout<<"i:"<<i<<",j:"<<k \
                //     <<" max_b:"<<maxbeauty<< \
                //     " sumuntil:"<<sumuntil<<"\n";
                int max_subproblem = recursivefind(arr,p-k,i+1,dp);
                maxbeauty = max(maxbeauty,max_subproblem+sumuntil);
            }
        // }
    }
    return dp[row][p] = maxbeauty;
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("err.txt","w",stderr);
    #endif
    int cnt=1;
    tc(){
        int p;cin>>n>>k>>p;
        vector<vector<int>> arr(n,vector<int>(k)),dp(n+1,vector<int>(p+1,0));
        // vector<int> visited(n,0);
        forn(i,n){
            forn(j,k){
                cin>>arr[i][j];
            }
        }

        int ans = recursivefind(arr,p,0,dp);

        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
}