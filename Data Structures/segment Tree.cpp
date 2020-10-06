
// Update range, query value

vi v,st;

void build_st(){
    for(int i=0;i<n;i++){ st[i+n]=v[i]; }
}

void update_st(int L,int R,int val){
	for(L+=n,R+=n;L<R;R/=2,L/=2){
		if(L&1)st[L++]+=val;
		if(R&1)st[--R]+=val;
	}
}

int query_st(int p){  /// rango [ L , R )
    int ans=0;
    for(p+=n;p;p/=2) ans+=st[p];
	return ans;
}

// Update value, query range


vi v,st;

void build_st(){
    for(int i=0;i<n;i++){ st[i+n]=v[i]; }
    for(int i=n-1;i>0;i--){ st[i]=st[i*2]+st[i*2+1]; }
}

void update_st(int index,int val){
    st[index+=n]=val;
    while(index/=2){ st[index]=st[index*2]+st[index*2+1]; }
}

int query_st(int L,int R){  /// rango [ L , R )
    int ans=0;
    for(L+=n,R+=n;L<R;L/=2,R/=2){
        if(L%2)ans+=st[L++];
        if(R%2)ans+=st[--R];
    }
    return ans;
}

v.assign(n,0); st.assign(2*n+5,0);

