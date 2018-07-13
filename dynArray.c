#include <stdio.h>
#include <stdlib.h>
void main()
{   
    int n=1;
    int *a;
    int *b;
    int abuse;
    b=(int*)malloc(sizeof(int)*n);
    a=(int*)malloc(sizeof(int)*n);
    
    
    while(n<10)
    {printf("Loop number n %d\n",n-1);
    
    if(n<2)
    {printf("value for %d ",n-1);scanf("%d ",&b[n-1]);n+=1;continue;}
    
    else
    {
    a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n-1;i++)
    {a[i]=b[i];}
    
    b=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n-1;i++)
    {a[i]=b[i];}
    
    printf("value for %d ",n-1);
    scanf("%d ",&b[n-1]);
    }
    n+=1;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("Position at value %d is %d",i,b[i]);
    }

}
