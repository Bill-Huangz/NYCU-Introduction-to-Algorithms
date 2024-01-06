#include "1622.h"
#include <vector>
#define pb push_back
using namespace std;
Number two_increasing_arrays(int n, int k, std::vector<Number> a, std::vector<Number> b) {
    // std::vector<int> tmp{a[0], b[0]}; // this costs 0
    vector<Number> A,B;
    A.pb(a[0]);B.pb(b[0]);
    for (int i=0;i<n;i++){
        A.pb(a[i]);
        B.pb(b[i]);
    }
    if (k==2*n){
        if (A[n]>B[n]) return A[n];
        else return B[n];
    }
    if (k==1){
        if (A[1]<B[1]) return A[1];
        else  return B[1];
    }
    
    int L=1,R=n,rb=(k<=n?k:-1),ra=(k<=n?k:-1);
    while (R>=L){
        int m=(L+R)/2;
        if (k-m>n){
            L=m+1;
            continue;
        }
        else if (k-m<1){
            R=m-1;
            continue;
        }
        if (A[m]>B[k-m]){
            ra=m;
            R=m-1;
        }
        else L=m+1,rb=k-m;
    } 
    /*L=1,R=n;
    while (R>=L){
        int m=(L+R)/2;
        if (k-m>n){
            L=m+1;
            continue;
        }
        else if (k-m<1){
            R=m-1;
            continue;
        }
        if (B[m]>A[k-m]){
            rb=m;
            R=m-1;
        }
        else L=m+1;
    } */
    if (ra==-1) return B[rb];
    if (rb==-1) return A[ra];
    if (A[ra]>B[rb]) return B[rb];
    else return A[ra];
}