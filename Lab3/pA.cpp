#include <bits/stdc++.h>
#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define pb push_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
//#define X first
//#define Y second
#define eps 0.00000001
#define ist insert
//#define mul(a,b,c) (a%c)*(b%c)%c
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=100005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

struct I{
    int cl,cr,rr;
};
stack<I> st;
int n,Q;
int a[N];
int pre[N];
int rangeSum(int l,int r){
    return pre[r]-pre[l-1];
}
int findPosition(int v,int sl,int sr){
    int l=sl,r=sr,res=-1;
    while (r>=l){
        int m=(l+r)/2;
        if (a[m]<=v){
            l=m+1;
            res=m;
        }
        else r=m-1;
    }
    return res;
}
pii getTarget(int cur,int target){
    int res=0;
    while (st.size()>1&&cur<target){
        auto [cl,cr,rr]=st.top();st.pop();
        int l=cl,r=cr,tmp=-1;
        //cerr<<l<<' '<<r<<'\n';
        while (r>=l){
            int m=(l+r)/2;
            if (rangeSum(m,cr)+cur>=target){
                tmp=m;
                l=m+1;
            }
            else r=m-1;
        }
        if (tmp==-1||tmp==cl){
            cur+=rangeSum(cl,cr);
            res+=cr-cl+1;
        }
        else{
            cur+=rangeSum(tmp,cr);
            st.push(I{cl,tmp-1,rr});
            res+=cr-tmp+1;
        }
    }
    if (cur<target) return make_pair(-1,-1);
    else return make_pair(res,cur);
}
void sol(){
    cin >>n>>Q;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    a[n+1]=INF;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];

    for (int qq=0,cnt,L,R,prev_r;qq<Q;qq++){
        cin >>L>>R;
        prev_r=cnt=0;
        while (st.size()) st.pop(); st.push({0,0,0});
        while (L<R){
            int rr=findPosition(L,prev_r+1,n);

            //cerr<<"pos: "<<rr<<'\n';
            if (rr==-1){
                cnt=-1;
                break;
            }
            st.push({prev_r+1,rr,rr});
            pii r=getTarget(L,min(a[rr+1],R));
            if (r.fi==-1) {cnt=-1;break;}
            else cnt+=r.fi,L=r.se;
            prev_r=rr;
        }
        cout <<cnt<<'\n';
    }
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}
/*
7 1
1 3 3 6 14 18 30
5 80
*/