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
    int cnt=1;
    tc(){
        int k=0,r=0,c=0,n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int>(n,0));

        //row major
        forn(i,n){
            vector<int> check_repeat(n+1,0);
            bool repeat = false;
            forn(j,n){
                cin>>arr[i][j];
                check_repeat[arr[i][j]] ^= arr[i][j];

                if(check_repeat[arr[i][j]]==0) repeat = true;
            }
            if(repeat) r++;
        }
        //column major
        forn(j,n){
            vector<int> check_repeat(n+1,0);
            bool repeat = false;
            forn(i,n){
                // cin>>arr[i][j];
                if (i==j) k += arr[i][j];
                check_repeat[arr[i][j]] ^= arr[i][j];

                if(check_repeat[arr[i][j]]==0) repeat = true;
            }
            if(repeat) c++;
        }

        cout<<"Case #"<<cnt<<": "<<k<<" "<<r<<" "<<c<<"\n";
        cnt++;
    }
}