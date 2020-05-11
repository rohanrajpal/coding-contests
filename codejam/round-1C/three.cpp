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
    freopen("inputthree.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    int cnt=1;
    tc(){
        int n,d;cin>>n>>d;
        vii arr(n);
        unordered_map<int,int> umap;
        forn(i,n) {
            cin>>arr[i];
            if(!umap[arr[i]]) umap[arr[i]] = 0;
            umap[arr[i]]++;
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        
        int ans=INT_MAX,mincnt2elem=-1;
        for(auto it:umap){
            if(it.second >= d){
                ans=0;
                break;
            }
            else if(it.second == 2){
                if(mincnt2elem == -1) mincnt2elem = it.first;
                else mincnt2elem = min(mincnt2elem,it.first);
            }
        }
        
        if(ans==INT_MAX and d==2)
            ans = 1;
        else if(ans==INT_MAX and d==3){
            //ans = 1 when count of two is there and one greater elem exists
            // ans = 1 when dividing one results in two eq and one other eq
            for(auto it:umap){
                if(it.first % 2 == 0 and umap[it.first/2]){
                    // cout<<"wellhere\n";
                    ans = 1;
                }
                // else if(it.first%2 != 0 a)
                else if(mincnt2elem!=-1 and it.first > mincnt2elem){
                    // cout<<"here\n";
                    ans = 1;
                }
            }
        }

        if (ans==INT_MAX){
            ans = 2;
        }

        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
}