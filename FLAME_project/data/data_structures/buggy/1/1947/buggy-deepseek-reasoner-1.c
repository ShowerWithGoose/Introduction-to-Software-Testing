#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ Missing return statement; should return after printing to avoid unnecessary loop.
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ Missing space between numbers; should be printf("%d ", a[i]);
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; 
            b[i] = 1; 
            FullArray(step + 1, n); 
            b[i] = 0; 
        }
    }
} 
int main()
{
    int n;
    scanf("%d", &n);
    FullArray(0,n);
    return 0;
}