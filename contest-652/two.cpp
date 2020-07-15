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
        int n;cin>>n;
        string s,ans;cin>>s;
        bool onepresent=false;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='1'){
                onepresent = true;
                ans += ch;
            }
            else if(ch=='0'){
                if(!ans.empty() and ans.back()=='0' and onepresent)
                    continue;
                while(!ans.empty() and ans.back()=='1')
                    ans.pop_back();
                if(!onepresent or ans.empty())
                    ans+=ch;
            }
            // cout<<ans<<"\n";
        }
        cout<<ans<<"\n";
        // cout<<"-------------\n";
    }
}