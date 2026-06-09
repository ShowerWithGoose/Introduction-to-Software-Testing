#include<stdio.h>
#include<string.h>
struct ex
{
	char str[100];
	int n;
}str1[100], t;
int main()
{
	int i = 0, j = 0, k = 0, flag = 0;
	int len_ex=0;
	FILE *fp1;
	fp1 = fopen("article.txt", "r");
	char ch;
	char str2[100];
	
	while((ch = fgetc(fp1))!= EOF)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			ch = 'a' + ch - 'A';
			str2[i] = ch;
			i++; 
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			str2[i] = ch;
			i++;
		}
		else
		{
			str2[i] = '\0';
			if(strcmp(str2,"\0")!=0)
			{
				for(j = 0; j < len_ex; j++)
				{
					if(strcmp(str2, str1[j].str) == 0)
					{
						flag = 1;
						str1[j].n++;
						break;
					}
					else
					{
						flag = 0;
					}
				}
				if(flag == 0)
				{
					strcpy(str1[len_ex].str, str2);
					str1[len_ex].n = 1;
					len_ex++;
				}
			}
			i=0;
		}
    }
	for(i = 0; i < len_ex - 1;i++)
	{
		flag = 0;
		for(j = 0; j < len_ex - 1 -i; j++)
		{
			 if(strcmp(str1[j].str,str1[j + 1].str)>0)
            {
                t = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = t;
                flag=1;
            }
		}
		if(flag == 0)
		{
			break;
		}
	}
	for(i = 0; i < len_ex; i++)
	{
		printf("%s %d\n", str1[i].str, str1[i].n);
	}
	fclose(fp1);
	return 0;
}

