#include<stdio.h>
#include <stdlib.h>

struct stack
{int s[20]; 
 int top;};

struct stack st;
void res(int x,int y,struct stack *st);
void dfs(int x,int y,int *visited,int vert,int **adj,struct stack *st);
void search(int x,int y,int *visited,int vert,int **adj,struct stack *st);

int main(void)
{ 
int v,i,j;
st.top=0;
printf("Enter the number of vertices");
scanf("%d",&v);

int **adj=(int **)malloc(sizeof(int *)*v);
for(i=0;i<v;i++)
{adj[i]=(int *)malloc(sizeof(int *)*v);}

int *visited=(int *)malloc(sizeof(int *)* v);

for(i=0;i<v;i++)
{for(j=0;j<v;j++)
{printf("Enter values for vertices %d and %d",i,j);
scanf("%d",&adj[i][j]);}
visited[i]=0;
}

int x,y;
printf("Enter the two nodes");
scanf("%d",&x);
scanf("%d",&y);
visited[x]=1;
st.s[st.top++]=x;
printf("assigned it");
search(x,y,visited,v,adj,&st);
printf("Completed");
res(x,y,&st);
}


void res(int x,int y,struct stack *st)
{
int t1=st->top;
while(t1)
{printf("%d",st->s[t1]);t1--;}
}

void dfs(int x,int y,int *visited,int vert,int **adj,struct stack *st)
{for(int z=0;z<vert;z++)
{if (adj[x][z]!=0 && visited[z]==0)
{st->s[st->top++]=z;
visited[z]=1;break;}
else if(z==vert-1){st->top=st->top-1;}
}
}

void search(int x,int y,int *visited,int vert,int **adj,struct stack *st)
{int temp=x;
 while(temp!=y)
{dfs(temp,y,visited,vert,adj,st);
temp=st->s[st->top-1];}
printf("Reached");
}

