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
dg(0,x); // @@ [Function 'dg' is used before it is declared or defined. In C, functions should be declared before use, or defined before main. Also, the logic inside dg is flawed for generating permutations of 1..N with spaces.]

return 0;
}
void dg(int m, int n) // @@ [The function definition appears after main without a prior declaration. Additionally, the parameter 'n' is used to track remaining depth, but the loop uses global 'x' which causes issues if not handled correctly. The main logical error is below.]
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans); // @@ [The output format is wrong. The problem requires integers separated by spaces (e.g., "1 2"), but this code prints characters concatenated (e.g., "12") because it stores digits in a char array and prints as string. It also lacks spaces between numbers.]
    return;
    }    
    
    
    
    
for(int i=1;i<=x;i++)    
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0'; // @@ [This converts integer i to its ASCII character representation. This approach fails for N > 9 (though N<=10 here, 10 is two digits) and does not allow for space separation easily. It treats the permutation as a string of digits rather than a sequence of integers.]
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}