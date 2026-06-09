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
dg(0,x); // @@ [Error: Function 'dg' is used before it is declared or defined. In C, functions should be declared before use, or defined before main. Also, the logic inside dg is flawed for generating permutations of 1..N with spaces.]

return 0;
}
void dg(int m, int n) // @@ [Error: The function definition appears after main without a prior declaration. Additionally, the parameter 'n' is decremented but the loop condition uses global 'x', and the base case 'n==0' prints the string. The major issue is that the problem requires space-separated integers, but this code constructs a string of characters. For N>9, 'i'+'0' will not produce correct output. For N<=9, it produces digits without spaces, e.g., "12" instead of "1 2".]
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans); // @@ [Error: This prints the permutation as a continuous string of characters (e.g., "12") instead of space-separated integers (e.g., "1 2"). The expected output format requires spaces between numbers.]
    return;
    }    
    
    
    
    
for(int i=1;i<=x;i++)     // @@ [Error: The loop runs from 1 to x. While this iterates through the numbers, the recursion depth and marking logic need to ensure exactly N numbers are picked. The variable 'n' controls depth, which is correct, but the output format is wrong.]
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0'; // @@ [Error: This converts the integer i to a single character digit. This only works for i < 10. More importantly, it does not add spaces between numbers. To match the expected output "1 2 ", we need to print integers with spaces, not concatenate characters into a string without separators.]
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}