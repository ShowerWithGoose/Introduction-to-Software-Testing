#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	FILE *fp;
	int i,j,k,flag,num1,temp2;
	char c;
	char word[1000][100],dic[1000][100],temp1[100];
	int num[1000]= {0};

	fp=fopen("article.txt","r");
	if(fp==NULL)
	{
		perror("Can't open file_a");
	}

	i=0;
	j=0;
	num1=0;
	while((c=fgetc(fp))!=EOF)
	{
		if(tolower(c)>='a'&&tolower(c)<='z')
		{
			word[i][j]=tolower(c);
			j++;
		}
		else //if(tolower(c)>='z'&&tolower(c)<='a')
		{
			word[i][j]='\0';
			//如果只读入了一个'\0'
			if(j==0)
			{
				i--;
			}

			else
			{
				//重置标志位
				flag=0;

				//将第一个单词复制进字典
				if(i==0)
				{
					strcpy(dic[0],word[0]);
					num1++;
				}

				else
				{
					for(k=0; k<num1; k++)
					{
						if(strcmp(word[i],dic[k])==0)
						{
							num[k]++;
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						strcpy(dic[num1],word[i]);
						num1++;
					}
				}
			}
			//准备下一个
			i++;
			j=0;
		}
	}


	//最后一个单词的结尾无法判断 无法进入判断
	word[i][j]='\0';

	i++;  //读入的所有单词的的个数

	if(word[i-1][0]=='\0')  //说明最后一个单词结尾有符号
	{
		i--;
	}

	else
	{
		//比较最后一个
		flag=0;
		for(k=0; k<num1; k++)
		{
			if(strcmp(word[i-1],dic[k])==0)
			{
				num[k]++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			strcpy(dic[num1],word[i-1]);
			num1++; //num1 出现的单词的个数 无重复
		}
	}
	//for(i=0; i<num1; i++)
	//{
	//	puts(word[i]);
	//}

	//排序
	for(i=0; i<num1; i++)
	{
		for(j=0; j<num1-i-1; j++)
		{
			if(strcmp(dic[j],dic[j+1])>0)
			{
				strcpy(temp1,dic[j]);
				strcpy(dic[j],dic[j+1]);
				strcpy(dic[j+1],temp1);

				temp2=num[j];
				num[j]=num[j+1];
				num[j+1]=temp2;

			}
		}
	}

	for(i=0; i<num1; i++)
	{
		for(j=0; j<strlen(dic[i]); j++)
		{
			printf("%c",dic[i][j]);
		}

		printf(" ");

		if(i<num1-1)
			printf("%d\n",num[i]+1);
		else
			printf("%d",num[i]+1);
	}

//printf("%d",num1);
	return 0;
}



