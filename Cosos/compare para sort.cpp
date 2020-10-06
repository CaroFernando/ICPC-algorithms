#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

struct tres{
    int a,b,c;
};

class Compare
{
public:
    bool operator() (tres a, tres b)
    {
        return a.c > b.c;
    }
};

tres v;
int i,x,n,m;
int t;
int a,b,c,k,h,costo;
vi p,rank;

class UnionFind{
    private: vi p, rank;
    public:
    UnionFind(int N){
        rank.assign(N,0); p.assign(N,0);
        for(int i=0;i<N;i++){ p[i]=i; }
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i,int j){ a=findSet(i); b=findSet(j); return a == b ; }
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            c++; int x=a,y=b;
            if(rank[x]>rank[j]) { p[y]=x; }
            else { p[x]=y; if(rank[x]==rank[y]) rank[y]++; }
        }
    }
    void unionSet(int i, int j,bool g){
        c++; int x=a,y=b;
        if(rank[x]>rank[j]) { p[y]=x; }
        else { p[x]=y; if(rank[x]==rank[y]) rank[y]++; }
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        bool p3=false,p4=false;
        priority_queue <tres,vector<tres>,Compare> pq;
        costo=0;
        c=0;
        cin>>n;
        UnionFind s(n);
        cin>>m;
        for(i=0;i<m;i++){
            cin>>a>>b>>k;
            if(a>b)swap(a,b);
            s.unionSet(a-1,b-1);
        }
        if(c>=n-1){ cout<<"Thank you, Goodbye"<<'\n'; p3=true; p4=true; }
        cin>>m;
        for(i=0;i<m;i++){
            cin>>a>>b>>k;
            if(a>b)swap(a,b);
            v.a=a-1; v.b=b-1; v.c=k;
            pq.push(v);
        }
        while(!pq.empty()&&n-1-c<=pq.size()){
            if(c>=n-1){ if(!p4)cout<<costo<<'\n'; p3=true; break; }
            v=pq.top();
            pq.pop();
            if(!s.isSameSet(v.a,v.b)){
                costo+=v.c;
                s.unionSet(v.a,v.b,0);
            }
        }
        if(!p4){
            if(c>=n-1){ if(!p3)cout<<costo<<'\n'; }
            else cout<<"You better hire someone else"<<'\n';
        }
    }
}