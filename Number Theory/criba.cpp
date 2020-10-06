#include <bits/stdc++.h>
using namespace std;

bool criba[1000006];

int main(){
    
    criba[0]=criba[1]=true;
    for(long long i=2; i*i<1000006;i++){
        if(criba[i] == false){
            for(long long j = i*2; j<1000006; j+=i){
                criba[j] = true;
            }
        }
    }
    for(long long i=0; i<1000;i++){
        if(criba[i] == false){
            cout<<i<<' ';
        }
    }
    cout<<'\n';
}
