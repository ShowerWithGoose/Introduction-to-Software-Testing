#include<stdio.h>
#include<math.h>
#include<string.h>
#define eps 10e-10
#define GET_BIT(value, bit) (((value) >> bit) & 1)
int mark[10]={0};
char ans[11];
int x;



int main()
{
scanf("%d",&x);
dg(0,x); // @@ [Error: dg function is called before it is declared. The function definition appears after main, so a forward declaration is needed, or the function should be defined before main.]

return 0;
}
void dg(int m, int n)
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans); // @@ [Error: This prints permutations as a string without spaces between numbers, but the expected output requires spaces between each integer (e.g., "1 2" instead of "12").]
    return;
    }    
    
    
    
    
for(int i=1;i<=x;i++) // @@ [Error: The loop uses 'x' (which is the original N) instead of 'n' to control the range of numbers. Since x is incremented in the reference program but not here, this causes incorrect behavior. Also, the loop variable 'i' is redeclared with 'int' inside the for loop, conflicting with the earlier 'int i' declaration.]
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0'; // @@ [Error: This converts integer i to a character by adding '0', but only works for single-digit numbers (1-9). For N=10, this would produce incorrect characters.]
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}