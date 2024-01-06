#include <bits/stdc++.h>
#define int long long
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pi pair<int, int>
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
#define INF 10000000000000000
#define eps 0.00000001
#define ist insert
#define mod 1000000007
#define N 100005
#define M 1000005
#define DNE nullptr
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC optimize("O2")
using namespace std;
typedef int ll;
int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}
bool isprime(int k){bool is=1 ; for ( int i = 2 ; i*i <= k ; i++ ) if ( k % i == 0 ) is = 0 ; return k>1?is:0;}
const double PI=acos(-1);
/*int read(){
   int s=0,w=1;
   char c=getchar();
   while (c<'0'||c>'9'){if (c=='-')w=-1;c=getchar();}
   while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
   return s*w;
}*/
struct seg{
    struct node{
        int mx;
        int sum;
        int pre;
        int suf;
        node(){}
        node(int _mx,int _sum,int _pre,int _suf):mx(_mx),sum(_sum),pre(_pre),suf(_suf){}
    };
    int n,sz;
    vector<node> st;
    void init(int _n){
        n=_n;
        sz=1;
        while (sz<n) sz*=2;
        st.resize(sz*2,node(0,0,0,0));
    }
    node merge(node L,node R){
        node res;
        res.sum=L.sum+R.sum;
        res.pre=max(L.pre,L.sum+R.pre);
        res.suf=max(R.suf,R.sum+L.suf);
        res.mx=max(L.suf+R.pre,max(res.pre,res.suf));
        res.mx=max(res.mx,max(L.mx,R.mx));
        return res;
    }
    void build(vector<int> &t,int pos,int l,int r){
        if (r-l==1){
            if (l<n){
                st[pos].sum=t[l];
                st[pos].pre=max(0,t[l]);
                st[pos].suf=max(0,t[l]);
                st[pos].mx=max(0,t[l]);
            }
            return;
        }
        int m=(l+r)/2;
        build(t,2*pos+1,l,m);
        build(t,2*pos+2,m,r);
        st[pos]=merge(st[2*pos+1],st[2*pos+2]);
    }
    void build(vector<int> &t){build(t,0,0,sz);}
 
    void modify(int i,int v,int pos,int l,int r){
        if (r-l==1){
            st[pos].sum=v;
            st[pos].pre=max(0,v);
            st[pos].suf=max(0,v);
            st[pos].mx=max(0,v);
            return;
        }
        int m=(l+r)/2;
        if (i<m) modify(i,v,2*pos+1,l,m);
        else modify(i,v,2*pos+2,m,r);
        st[pos]=merge(st[2*pos+1],st[2*pos+2]);
    }
    void modify(int i,int v){modify(i,v,0,0,sz);}
 
    node query(int pos,int l,int r,int lq,int rq){
        if (l>=rq||r<=lq) return node(0,0,0,0);
        if (lq<=l&&r<=rq) return st[pos];
        int m=(l+r)/2;
        node L=query(2*pos+1,l,m,lq,rq);
        node R=query(2*pos+2,m,r,lq,rq);
        return merge(L,R);
    }
    int query(int op,int lq,int rq){
        node res=query(0,0,sz,lq,rq);
        if (op==2) return res.sum;
        if (op==3) return res.pre;
        if (op==4) return res.suf;
    }
}ST;
int n,q;
void sol(){
    cin >>n>>q;
    vector<int> t(n);
    for (int i=0;i<n;i++)
        cin >>t[i];
    ST.init(n);
    ST.build(t);
    for (int i=0,op,k,x;i<q;i++){
        cin >>op;
        cin >>k>>x;
        if (op==1){
            ST.modify(k-1,x);
        }
        else {
            cout <<ST.query(op,k-1,x)<<'\n';
        }
        
    }
}
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}