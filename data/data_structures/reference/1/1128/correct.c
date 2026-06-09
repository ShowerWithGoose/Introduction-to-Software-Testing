#include <stdio.h> 
int a[10000];
int b[10000];
int N; 
void pailie(int s)
{ 
   int i,k;
   if(s == N) 
    {
        for(k = 0; k < N; k++)
		{
       		printf("%d ", b[k]); 
   		}
       	 printf("\n");
	}
    else
    {
    	for(i=0;i<N;i++)
        { 
            if(!a[i])
            { 
                a[i] = 1; 
                b[s] = i + 1; 
                pailie(s + 1); 
                a[i] = 0; 
            } 
        } 
	}
} 
int main()
{ 	
    scanf("%d", &N); 
    pailie(0); 
} 


