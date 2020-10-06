#include <bits/stdc++.h>
using namespace std;

#define PI  355/113    ///3.1415926535

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector < vi > vvi;

int i,n,x,t,a,k,m,b;
vi v,w;

int knapsack(int index,int val){
    if(val==0)return 0;
    if(index==n)return 0;
    if(w[index]>val) return knapsack(index+1,val);
    else return max( knapsack( index+1 , val ) , knapsack( index+1 , val-w[index] ) + v[index] );
}

int knapSack(int W, int n){
   int i, wt;
   int K[n+1][W+1];
   memset(K,0,sizeof K);
   for (i = 1; i <= n; i++){
       for (wt = 1; wt <= W; wt++){
           if (w[i-1] <= wt)
                K[i][wt] = max(v[i-1] + K[i-1][wt-w[i-1]],  K[i-1][wt]);
           else
                K[i][wt] = K[i-1][wt];
       }
   }
   return K[n][W];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t; int j,S,wt;
    while(t--){
        cin>>n>>wt;
        int v[n],w[n];
        for(i=0;i<n;i++)cin>>v[i];
        for(i=0;i<n;i++)cin>>w[i];
        int k[wt+1]; memset(k,0,sizeof(k));
        for(i=0;i<n;i++)
            /// j = tamaño posible de la mochila
            for(j=0;j<=wt;j++)
                ///el if sirve para saber si lo puedo tomar o no, si no me saldre del indice
                if(w[i]<=j) k[j]=max(k[j],v[i]+k[j-w[i]]);
                /// enseguida tomo el mayor entre el valor que tengo y el valor que puedo tener
                /// si tomo el valor del elemento mas el valor en la mochila sin el peso del elemento
        for(i=1;i<=wt;i++) cout<<k[i]<<" "; cout<<'\n';
        cout<<k[wt]<<'\n';
    }
}
