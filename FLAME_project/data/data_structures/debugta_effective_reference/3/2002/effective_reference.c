#include <stdio.h>
#include <string.h>
int main()
{
	char shu_ru[110]="";
	gets(shu_ru);
	int len=strlen(shu_ru);
	int i;
	int xiao_shu_dian=0;
	int flag=0;
	for(i=0;i<len;i++)
	{
		if(shu_ru[0]=='0')    //首位为0 
		{
			flag=1;
			break;	
		}
		else
		{
			flag=2;
			if(shu_ru[i] != '.')
				xiao_shu_dian++;
			if(shu_ru[i] == '.')
				break;
		 } 
	}
	if(flag == 1 && shu_ru[len-2] != '0' && shu_ru[len-2] != '.')        // 首位为0 
	{
		int j;
			for(j=2;j<len;j++)
			{
				if(shu_ru[j] != '0')
				{
					
					printf("%c",shu_ru[j]);
					printf(".");
					int k;
					for(k=j+1;k<len;k++)
						printf("%c",shu_ru[k]);
					printf("e");
					printf("-%d",j-1);
					break;
				}
			}
	}
	else if(flag == 1 && shu_ru[len-2] == '0')
	{
		printf("%ce-%d",shu_ru[len-1],len-2);
	}
	else if(flag == 1 && shu_ru[len-2] == '.')
		printf("%ce-1",shu_ru[len-1]);
	else if(flag==2 && len != 1)
	{
		printf("%c",shu_ru[0]);
		printf(".");
		int l;
		for(l=1;l<xiao_shu_dian;l++)
			printf("%c",shu_ru[l]);
		int p;
		for(p=xiao_shu_dian+1;p<len;p++)
			printf("%c",shu_ru[p]);
		printf("e");
		printf("%d",xiao_shu_dian-1);
	}
	else if(flag == 2 && len == 1)
		printf("%ce0",shu_ru[0]);
	return 0;
}

