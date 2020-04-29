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
// #define int long long
 
#define all(v) v.begin(),v.end()
#define scd second
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
#define mst(A) memset( (A) , 0 , sizeof(A) );
#define tc() int t; cin >> t ; while (t--)

using namespace std;
vector<string> paranthesis;
void recursive_insert(string& s,int start,int end){
    if(start > end) return;

    // cout<<"st:"<<start<<" end:"<<end<<"\n";
    int min_char=9;
    //greedy part
    for(int i=start;i<=end;i++) min_char = min(min_char,s[i]-'0');
    // cout<<"min:"<<min_char<<"\n";
    //enter paranthesis here
    paranthesis[start] += string(min_char,'(');
    paranthesis[end+1].insert(0,string(min_char,')'));
    // cout<<paranthesis[start]<<" "<<paranthesis[end+1]<<"\n";

    for(int i=start;i<=end;i++) {
        // cout<<"before:"<<s[i]<<" ";
        // s[i] = ((s[i]-'0') - min_char);
        int newnum = ((s[i]-'0') - min_char);
        s.replace(i,1,to_string(newnum));
        // cout<<"after:"<<s[i]<<"\n";
    }
    int st_new=start,end_new,i;
    for (i = start; i <= end; i++)
    {
        // cout<<"s[i]:"<<s[i]<<" ";
        if(s[i]=='0'){
            // cout<<"entered\n";          
            end_new = i;
            recursive_insert(s,st_new,end_new-1);
            while (i<end and s[i+1] == '0')
            {
                i++;    
            }
            end_new = i+1;
            recursive_insert(s,end_new,end);
            st_new = i+1;
            //for the same digits occuring together
            break;
        }
    }
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("err.txt","w",stderr);
    #endif

    int cnt=1;
    tc(){
        string inp;cin>>inp;
        int n=inp.size();
        string s(inp);paranthesis=vector<string>(n+1,"");
        // inp.insert(0,"))");
        recursive_insert(s,0,n-1);

        string ans="";
        for(int i=0;i<n;i++){
            ans+=paranthesis[i]+inp[i];
            // cout<<ans<<" ";
        }
        // cout<<"\n";
        ans+=paranthesis[n];
        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
}