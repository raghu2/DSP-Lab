#include <stdio.h>
#include <stdlib.h>
int arr[10][10];
int nodes,ind=0;
int count=0;
int IsInPath(int (*path)[10],int r,int c)
{
    if(path[r][c]==0)   return 0;
    else    return 1;
}
int isValid(int r,int c)
{
    if((r>=0 && r<=nodes-1) && (c>=0 && c<=nodes-1))
        return 1;
    else
        return 0;
}
void findPath(int (*path)[10],int r,int c)
{
    int path2[10][10];
    int i,j;
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
            path2[i][j]=0;
    if(arr[r][c]==2)
    {
        count=1;
	exit;
    }
    else if(arr[r][c]==0 || (arr[r][c]==3 && IsInPath(path,r,c)))
    {
        return;
    }
    else if((arr[r][c]==3 && !IsInPath(path,r,c)) || arr[r][c]==1)
    {
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
                path2[i][j]=path[i][j];
        path2[r][c]=1;
        if(isValid(r,c-1))          findPath(path2,r,c-1);
        if(isValid(r-1,c))          findPath(path2,r-1,c);
        if(isValid(r,c+1))          findPath(path2,r,c+1);
        if(isValid(r+1,c))          findPath(path2,r+1,c);
    }
}
int main()
{
    int i,j,flag=0;
    int path[10][10];
    printf("enter number of nodes\n");
    scanf("%d",&nodes);
    printf("enter a %d * %d matrix path\n",nodes,nodes);
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
            scanf("%d",&path[i][j]);
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            if(arr[i][j]==1)
            {
                findPath(path,i,j);
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }
    if(count==1)
    printf("Yes\n");
	else printf("No\n");
    return 0;
}
