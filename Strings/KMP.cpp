void checa(string s,string t){
    int i=0,j=0,m=t.size(),n=s.size();
    while(i<m){
        if(s[j]==t[i]){
            i++; j++;
        }
        if(j==n){
            cout<<"Substring encontrada en index "<< i-n <<'\n';
            j=v[j-1];
        }
        if(j<n&&i<m&&s[j]!=t[i]){
            if(j!=0) j=v[j-1];
            else i++;
        }
    }
}

void genera_sp(vi s){
    int n=s.size(),i,j;
    for(i=1,j=0;i<n&&j<n;){
        if(s[i]==s[j]){
            v[i]=j+1;
            j++; i++;
        }else{
            if(j!=0){
                j=v[j-1];
            }else{
                v[i]=0;
                i++;
            }
        }
    }
}

// DOS - JAVA

void kmp(String s,String t){
  int n=s.length(),m=t.length();
  genera_sp(s);
  for(int i=0,j=0;i<m;){
    if(s.charAt(j) == t.charAt(i)){
      j++; i++;
      if(j == n){
        print("Substring encontrada en index " + (i-n) + "\n");
        j = pre[j-1];
      }
    }else if(j!=0){
       j = pre[j-1];
    }else{
      i++; 
    }
     
  }
}

void genera_sp(String s){
  int n = s.length();
  pre = new int[n];
  pre[0]=0; 
  for(int i = 1, j=0; i<n; i++){
    while(j>0 && s.charAt(i) != s.charAt(j) ) j = pre[j-1];
    if(s.charAt(i) == s.charAt(j)) j++;
    pre[i] = j;
  }
}

