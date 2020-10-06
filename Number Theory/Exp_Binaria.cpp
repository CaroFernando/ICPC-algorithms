ll exp_bin(ll x,ll p){
    ll ans=1,n=x,po=p,m=1000000007;
    while(po>0){
        if(po&1)ans*=n;
        n*=n; n%=m;
        ans%=m; po>>=1;
    }
    return ans;
}
