#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 2e18
#define maxn 100005
#define mod 1000000007
#define debug(x) cerr<<#x<<"is"<<x<<endl

struct order{
    int start,finish,value,index;
}orderlist[maxn];

bool cmp(order a,order b){
    return a.finish<b.finish;
}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    int dp[maxn];
    dp[0]=0;
    int prev[maxn];
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(prev,0,sizeof(prev));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int duration;
            cin>>orderlist[i].start>>duration>>orderlist[i].value;
            orderlist[i].finish=orderlist[i].start+duration;
        }
        sort(orderlist+1,orderlist+n+1,cmp);
        for(int i=1;i<=n;i++){
            orderlist[i].index=i;
        }
        for(int i=n;i>0;i--){
            for(int j=n-1;j>0;j--){
                if(orderlist[j].finish<=orderlist[i].start){
                    prev[i]=orderlist[j].index;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            dp[i]=max(dp[i-1],dp[prev[i]]+orderlist[i].value);
        }
        cout<<dp[n]<<endl;
    }
}
