#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ [The base case should trigger when step > n or step == n+1 because the recursion starts at step=0 and fills a[step+1]. As written, it stops one step early, producing permutations of length n-1 instead of n. Also, for n=2, this condition becomes true when step=2, but a[1] and a[2] are set only when step=0 and step=1, so a[2] is never set before printing.]
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ [Missing space between numbers as required by the output format. Should be "%d " instead of "%d".]
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; // @@ [Because the initial call uses step=0, this writes to a[1] first, which is okay, but combined with the incorrect base case (step == n), the last element a[n] is never assigned before printing when step reaches n. The logic is off-by-one.]
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
    FullArray(0,n); // @@ [Starting with step=0 causes an off-by-one error in indexing relative to the base case condition. The reference program starts with step=1 and checks step > n. Here, starting at 0 and checking step == n leads to incomplete permutation generation.]
    return 0;
}