#include<bits/stdc++.h>
// iteration and input/output stream
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define printarr(x) rep(i,0,x.size()-1) cout<<x[i]<<" "; cout<<endl;
#define all(v) v.begin(),v.end()
 
#define si(x) int x; scanf("%d", &x)
#define sll(x) ll x; scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pll(x) printf("%lld", x)
#define nl printf("\n")
#define tr(cont,it) \
for(decltype(cont.begin()) it = cont.begin(); it!= cont.end() ; it++)
 
#define endl "\n"
#define tc() int t; cin >> t ; while (t--)
//STL shortcuts
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define F first
#define S second
#define MP make_pair
 
// Error detection
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
 
using namespace std;
 
typedef long long int ll; // 64 bit integer
typedef unsigned long long int  ull; // 64 bit unsigned integer
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,ll> pill;
 
inline void smax(int &x , int y) { x = max(x , y) ; }
inline void smin(int &x , int y) { x = min(x , y) ; }
 
#define MOD 1000000007
#define inf 4000000000000000000LL
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);


bool f(ppi e1,ppi e2)
{
    if(e1.F.F!=e2.F.F)
    {
        return e1.F.F<e2.F.F;
    }
    else
    {
        return e1.F.S<e2.F.S;
    }
}

bool overlap_time(pii a1,pii a2)
{
    return a2.F<a1.S;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif
    
    int ptr = 0;
    tc()
    {
        int n;
        cin>>n;
        vector<ppi> a;
        vector<pii> arr;
        unordered_map<int,char> role;
        for (int i = 0; i < n; i++)
        {
            int x,y;
            cin>>x>>y;
            arr.pb({x,y});
            a.pb(MP(MP(x,y),i));
        }
        sort(all(a),f);
        vector<char> b= {'J','C'};
        int cur = 0;
        int f =1;
        vector<pii> job_time = {{0,0},{0,0}};//removing starting time;
        for (int i = 0;i < n; i++)
        {
            int p = 0;
            for(int j =0;j<2;j++)
            {
                bool busy = overlap_time(job_time[j],a[i].F);
                if(!busy)
                {
                    p=1;
                    job_time[j] = a[i].F;
                    cur = j;
                    break;
                }
            }
            if(p==0)
            {
                f=0;
                break;
            }
            role[i] = b[cur];
        }
        ++ptr;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans+=role[i];
        }
        if(!f)
        {
            ans = "IMPOSSIBLE";
        }
        cout<<"Case #"<<ptr<<": "<<ans<<"\n";
    }
    return 0;
}