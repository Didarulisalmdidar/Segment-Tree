///Dynamic Range Sum Queries
/// Range sum-->> TC (NLOGN)

#include<bits/stdc++.h>
using namespace std;
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2 +1,en,nd+nd+1
const int maxx=200005;
long long tree[4*maxx];
long long ar[maxx+5];
void buildTree(int st,int en,int nd)
{
    if(st==en)
    {
        tree[nd]=ar[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd]=tree[nd+nd]+tree[nd+nd+1];


}
long long getSum(int st,int en,int nd,int L ,int R)
{
    if(L<=st && en<=R)
        return tree[nd];
    if(en<L || R<st)
        return 0;
    return (getSum(left,L,R)+ getSum(right,L,R));
}
void pointUpdate(int st,int en,int nd,int idx,int v)
{
    if(en<idx || idx<st)return;
    if(st==en)
    {
        tree[nd]=v;
        return;
    }
    pointUpdate(left,idx,v);
    pointUpdate(right,idx,v);
    tree[nd]=tree[nd+nd]+tree[nd+nd+1];
}
int main()
{
    int n,q,type;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&ar[i]);
    buildTree(1,n,1);
//    for(int i=1;i<=20;i++)
//        cout<<i<<" : "<<tree[i]<<"\n";
    while(q--)
    {
        scanf("%d",&type);

        if(type==2){
        int L,R;
        scanf("%d %d",&L,&R);
        printf("%lld\n",getSum(1,n,1,L,R));
        }
        else if(type==1)
        {
            long long idx,v;
            scanf("%lld %lld",&idx,&v);
            pointUpdate(1,n,1,idx,v);
        }
    }

}


