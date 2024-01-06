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
//#pragma GCC optimize("Ofast","inline","-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long LL;
const int N=5005;
const int M=505;
// const int MOD=998244353;//1000000007;
const LL INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;


int n,tot;
vector<int> e[N],orge[N];
vector<int> order[N],res[N];
int fa[N],deg[N],bln[N];
pii a[N];
pair<char,int> orgc[N],c[N];
int isInfinite=0,isInfinite_v=0;
int calc(int val,pii x){
    return val*x.fi+x.se;
}
void HAHAHAITISINFINITE(){
    cout <<"infinite\n";
    for (int i=1;i<=n;i++)
        for (int x:res[i])
            cout <<x<<' ';
    cout <<'\n';
}
void dfs(int v,vector<int> &t){
    if (orgc[v].fi=='x') return;
    t.pb(v);
    for (int i:orge[v]){
        dfs(i,t);
    }
}
void sol(){
    cin >>n;
    tot=isInfinite=isInfinite_v=0;
    for (int i=0;i<=n;i++){
        e[i].clear();
        orge[i].clear();
        order[i].clear();
        res[i].clear();
        bln[i]=deg[i]=0;
    }
    for (int i=1,x;i<=n;i++){
        cin >>fa[i];
        orge[fa[i]].pb(i);
    }
    for (int i=1;i<=n;i++) {
        cin >>orgc[i].fi>>orgc[i].se;
        if (orgc[i].fi=='x'&&orgc[i].se==1)
            orgc[i].fi='+',orgc[i].se=0;
    }
    int cc=(orgc[1].fi=='+'?1+orgc[1].se:orgc[1].se); orgc[1]={'+',0};
    for (int i=1;i<=n;i++){
        if (!bln[i]){
            tot++;
            if (orgc[i].fi=='x'){
                c[tot]=orgc[i];
                bln[i]=tot;
                res[tot].pb(i);
            }
            else{    
                vector<int> tmp;
                dfs(i,tmp);
                for (int x:tmp)
                    bln[x]=tot;
                
                    c[tot]={'+',0};
                    for (int x:tmp)
                        c[tot].se+=orgc[x].se;
                
                res[tot]=tmp;
            }
        }
    }
    //cerr<<tot<<'\n';
    for (int i=1;i<=n;i++){
        for (int v:orge[i]){
            if (bln[v]!=bln[i])
                e[bln[i]].pb(bln[v]),fa[bln[v]]=bln[i];
        }
    }
    for (int i=1;i<=tot;i++) deg[i]=e[i].size();//,cerr <<deg[i]<<' ';
    n=tot;
    for (int i=1;i<=n;i++){
        if (c[i].fi=='+')
            a[i]={1,c[i].se};
        else a[i]={c[i].se,0};
        order[i].pb(i);
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (deg[i]==0)
            q.push(i);
    }
    while (q.size()){
        int v=q.front(); q.pop();
        //cerr<<v<<' ';
        deg[fa[v]]--;
        if (deg[fa[v]]==0&&fa[v]!=0) q.push(fa[v]);

        vector<vector<int>> tmp;
        for (int i:e[v])
            tmp.pb(order[i]);
        if (tmp.size()==0){
            continue;
        }
        if (tmp.size()==1){
            for (int i:tmp[0])
                order[v].pb(i);
            continue;
        }
        vector<int> mrg=tmp[0];
        for (int i=1;i<tmp.size();i++){
            int nn=mrg.size();
            int mm=tmp[i].size();
            // cerr<<nn<<' '<<mm<<'\n';
            // for (int x:mrg) cerr<<x<<' '; cerr<<'\n';
            
            
            vector<int> bbb=tmp[i];
            //for (int x:bbb) cerr<<x<<' '; cerr<<'\n';
            vector<vector<int>> dp(nn+1,vector<int>(mm+1));
            vector<vector<int>> pre(nn+1,vector<int>(mm+1));
            dp[1][0]=calc(1,a[mrg[0]]); pre[1][0]=1;
            dp[0][1]=calc(1,a[bbb[0]]); pre[0][1]=2;
        
            for (int j=1;j<nn;j++){
                dp[j+1][0]=calc(dp[j][0],a[mrg[j]]),pre[j+1][0]=1;
                if (dp[j+1][0]>=1E18){
                    HAHAHAITISINFINITE();
                    return;
                }
            }
            for (int j=1;j<mm;j++){
                dp[0][j+1]=calc(dp[0][j],a[bbb[j]]),pre[0][j+1]=2;
                if (dp[0][j+1]>=1E18){
                    HAHAHAITISINFINITE();
                    return;
                }
            }
            for (int x=1;x<=nn;x++){
                for (int y=1;y<=mm;y++){
                    if (calc(dp[x-1][y],a[mrg[x-1]])>calc(dp[x][y-1],a[bbb[y-1]])){
                        pre[x][y]=1;
                        dp[x][y]=calc(dp[x-1][y],a[mrg[x-1]]);
                        if (dp[x][y]>=1E18) {HAHAHAITISINFINITE();return;}
                    }
                    else{
                        pre[x][y]=2;
                        dp[x][y]=calc(dp[x][y-1],a[bbb[y-1]]);
                        if (dp[x][y]>=1E18) {HAHAHAITISINFINITE();return;}
                    }
                }
                if (isInfinite) {
                    {HAHAHAITISINFINITE();return;}
                }
            }
            if (isInfinite) {
                {HAHAHAITISINFINITE();return;}
            }
            vector<int> New;
            int x=nn,y=mm;
            for (int times=0;times<x+y;times++){
                if (pre[nn][mm]==1){
                    New.pb(mrg[--nn]);
                }
                else New.pb(bbb[--mm]);
            }
            //for (int x:New) cerr<<x<<' '; cerr<<'\n';
            mrg=New;
            reverse(ALL(mrg));
        }
        for (int i:mrg)
            order[v].pb(i);
        if (isInfinite) {
            {HAHAHAITISINFINITE();return;}
            break;
        }
    }

    //cerr<<'\n';
    
    for (int i:order[1]){
        cc=calc(cc,a[i]);
        if (cc>=1E18) {HAHAHAITISINFINITE();return;}
    }
    if (!isInfinite) {
        cout <<cc<<'\n';
        for (int i:order[1]){
            for (int x:res[i])
                cout <<x<<' ';   
        }
    }   
    else {
        cout <<"infinite\n";
        for (int i=1;i<=n;i++)
            for (int x:res[i])
                cout <<x<<' ';
    }
    cout <<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    //srand(time(NULL));
    int _=1;
    cin >>_;
    while (_--) sol();
    return 0;
}

/*
sort(ALL(vc),[](I lh, I rh){
    return lh.mul*rh.add+lh.add<rh.mul*lh.add+rh.add;
});

1
6
0 1 1 1 2 2
x 2
x 2
x 5
+ 1
+ 4
+ 1
*/