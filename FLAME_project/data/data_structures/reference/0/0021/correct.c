#include<stdio.h>
#include<string.h>
char ch[1000000];
char bh[1000000];
int main()
{
	int i, k = 0, j;
	scanf("%s", ch);
	for(i = 0; i < strlen(ch); i++)
	{
		if(ch[i] == '-')
		{
			if(((ch[i - 1] >= 'a' && ch[i + 1] <= 'z') || (ch[i - 1] >= 'A' && ch[i + 1] <= 'Z') || (ch[i - 1] >= '0' && ch[i + 1] <= '9') )&& ch[i + 1] > ch[i - 1])
			{
				int j=1;
				k = 0;
				bh[k] = ch[i - 1];
				k++;
				while(bh[k - 1] < ch[i + 1]-1)
				{
					bh[k] = ch[i - 1] + j;
					printf("%c",bh[k]);
					j++;
					k++;
				}
			}
			else
			{
				printf("%c", ch[i]);
			}
		}
		else
		{
			//bh[k++] = ch[i];
			printf("%c",ch[i]);
		}
	}
/*	if(bh != '\0')
		{
			puts(bh);
		}
		*/
	return 0;
} 

