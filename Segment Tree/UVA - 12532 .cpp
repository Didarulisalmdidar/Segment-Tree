/// Interval Product

#include<bits/stdc++.h>
using namespace std;
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2 +1,en,nd+nd+1
const int maxx=100005;
int tree[4*maxx];
int ar[maxx+5];
void buildTree(int st,int en,int nd)
{
    if(st==en)
    {
        if(ar[st]==0)
        {
            tree[nd]=0;
        }
        else if(ar[st]>0)
            tree[nd]=1;
        else
            tree[nd]=-1;
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd]=tree[nd+nd]*tree[nd+nd+1];


}
long long getProduct(int st,int en,int nd,int L,int R)
{
    if(L<=st && en<=R)
        return tree[nd];
    if(en<L || R<st)
        return 1;
    return (getProduct(left,L,R)* getProduct(right,L,R));
}
void pointUpdate(int st,int en,int nd,int idx,int v)
{
    if(en<idx || idx<st)
        return;
    if(st==en)
    {
       if(v==0)
        tree[nd]=0;
       else if(v>0)
        tree[nd]=1;
       else
        tree[nd]=-1;
        return;
    }
    pointUpdate(left,idx,v);
    pointUpdate(right,idx,v);
    tree[nd]=tree[nd+nd]*tree[nd+nd+1];
}
int main()
{
    int n,q;
    while(scanf("%d %d",&n,&q)==2){
    memset(ar,0,sizeof(ar));
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=n;i++)
        scanf("%d",&ar[i]);
    buildTree(1,n,1);
//    for(int i=1;i<=20;i++)
//        cout<<i<<" "<<tree[i]<<endl;
      string ans="";
     while(q--)
     {
         char ch;
         cin>>ch;
         if(ch=='C')
         {
             int idx,v;
             scanf("%d %d",&idx,&v);
             pointUpdate(1,n,1,idx,v);
         }
         else if(ch=='P')
         {
             int L,R;
             scanf("%d %d",&L,&R);
             int res=getProduct(1,n,1,L,R);
             if(res==0)
                ans+='0';
             else if(res>0)
                ans+='+';
             else
                ans+='-';
         }
     }
     cout<<ans<<endl;
    }



}







