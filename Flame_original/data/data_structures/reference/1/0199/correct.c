#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int a[11], flag[100];
void pailie(int bu1,int n)
{
    int i=0;;
    if (bu1==n+1)  
    {  
    i=1;
    while(i<=n){
    	printf("%d ",a[i]);
    	i++;
	}
        printf("\n");
        return;
    }
    for (i=1; i<=n; i++)
    {
        if (flag[i]==0)  
        {
            a[bu1]=i;  
            flag[i]=1;  
            pailie(bu1+1,n);  
            flag[i]=0;  
        }
    }
    return;
}

int main()
{
int n=0;
scanf("%d", &n); 
   pailie(1,n);  
}




