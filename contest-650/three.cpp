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
        int n,k;cin>>n>>k;
        string str;cin>>str;
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                for(int j=i-k;j<=i+k;j++)
                    if(j>=0 and j<n)
                        str[j] = '2';
                i+=k;
            }
        }
        // cout<<str<<"\n";
        int ans=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                for(int j=i;j<=i+k;j++){
                    if(j>=0 and j<n)
                        if(str[j]!='2')
                            str[j] = '2';
                        else
                            break;
                }
                ans++;
                i+=k;
            }
        }
        
        cout<<ans<<"\n";
    }
}