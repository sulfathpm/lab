#include<stdio.h>
#include<stdlib.h>
#define INF 9999
#define MAX 100
void prims(int cost[MAX][MAX],int n,int t[MAX][2]){
    int near[MAX];
    int i,j,k=0,l=0,min,mincost=0;
    min=INF;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(cost[i][j]<min && i!=j){
                min=cost[i][j];
                k=i;
                l=j;
            }
        }
    }

    t[1][0]=k;
    t[1][1]=l;
    min=cost[k][l];

    for(i=1;i<=n;i++){
        if(cost[i][l]<cost[i][k]){
            near[i]=l;
        }else{
            near[i]=k;
        }
    }
    near[k]=near[l]=0;

    for(i=2;i<n;i++){
        min=INF;
        int next=0;
        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][near[j]]<min){
                min=cost[j][near[j]];
                next=j;
            }
        }
        t[i][0]=next;
        t[i][1]=near[next];
        mincost+=cost[next][near[next]];
        near[next]=0;
        for(k=1;k<=n;k++){
            if(near[k]!=0 && cost[k][near[k]]>cost[k][next]);
            {
                near[k]=next;
            }
        }
    }

    printf("\nMinimum cost spanning tree edges : \n");
    for(i=1;i<n;i++){
        printf("( %d \t %d )\n",t[i][0],t[i][1]);
    }
    printf("Total minimum cost : %d\n",mincost);
}

int main(){
    int n,i,j;
    int cost[MAX][MAX],t[MAX][2];
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix (9999 for no edge) : ");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    prims(cost,n,t);
    return 0;
}

