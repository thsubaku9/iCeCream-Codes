#include<stdio.h>
#include <stdlib.h>

struct queue
{int q[20]; 
int head;
int tail;};

struct queue qu;

void res(int x,int y,int *parent);
void bfs(int a,int b,int *visited,int vert,int **adj,struct queue *qu,int *parent);
void search(int x,int y,int *visited,int vert,int **adj,struct queue *qu,int *parent);

int main(void)
{
int v,i,j;
printf("Enter the number of vertices");
scanf("%d",&v);
//adj matrix
int **adj =(int **)malloc(sizeof(int *)*v);
for(i=0;i<v;i++)
{adj[i]=(int *)malloc(sizeof(int *)*v);}

//visited
int *visited =(int *)malloc(sizeof(int *)* v);
//parent
int *parent =(int *)malloc(sizeof(int *)* v);

for(i=0;i<v;i++)
{for(j=0;j<v;j++)
{printf("Enter values for vertices %d and %d",i,j);
scanf("%d",&adj[i][j]);}
visited[i]=0;
parent[i]=0;
}

int x,y;
printf("Enter the two nodes");
scanf("%d",&x);
scanf("%d",&y);
qu.head=0;
qu.q[qu.tail++]=x;
visited[x]=1;
search(x,y,visited,v,adj,&qu,parent);
printf("Completed");
res(x,y,parent);
}

void res(int x,int y,int *parent)
{printf("%d",y);
 int t1=y;
 while(parent[t1]!=x)
  {printf("%d",parent[t1]);t1=parent[t1];}
printf("%d",x);}

void bfs(int a,int b,int *visited,int vert,int **adj,struct queue *qu,int *parent)
{for(int z=0;z<vert;z++)
 {if(adj[a][z]!=0 && visited[z]==0)
  {qu->q[qu->tail]=z;qu->tail++;visited[z]=1;parent[z]=a;}}
}

void search(int x,int y,int *visited,int vert,int **adj,struct queue *qu,int *parent)
{int temp=x;
    while(qu->head <= qu->tail)
{if (temp == y){printf("Reached");break;}
        else{bfs(temp,y,visited,vert,adj,qu,parent);
	qu->head+=1;
	temp=qu->q[qu->head];}
}
}
