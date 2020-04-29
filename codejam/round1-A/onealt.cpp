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
pair<string,string> get_prefix_suffix(string& s){
    string p="",k="";
    for(int i =0;s[i]!='*';i++) p+=s[i];
    for(int i=s.size()-1;s[i]!='*';i--) k+=s[i];
    // reverse(all(k));
    return mp(p,k);
}
string find_bigger_intersection(string& suffix_glob, string& suffix_local,int step){
    if(step == 1){
        for(int i=0,j=0;i<suffix_glob.size() and j<suffix_local.size();i+=step,j+=step){
            if(suffix_glob[i] != suffix_local[j]) return "None";
        }
    }
    else{
        for(int i=suffix_glob.size()-1,j=suffix_local.size()-1;i>=0 and j>=0;i+=step,j+=step){
            if(suffix_glob[i] != suffix_local[j]) return "None";
        }
    }
    
    if(suffix_glob.size() > suffix_local.size()) return suffix_glob;
    else return suffix_local;
}
void add_middle(string& middle, string& inp){
    int i,j;
    for(i=0;i<inp.size();i++){
        if(inp[i] == '*') {i++;break;}
    }
    for(j=inp.size()-1;j>=0;j--){
        if(inp[j] == '*') {j--;break;}
    }
    // cout<<"\n";
    // cout<<i<<" "<<j<<"\n";
    for(int k=i;k<=j;k++) if(inp[k]!='*') middle += inp[k];
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    int cnt=1;
    tc(){
        int n;cin>>n;
        vector<string> arr(n);
        forn(i,n) cin>>arr[i];

        string prefix="",suffix="",middle="",ans="";

        forn(i,n){
            pair<string,string> p_s = get_prefix_suffix(arr[i]);
            // cout<<p_s.second<<"\n";
            prefix = find_bigger_intersection(prefix,p_s.first,1);
            suffix = find_bigger_intersection(suffix,p_s.second,1);
            add_middle(middle,arr[i]);
            // cout<<prefix<<" "<<middle<<" "<<suffix<<" ";
            // cout<<prefix.size()<<" "<<middle.size()<<" "<<suffix.size()<<"\n";
            if(prefix == "None" or suffix == "None"){
                ans="*";
                break;
            }
        }
        if(ans!="*"){
            reverse(all(suffix));
            ans = prefix+middle+suffix;
        }
        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
}