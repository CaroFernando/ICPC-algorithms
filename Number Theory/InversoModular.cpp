
ll bin_pow(ll a, ll x, ll mod) {
    ll ans=1;
    for(ll p=a%mod; x; x/=2, p=p*p%mod) {
        if(x&1) {
            ans = ans*p%mod;
        }
    }
    return ans;
}
 
ll inv(ll x, ll mod) {
    return bin_pow(x, mod-2, mod);
}


