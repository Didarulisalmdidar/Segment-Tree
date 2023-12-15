///Range Xor Queries
#include<bits/stdc++.h>
using namespace std;
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2 +1,en,nd+nd+1
const int maxx=200005;
int tree[4*maxx];
int ar[maxx+5];
void buildTree(int st,int en,int nd)
{
    if(st==en)
    {
        tree[nd]=ar[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd]=tree[nd+nd]^tree[nd+nd+1];


}
int getXor(int st,int en,int nd,int L ,int R)
{
    if(L<=st && en<=R)
        return tree[nd];
    if(en<L || R<st)
        return 0;
    return (getXor(left,L,R)^ getXor(right,L,R));
}

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    buildTree(1,n,1);
//    for(int i=1;i<=20;i++)
//        cout<<i<<" : "<<tree[i]<<"\n";
    while(q--)
    {

        int L,R;
        cin>>L>>R;
        cout<<getXor(1,n,1,L,R)<<"\n";
    }

}



