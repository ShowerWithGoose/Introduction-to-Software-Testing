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
dg(0,x); // @@ [Function dg is called before its declaration; this may cause compilation issues or undefined behavior in some compilers, though not the primary cause of wrong output]

return 0;
}
void dg(int m, int n)
{
int i;
if(n==0)
    {
    ans[m]='\0';
    printf("%s\n",ans); // @@ [This prints the permutation as a concatenated string of digits without spaces, but the expected output requires space-separated integers]
    return;
    }    
    
    
    
    
for(int i=1;i<=x;i++)    
if(mark[i]==0)
{
    mark[i]=1;
    ans[m]=i+'0'; // @@ [Storing characters instead of integers prevents proper space-separated output; also, array 'mark' has size 10, but for x=10, mark[10] would be out-of-bounds since indices go from 0 to 9]
    dg(m+1,n-1);
    mark[i]=0;
    
    
}
    
    
    
    
}