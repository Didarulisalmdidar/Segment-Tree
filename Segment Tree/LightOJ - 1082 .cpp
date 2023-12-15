///Array Queries

#include<bits/stdc++.h>
using namespace std;
#define left st,(st+en)/2,nd+nd
#define right (st+en)/2+1,en,nd+nd+1
const int MAX=100000;
int tree[MAX*4];
int ar[MAX+5];

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


int getRangeMin(int st,int en,int nd,int L,int R)
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
    int t;
    scanf("%d",&t);
    //printf("\n");
    int tc=1;
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        memset(ar,0,sizeof(ar));
        memset(tree,0,sizeof(tree));

        for(int i=1; i<=n; i++)
            scanf("%d",&ar[i]);

        cout<<"Case "<<tc<<":"<<"\n";
        tc++;

        buildTree(1,n,1);
        vector<int>v;

        while(q--)
        {

            int L,R;
            cin>>L>>R;
            printf("%d\n",getRangeMin(1,n,1,L,R));
        }
    }

}



