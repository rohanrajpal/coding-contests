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
        int n,toadd = -2,i;cin>>n;
        vii arr(n,-1);
        int cur = n & 1 ? n-1:n;
        // cout<<cur<<"done\n";
        for(i=0;i<n and cur >0;i++){
            if(cur >= 6){
                arr[i] = cur;
            }
            else{
                arr[i] = 2;
                arr[i+1] = 4;
                i+=2;
                break;
            }
            cur -= 2;
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
        cur = 1;
        for(i;i<n and cur<=n;i++){
            arr[i] = cur;
            cur += 2;
        }

        if(arr[0] == -1 or n<=3)
            cout<<-1;
        else
        {
            forn(i,n) cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}