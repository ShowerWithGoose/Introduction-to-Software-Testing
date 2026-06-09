#include<stdio.h>
#include<string.h>
	char str[105];
	int i,i,k;
	int num;
	int main()
	{	
		gets(str);
		for(i=0;i<strlen(str);i++)//ÕÒ"." 
		{if(str[1]=='.'&&str[0]=='0')
			{for(i=2;i<strlen(str);i++)
				{if(str[i]!='0'&&i==strlen(str)-1)//Ä©Î» 
					{printf("%ce-",str[i]);
					printf("%d",i-1);
					return 0;
					}
				else if(str[i]!='0')
					{printf("%c.",str[i]);
						for(k=i+1;k<strlen(str);k++)
						printf("%c",str[k]);
					printf("e-%d",i-1);
					return 0;
					}
				}
				
			}
		else if(str[1]=='.')
			{	for(k=0;k<strlen(str);k++)
				printf("%c",str[k]);
				printf("e0");
				return 0;
			}
		else if(str[i]=='.')
		{printf("%c.",str[0]);
			for(k=1;k<i;k++)
			printf("%c",str[k]);
			for(k=i+1;k<strlen(str);k++)
				printf("%c",str[k]);
			printf("e%d",i-1);
			return 0;
		}
			
		}
	
	}

