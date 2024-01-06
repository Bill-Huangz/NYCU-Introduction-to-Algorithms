#include "1612.h"
#include <cstring>
int a[10005];int convex_hull(int L, int k) {
    int l=-1E9,r=1E9,res=0,cnt=0;
    
    for (int i=0;i<=L;i++) a[i]=-1;
    while (r>=l){
        int m=(l+r)/2;
        auto [x,y]=query(m);
        a[x]=y;
        if (x==k) return y;
        else if (x<k){
            r=m-1;
        }
        else l=m+1;
    }
    a[0]=a[L]=0;
    r=l=k;
    while (a[l]==-1) l--;
    while (a[r]==-1) r++;;
    return a[l]+(a[r]-a[l])/(r-l)*(k-l);
}