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
void search(string pt, string st, vector<int> suff_st, int n){

    int m =pt.length();
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid = l+(r-1)/2;
        int res= pt.compare(st.substr(0,suff_st[mid]+1));

        if(res==0){
            cout<<"Pattern found at index "<<suff_st[mid]<<endl;
            return ;
        }
        if(res<0){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<"Pattern not found "<<endl;
    return;
}

int main(){
    string inp;
    cin>>inp;
    string cmp;
    cin>>cmp;
    int n= inp.length();
    vector<int> ans=suffix_arr(inp,n);
    for(int i =0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n"<<endl;
    search(cmp,inp,ans,n);
    return 0;
}