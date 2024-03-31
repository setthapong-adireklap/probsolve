#include <bits/stdc++.h>
#include "probelib.h"

using namespace std;

int main(){

    int n = probe_init();
    int l = 0, r = n;

    int m;
    while(l <= r){
        if(r == l){
            probe_answer(l);
        }
        m = l + (r-l)/2;
        if(probe_check(l,m)){
            r = m;
        }
        else{
            l = m+1;
        }
    }

    return 0;
}