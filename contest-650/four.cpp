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
    // fast;
    tc(){
        // cout<<"st\n";
        string s;cin>>s;
        // sort(s.begin(),s.end());
        int m;cin>>m;
        vii brr(m);
        vii count(26,0);
        forn(i,m) {
            cin>>brr[i];
        }
        forn(i,s.size())
            count[s[i]-'a']++;
        // forn(i,26)
        //     cout<<count[i]<<" ";
        // cout<<"done\n";
        // cout<<"\n";
        string ans(m,'*');
        // cout<<"reached";
        int p=m;
        while(p>0){
            //find min 0
            vector<int> indexes;
            vector<int>::iterator it = find(all(brr),0);
            while(it != brr.end()){
                int idx =  it - brr.begin();
                brr[idx] = -1;
                indexes.push_back(idx);
                it = find(all(brr),0);
            }
            
            // cout<<indexes[0]<<endl;
            //take last elem of s and put
            int k = indexes.size(),j;
            for(j=25;j>=0;j--)
                if(count[j]>=k)
                    break;
            count[j] = 0;
            // cout<<j<<" is\n";
            for(int idx:indexes)
                ans[idx] = 'a'+j;
            
            //do updates
            // int sub = accumulate(all(indexes),0);

            forn(j,m)
                if(brr[j]>0)
                    for(int idx:indexes)
                        brr[j] -= abs(j-idx);
            p -= k;
            // cout<<k<<" going\n";
            // forn(j,m)
            //     cout<<brr[j]<<" ";
            // cout<<endl;
            // cout<<ans<<"\n";
            // if(k==0) break;
        }
        
        cout<<ans<<"\n";
    }
}