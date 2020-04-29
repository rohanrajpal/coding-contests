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
    int cnt=1;
    tc(){
        int n;cin>>n;
        string y_left_end="",y_right_end="";
        vector<string> arr(n);
        forn(i,n) cin>>arr[i];
        bool found_common=true;
        for1(i,n-1){
            string cur = arr[i];
            found_common=true;
            bool leftmode=true,rightmode=false;
            int cur_pos,y_pos;
            for(int j=0;j<cur.size();j++){
                if(leftmode and arr[i][j] != '*'){
                    y_left_end += arr[j];
                }
                else if(arr[i][j] == '*'){
                    rightmode = true;
                }
                else if(rightmode){
                    y_right_end += arr[j];
                }
            }
            if(!found_common) break;
            if(cur.size()>y_left_end.size())
                y_left_end = cur;
        }
        string y = "*";
        if(found_common)
            y_left_end=y_left_end.substr(1);
        cout<<"Case #"<<cnt++<<": "<<y_left_end<<"\n";
    }
}