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
struct Time_obj{
    int st,end,pos,person;
    // int person;

    // Time_obj(int st, int end,int pos):st(st),end(end),pos(pos){}
};

struct less_than_st
{
    inline bool operator() (const Time_obj& struct1, const Time_obj& struct2)
    {
        return (struct1.st < struct2.st);
    }
};
struct less_than_pos
{
    inline bool operator() (const Time_obj& struct1, const Time_obj& struct2)
    {
        return (struct1.pos < struct2.pos);
    }
};
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif

    int cnt=1;
    tc(){
        int n;cin>>n;
        vector<Time_obj> schedule(n,{0,0,0,0});
        forn(i,n) {
            int st,end;cin>>st>>end;
            Time_obj cur = {st,end,i,0};
            schedule[i] = cur;
            // cout<<schedule[i].st<<" k";
        }

        sort(all(schedule),less_than_st());
        int c_till = 0, j_till=0;
        string ans="";
        
        for(int i=0;i<n;i++){
            // cout<<c_till<<" "<<j_till<<"\n";
            if(schedule[i].st>=c_till){
                schedule[i].person = 0;
                c_till = schedule[i].end;
            }
            else if(schedule[i].st>=j_till){
                schedule[i].person = 1;
                j_till = schedule[i].end;
            }
            else{
                ans="IMPOSSIBLE";
                break;
            }
        }
        if(ans != "IMPOSSIBLE"){
            sort(all(schedule),less_than_pos());
            for(int i=0;i<n;i++){
                if(schedule[i].person == 0)
                    ans+='C';
                else
                    ans+='J';
            }
        }
        
        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
}