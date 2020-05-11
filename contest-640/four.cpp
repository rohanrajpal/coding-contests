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
    fast;
    tc(){
        int n;cin>>n;
        vector<int> arr(n);
        forn(i,n) cin>>arr[i];

        int alice=arr[0],bob=0,prev_sum=arr[0],num_moves=1,i=1,j=n-1;
        
        while(i<=j){
            int cursum=0;
            if(num_moves & 1){
                //bob
                while(j>=i and cursum <= prev_sum){
                    cursum += arr[j];
                    j--;
                }
                bob += cursum;
            }
            else{
                //alice
                while(i<=j and cursum <= prev_sum){
                    cursum += arr[i];
                    i++;
                }
                alice += cursum;
            }
            prev_sum = cursum;
            num_moves++;
        }

        cout<<num_moves<<" "<<alice<<" "<<bob<<endl;
    }
}