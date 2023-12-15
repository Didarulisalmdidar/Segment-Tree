/// Dynamic Range Minimum Queries
#include<bits/stdc++.h>
using namespace std;
#define left st,(st+en)/2,nd+nd
#define right (st+en)/2+1,en,nd+nd+1
const int MAX=200005;
long long tree[MAX*4];
long long ar[MAX+5];

void buildTree(int st,int en,int nd)
{
    if(st==en)
    {
        tree[nd]=ar[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd]=min(tree[nd+nd],tree[nd+nd+1]);
}
void pointUpdate(int st,int en,int nd,int idx,int v)
{
    if(en<idx || idx<st)
        return;
        if(st==en)
        {
            tree[nd]=v;
            return;
        }
    pointUpdate(left,idx,v);
    pointUpdate(right,idx,v);
    tree[nd]=min(tree[nd+nd],tree[nd+nd+1]);
}

long long  getRangeMin(int st,int en,int nd,int L,int R)
{
    if(L<=st && en<=R)
    {
        return tree[nd];
    }
    if(en<L || R<st)
        return INT_MAX/2;
    return min(getRangeMin(left,L,R),getRangeMin(right,L,R));

}

int main()
{
    int n,q,type;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    buildTree(1,n,1);
//    for(int i=1;i<=20;i++)
//        cout<<i<<" : "<<tree[i]<<"\n";
    while(q--)
    {
        scanf("%d",&type);
        if(type==2){
        int L,R;
        cin>>L>>R;
        printf("%lld\n",getRangeMin(1,n,1,L,R));
        }
        else if(type==1)
        {
            int idx,v;
            scanf("%d %d",&idx,&v);
            pointUpdate(1,n,1,idx,v);
        }
    }
}



