#include<stdio.h>
#include<string.h>
int main()
{
	char ch[1000];
	int i,id_point,id_firstNum;
	scanf("%s",&ch);
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='.')
		{id_point=i;
		break;	
		}
	}
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]>'0'&&ch[i]<='9')
		{id_firstNum=i;	
		break;
		}
	}
	if(id_firstNum==strlen(ch)-1){
		printf("%ce%d",ch[id_firstNum],id_point-id_firstNum);
	}
	else if(id_firstNum<id_point) {
		printf("%c.",ch[id_firstNum]);
		for(i=id_firstNum+1;i<id_point;i++){
			printf("%c",ch[i]);
		}
		for(i=id_point+1;i<strlen(ch);i++){
			printf("%c",ch[i]);
		}
		 printf("e%d",id_point-id_firstNum-1);
	}
	else{
		printf("%c.",ch[id_firstNum]);
		for(i=id_firstNum+1;i<strlen(ch);i++){
			printf("%c",ch[i]);
		}
		 printf("e%d",id_point-id_firstNum);
	}

 } 

