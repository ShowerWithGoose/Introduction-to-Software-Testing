#include<stdio.h>
#include<string.h>
char shi[200];//原算术式
char fu[200];//记录运算符
int shu[200],shu2[200];//记录每个运算符前的数字
int haxi[200];//记录+、-的位置 
int main()
{
	gets(shi);
	
	int d=strlen(shi);
	int kai,mo;
	int i,j=0,flag=0,k=0,z=0,y,count=0,num2,num;
	for(i=0;i<d;i++)
	{
		if(shi[i]==' '){
	
		continue;}
		else if(shi[i]>='0'&&shi[i]<='9')
		{
			shu[j]=shu[j]*10+(shi[i]-48);
		
	}
	else
	{
		fu[k++]=shi[i];
		j++;
	}
	if(shi[i]=='=')
	break;
	}
	if(fu[0]=='=')
	printf("%d",shu[0]);
	else{
	
	int l1=j;
	for(i=0;i<l1;i++){
		if(fu[i]=='+'||fu[i]=='-'){
			if(flag==1){
				for(y=kai;y<=mo;y++)
				shu[y]=num;
			}
			num=0;
		flag=0;
		haxi[z++]=i;
		count++;}
		else if(fu[i]=='*'){
				if(flag==0){
					kai=i;
					mo=i+1;
					num=shu[i];
				}else
				mo=i+1;
		num=num*shu[i+1];
		flag=1;		
		}
		else if(fu[i]=='/'){
				if(flag==0){
					kai=i;
					mo=i+1;
					num=shu[i];
				}else
				mo=i+1;
		num=num/shu[i+1];
		flag=1;
		}
		else if(fu[i]=='='){
			if(flag==1){
				for(y=kai;y<=mo;y++)
				shu[y]=num;
			}
		}
	}
	num2=shu[0];
	for(i=0;i<count;i++){
		if(fu[haxi[i]]=='+'){
			num2+=shu[haxi[i]+1];
		}
		else
		num2-=shu[haxi[i]+1];
	}
	printf("%d",num2);}
	return 0;
 } 

