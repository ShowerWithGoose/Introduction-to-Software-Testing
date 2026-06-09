#include <stdio.h> 
int ins[15]={}; 
int last[15]; 
int N; 
 
void print()
{ 
    int i; 
    for(i = 0; i < N; i++)
	{
		printf("%d ", last[i]); 
  	}

    printf("\n"); 
} 
void cal(int step)
{ 
    int i; 
    if(step == N) 
    print(); 
    else
    { 
    	for(i = 0; i < N; i++)
        { 
            if(ins[i]!=1)
            { 
                ins[i] = 1; 
                last[step] = i + 1; 
                cal(step + 1); 
                ins[i] = 0; 
            } 
        } 
    } 
} 
 
int main()
{ 
        scanf("%d", &N); 
        cal(0); 
} 




