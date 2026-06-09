#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num[101]={0};
	int end=0;
	int n=0,k=0;
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:
			{
				if(end==100)
				{
					printf("error ");
					break;
				}
			scanf("%d",&k);
			num[end]=k;
			end++;
				break;
			}
			case 0:
				{
					if(end==0)
					{
						printf("error ");
						break;
					}
					printf("%d ",num[end-1]);
					end--;
					break;
				}
			case -1:
				return 0;
		}
	}
	return 0;
}

