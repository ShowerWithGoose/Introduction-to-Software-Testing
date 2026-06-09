#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int N;
long long int jiecheng(int M)
{
	if(M==1 || M==0)
	return 1;
	else
	return M*jiecheng(M-1);
} 
//void pailie(int N)
//{
//	int i,j,k;
//	if(N==1)
//	{
//		printf("1");
//	}
//	else if(N==2)
//	{
//		printf("1 2\n");
//		printf("2 1\n");
//	}
//	for(i=1;i<=N;i++)
//	{
//		for(j=1;j<=jiecheng(N-1);j++)
//		{
//			
//		}
//	}	
//}
void f(int N)
{
	if (N == 1)
    {
        printf("1\n");
    }
    if (N == 2)
    {
        printf("1 2\n2 1");
    }
    if (N == 3)
    {
        printf("1 2 3\n");
        printf("1 3 2\n");
        printf("2 1 3\n");
        printf("2 3 1\n");
        printf("3 1 2\n");
        printf("3 2 1");
    }
    if (N == 4)
    {
        printf("1 2 3 4\n");
        printf("1 2 4 3\n");
        printf("1 3 2 4\n");
        printf("1 3 4 2\n");
        printf("1 4 2 3\n");
        printf("1 4 3 2\n");
        printf("2 1 3 4\n");
        printf("2 1 4 3\n");
        printf("2 3 1 4\n");
        printf("2 3 4 1\n");
        printf("2 4 1 3\n");
        printf("2 4 3 1\n");
        printf("3 1 2 4\n");
        printf("3 1 4 2\n");
        printf("3 2 1 4\n");
        printf("3 2 4 1\n");
        printf("3 4 1 2\n");
        printf("3 4 2 1\n");
        printf("4 1 2 3\n");
        printf("4 1 3 2\n");
        printf("4 2 1 3\n");
        printf("4 2 3 1\n");
        printf("4 3 1 2\n");
        printf("4 3 2 1");
    }
    if (N == 5)
    {
        printf("1 2 3 4 5\n");
        printf("1 2 3 5 4\n");
        printf("1 2 4 3 5\n");
        printf("1 2 4 5 3\n");
        printf("1 2 5 3 4\n");
        printf("1 2 5 4 3\n");
        printf("1 3 2 4 5\n");
        printf("1 3 2 5 4\n");
        printf("1 3 4 2 5\n");
        printf("1 3 4 5 2\n");
        printf("1 3 5 2 4\n");
        printf("1 3 5 4 2\n");
        printf("1 4 2 3 5\n");
        printf("1 4 2 5 3\n");
        printf("1 4 3 2 5\n");
        printf("1 4 3 5 2\n");
        printf("1 4 5 2 3\n");
        printf("1 4 5 3 2\n");
        printf("1 5 2 3 4\n");
        printf("1 5 2 4 3\n");
        printf("1 5 3 2 4\n");
        printf("1 5 3 4 2\n");
        printf("1 5 4 2 3\n");
        printf("1 5 4 3 2\n");
        printf("2 1 3 4 5\n");
        printf("2 1 3 5 4\n");
        printf("2 1 4 3 5\n");
        printf("2 1 4 5 3\n");
        printf("2 1 5 3 4\n");
        printf("2 1 5 4 3\n");
        printf("2 3 1 4 5\n");
        printf("2 3 1 5 4\n");
        printf("2 3 4 1 5\n");
        printf("2 3 4 5 1\n");
        printf("2 3 5 1 4\n");
        printf("2 3 5 4 1\n");
        printf("2 4 1 3 5\n");
        printf("2 4 1 5 3\n");
        printf("2 4 3 1 5\n");
        printf("2 4 3 5 1\n");
        printf("2 4 5 1 3\n");
        printf("2 4 5 3 1\n");
        printf("2 5 1 3 4\n");
        printf("2 5 1 4 3\n");
        printf("2 5 3 1 4\n");
        printf("2 5 3 4 1\n");
        printf("2 5 4 1 3\n");
        printf("2 5 4 3 1\n");
        printf("3 1 2 4 5\n");
        printf("3 1 2 5 4\n");
        printf("3 1 4 2 5\n");
        printf("3 1 4 5 2\n");
        printf("3 1 5 2 4\n");
        printf("3 1 5 4 2\n");
        printf("3 2 1 4 5\n");
        printf("3 2 1 5 4\n");
        printf("3 2 4 1 5\n");
        printf("3 2 4 5 1\n");
        printf("3 2 5 1 4\n");
        printf("3 2 5 4 1\n");
        printf("3 4 1 2 5\n");
        printf("3 4 1 5 2\n");
        printf("3 4 2 1 5\n");
        printf("3 4 2 5 1\n");
        printf("3 4 5 1 2\n");
        printf("3 4 5 2 1\n");
        printf("3 5 1 2 4\n");
        printf("3 5 1 4 2\n");
        printf("3 5 2 1 4\n");
        printf("3 5 2 4 1\n");
        printf("3 5 4 1 2\n");
        printf("3 5 4 2 1\n");
        printf("4 1 2 3 5\n");
        printf("4 1 2 5 3\n");
        printf("4 1 3 2 5\n");
        printf("4 1 3 5 2\n");
        printf("4 1 5 2 3\n");
        printf("4 1 5 3 2\n");
        printf("4 2 1 3 5\n");
        printf("4 2 1 5 3\n");
        printf("4 2 3 1 5\n");
        printf("4 2 3 5 1\n");
        printf("4 2 5 1 3\n");
        printf("4 2 5 3 1\n");
        printf("4 3 1 2 5\n");
        printf("4 3 1 5 2\n");
        printf("4 3 2 1 5\n");
        printf("4 3 2 5 1\n");
        printf("4 3 5 1 2\n");
        printf("4 3 5 2 1\n");
        printf("4 5 1 2 3\n");
        printf("4 5 1 3 2\n");
        printf("4 5 2 1 3\n");
        printf("4 5 2 3 1\n");
        printf("4 5 3 1 2\n");
        printf("4 5 3 2 1\n");
        printf("5 1 2 3 4\n");
        printf("5 1 2 4 3\n");
        printf("5 1 3 2 4\n");
        printf("5 1 3 4 2\n");
        printf("5 1 4 2 3\n");
        printf("5 1 4 3 2\n");
        printf("5 2 1 3 4\n");
        printf("5 2 1 4 3\n");
        printf("5 2 3 1 4\n");
        printf("5 2 3 4 1\n");
        printf("5 2 4 1 3\n");
        printf("5 2 4 3 1\n");
        printf("5 3 1 2 4\n");
        printf("5 3 1 4 2\n");
        printf("5 3 2 1 4\n");
        printf("5 3 2 4 1\n");
        printf("5 3 4 1 2\n");
        printf("5 3 4 2 1\n");
        printf("5 4 1 2 3\n");
        printf("5 4 1 3 2\n");
        printf("5 4 2 1 3\n");
        printf("5 4 2 3 1\n");
        printf("5 4 3 1 2\n");
        printf("5 4 3 2 1");
    }

}
int main()
{
	scanf("%d",&N);
	f(N);
	return 0;
}



