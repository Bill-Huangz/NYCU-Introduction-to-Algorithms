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
#define DNE NULL
//#define mul(a,b,c) (a%c)*(b%c)%c
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=200005;
const int M=1000005;
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

struct Seg{
    struct Node{
        Node *ls,*rs;
        int cnt;
        int exi;
        Node (){
            ls=rs=DNE;
            cnt=exi=0;
        }
    } *rt=new Node();
    
    Node *merge(Node *v){
        if (v->ls==DNE) {
            v->exi=v->rs->exi;
            v->cnt=v->rs->cnt;
        }
        else if (v->rs==DNE) {
            v->exi=v->ls->exi;
            v->cnt=v->ls->cnt;    
        }
        else {
            v->exi=v->ls->exi+v->rs->exi;
            v->cnt=v->ls->cnt+v->rs->cnt;
        }
        return v;
    }
    Node *modify(Node *v,int x,int val,int l,int r){
        if (v==DNE) v=new Node();
        //cerr <<l<<" "<<r<<'\n';
        assert(v!=NULL);
        if (r-l==1){
            v->cnt+=val;
            if (val==1&&v->cnt==1) v->exi=1;
            if (val==-1&&v->cnt==0) v->exi=0;
            return v;
        }
        int m=(l+r)/2;
        if (x<m) v->ls=modify(v->ls,x,val,l,m);
        else v->rs=modify(v->rs,x,val,m,r);
        v=merge(v);
        return v;
    }
    void modify(int x,int val){
        rt=modify(rt,x,val,0,1000000005);
    }
    int query1(Node *v,int l,int r){
        if (r-l==1) return l;
        //cerr<<l<<' '<<r<<'\n';
        assert(v!=NULL);
        int m=(l+r)/2;
        if (v->ls!=DNE&&v->ls->cnt!=0) return query1(v->ls,l,m);
        else return query1(v->rs,m,r);
    }
    int query1(){
        return query1(rt,0,1000000005);
    }
    int query2(Node *v,int l,int r){
        if (r-l==1) return l;
        int m=(l+r)/2;
        if (v->rs==DNE||v->rs->cnt==0) return query2(v->ls,l,m);
        else return query2(v->rs,m,r);
    }
    int query2(){
        return query2(rt,0,1000000005);
    }
    int query3(Node *v,int l,int r){
        if (r-l==1||v==NULL) return l;
        int m=(l+r)/2;
        if (v->ls!=DNE&&v->ls->exi==m-l) return query3(v->rs,m,r);
        else return query3(v->ls,l,m); 
    }
    int query3(){
        return query3(rt,0,1000000005);
    }
};

int n,Q;
int a[N];
void sol(){
    cin >>n>>Q;
    int MX=1000000005;
    Seg tr;
    for (int i=0,x;i<n;i++){
        cin >>x;
        tr.modify(x,1);
    }
    for (int i=0,x;i<Q;i++){
        cin >>x;
        if (x==1){
            int t=tr.query1();
            cout <<t<<"\n";
            tr.modify(t,-1);
        }
        if (x==2){
            int t=tr.query2();
            cout <<t<<"\n";
            tr.modify(t,-1);
        }
        if (x==3){
            int t=tr.query3();
            cout <<t<<'\n';
            tr.modify(t,1);
        }
    }
}
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine
    //srand(time(NULL));
    int _=1;
    //cin >>_;
    
    while (_--) sol();
    //while (cin >>n&&n) sol();

    return 0;
}