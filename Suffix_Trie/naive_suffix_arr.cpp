
/*Naive approach to create suffix array */

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

struct suffix{
    int ind;
    string suff;
};
bool cmpsuff(struct suffix a, struct suffix b){
    if(a.suff.compare(b.suff)<0){
        return true;
    }
    else{
        return false;
    }
}
vector<int> suffix_arr(string st, int n){

    struct suffix suffixes[n];

    for(int i=0;i<n;i++){
        suffixes[i].ind=i;
        cout<<suffixes[i].ind<<endl;
        suffixes[i].suff= st.substr(i);
        cout<<suffixes[i].suff<<endl;
    }
    sort(suffixes,suffixes+n,cmpsuff);
    vector<int> suff_st(n,0);
    for(int i=0;i<n;i++){
        suff_st[i]=suffixes[i].ind;
    }
    return suff_st;
}

int main(){
    string inp;
    cin>>inp;
    int n= inp.length();
    vector<int> ans=suffix_arr(inp,n);
    for(int i =0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
