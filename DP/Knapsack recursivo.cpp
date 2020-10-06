#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define EPS 1e-9
#define INF  1e15 +1    /// 10^15 + 1
#define INF2 1<<63 /// 2^63

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector < vi > vvi;
typedef vector < vll > vvll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef vector < vpii > vvpii;

ll mcd(ll a,ll b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    else return mcd(b,a%b);
}

struct item{
    int w,v;
};

int i,n,m,k;
vector <item> v;
item a;
int dp[103][10205];

int f(int index,int llevo,bool extra){
    if(index==n||llevo==k) {
        if(extra)
            if(llevo>2000||llevo<=k-200)return 0;
            else return -1000000;
        else return 0;
    }
    if(dp[index][llevo]!=-1) return dp[index][llevo];
    if(llevo+v[index].w>k) return dp[index][llevo]=f(index+1,llevo,extra);
    else return dp[index][llevo]=max(f(index+1,llevo+v[index].w,extra)+v[index].v,f(index+1,llevo,extra));
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    while(cin>>k>>n){
        v.assign(n,a);
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++){
            cin>>v[i].w>>v[i].v;
        }
        bool si=false;
        if(k>1800){
            k+=200; si=true;
        }
        m=f(0,0,si);
        cout<<m<<'\n';
    }
}
