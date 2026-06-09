#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char ch[1000];
	int len,j=0,k=0,cup[1000]={0};
	gets(ch);
	len=strlen(ch);
	
	for(int i=0;i<len;i++){
		if(ch[i]!=' '){
			ch[j]=ch[i];
			j++;
		}
	}
	ch[j]='\0';
	for(int i=0;i<j;){                //转换成整型数组 
		int temp=ch[i]-'0';
		while(ch[i+1]>='0'&&ch[i+1]<='9'){
			temp=temp*10+ch[i+1]-'0';
			i++;
		}
		cup[k]=temp;
		cup[++k]=ch[i+1]-100;
		k++;
		i+=2;
	}
	
	
	
	for(int i=1;i<k;i++){           //进行乘除运算 
		if(cup[i]=='*'-100||cup[i]=='/'-100){
			cup[i+1]=(cup[i]=='*'-100)?cup[i-1]*cup[i+1]:cup[i-1]/cup[i+1];
			cup[i-1]=0;
		}
	}
	j=0;
	for(int i=0;i<k;i++){           //除去0和乘除号 
		if(cup[i]==-39) break;
		if((cup[i]!=0&&cup[i]!='*'-100&&cup[i]!='/'-100)){
			cup[j]=cup[i];
			j++;
		}
	}
	cup[j]=-39;

	
	
	for(int i=0;i<k;i++){           //除去多余的加减号 
		if(cup[i]==-39) break;
		if((cup[i]=='+'-100||cup[i]=='-'-100)&&(cup[i+1]=='+'-100||cup[i+1]=='-'-100||cup[i+1]=='='-100))
		cup[i]=0;
	}
	
	j=0;
	for(int i=0;i<k;i++){
		
		if(cup[i]!=0){
			cup[j]=cup[i];
			j++;
		}
		if(cup[i]==-39) break;
	}

	
	for(int i=0;i<k;i++){
		
		if(cup[i]==-39) break;
		if(cup[i]=='+'-100||cup[i]=='-'-100){
		
			cup[i+1]=(cup[i]=='+'-100)?cup[i-1]+cup[i+1]:cup[i-1]-cup[i+1];
		}
		 
		
		j=i;
	}
	if(cup[j]==-39){
		printf("0\n");
	} else
	printf("%d\n",cup[j]);	
}

