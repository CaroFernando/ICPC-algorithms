ll mcd(ll a,ll b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    else return mcd(b,a%b);
}