#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"
typedef struct
{
    int num[100],bnum[100][100];
} map;
int x2(int*,int);
void ano(int*,int);
int main()
{
    map *hcube;
    hcube=malloc(sizeof(map));
    int a=1,n,b,i,j,num[100],c=0,time1,ans,A[100],dfs[100][100],test[100];
    int root,k=0,l,x,root1,y;
    scanf("%d %d",&n,&root1);
    n=pow(2,n);
    while(n>a)
    {
        a*=2;
        c++;
    }
    for(i=0; i<n; i++)
    {
        hcube->num[i]=i;
        b=i;
        for(j=c-1; j>=0; j--)
        {
            hcube->bnum[i][j]=b%2;
            b/=2;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<c; j++)
        {
            for(k=0; k<c; k++)
                A[k]=hcube->bnum[i][k];
            ano(A,c-1-j);
            ans=x2(A,c);
            dfs[i][j]=ans;

        }
    }
    k=0;
    root=root1;
    test[k]=root;
    k++;
    x=0;
    while(k<n)
    {
        for(j=0; j<c; j++)
        {
            for(l=0; l<k; l++)
            {
                if(dfs[root][j]==test[l])
                    x++;
            }
            if(x==0)
            {
                test[k]=dfs[root][j];
                root=dfs[root][j];
                k++;
                x=0;
                break;
            }
            x=0;
        }
    }
    printf("dfs start from %d\n",root1);
    for(i=0;i<n;i++)
        printf("%d ",test[i]);
        printf("\n");
        memset(test,0,sizeof(test));

        k=0;
    root=root1;
    test[k]=root;
    k++;
    x=0;
    y=1;
    while(k<n)
    {
        for(j=0; j<c; j++)
        {
            for(l=0; l<k; l++)
            {
                if(dfs[root][j]==test[l])
                    x++;
            }
            if(x==0)
            {
                test[k]=dfs[root][j];
                k++;
                x=0;
            }
            x=0;
        }
        root=test[y];
        y++;
    }
    printf("bfs start from %d\n",root1);
    for(i=0;i<n;i++)
        printf("%d ",test[i]);
        printf("\n");

    return 0;
}


