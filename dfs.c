#include<stdio.h>
#define MAX 100

int stack[MAX],top=-1;

void push(int value){
    if(top==MAX-1){
        printf("\nStack overflow\n");
    }
    stack[++top]=value;
}

int pop(){
    if(top==-1){
        printf("\nStack underflow\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty(){
    return (top==-1);
}

void dfs(int adj[MAX][MAX],int vertices,int start){
    int visited[MAX]={0};
    push(start);
    printf("\nDFS traversal: \n");
    while(!isEmpty()){
        int current=pop();
        if(!visited[current]){
            printf(" %d ",current);
            visited[current]=1;
            for(int i=vertices-1;i>=0;i--){
                if(adj[current][i]==1&&!visited[i]){
                    push(i);
                }
            }
        }
    }
    printf("\n");
}

int main(){
    int adj[MAX][MAX],vertices,start;
    printf("\nEnter the number of vertices : \n");
    scanf("%d",&vertices);
    printf("\nEnter the adjacent matrices ( %d x %d ) : \n",vertices,vertices);
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
           scanf("%d",&adj[i][j]); 
        }
    }
    printf("\nEnter the starting vertex ( 0 - %d ) : \n",vertices-1);
    scanf("%d",&start);
    dfs(adj,vertices,start);
    return 0;
}
