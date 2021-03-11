#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

/* Naive method for pattern matching */
void match(string st, string pt){
    int n = st.length();    // length of haystack
    int m=pt.length();      // length of needle
    for(int i=0;i<n;i++){   //Outer loop
        int j=0;
        while(j<m && i+j<n){    //Inner loop breaks if a mismatch is detected
            if(st[i+j]!=pt[j]){
                break;
            }
            j++;
        }
        if(j==m){               //Check if pattern contains till checked
            cout<<"Match found"<<endl;
            return;
        }
    }
    cout<<"No match found"<<endl;   //No match found yet
    return;
}


int main(){
    string st;
    cin>>st;
    string pt;
    cin>>pt;
    match(st,pt);

    return 0;
}
