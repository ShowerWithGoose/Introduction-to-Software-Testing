 #include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

	int a[11], temp[100]={0}, N;

void func(int n)
{
    int i;
    if (n== N + 1)  
    {   
        for (i = 1; i <= N; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= N; i++)
    {
        if (temp[i] == 0)  
        {
            a[n] = i;  
            temp[i] = 1;  
            func(n + 1);  
            temp[i] = 0; 
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    func(1); 
	getchar();
    return 0;
}
	



