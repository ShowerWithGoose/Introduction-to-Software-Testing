#include<stdio.h>
#include<string.h>
void clean(char *s){
	int len=strlen(s),i,j=0;
	for(i=0;i<len;i++){
		if(s[i]!=' ')s[j++]=s[i];
	}
	s[j]='\0';
}//È¥³ý¿Õ¸ñ 
int main(){
	char s[105],computor[50];
	int sum=0,i=0,j=0,m=0,len,middle[50],num_com=0,num_mid,number[50];
	int kick_1,kick_2;
	gets(s);
	clean(s);
	//printf("%s\n",s);
	len=strlen(s);
	for(i=0;s[i]!='=';i++){
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
		computor[j++]=s[i];
		num_com++;
		}
	}
	//printf("%d\n",num_com);
	j=0;
	for(i=0;i<len;i++){
		kick_1=0;
		while(s[i]>='0'&&s[i]<='9'){
			kick_1=10*kick_1+s[i]-'0';
			//printf("%d ",kick_1);
			i++;
		}
		if(s[i-1]>='0'&&s[i-1]<='9'&&!(s[i]>='0'&&s[i]<='9'))
		middle[j++]=kick_1;
	}
	//for(i=0;i<j;i++)printf("%d\n",middle[i]);	
	num_mid=j;j=0;

	for(i=0;i<=num_com;i++){
		number[m]=middle[j++];
		while(computor[i]=='*'||computor[i]=='/'){
			if(computor[i]=='*')number[m]*=middle[j++];
			else number[m]/=middle[j++];
			i++;
		}
		m++;
	}
	//printf("%d\n",m);
	if(num_com==0)printf("%d",middle[0]);
	//for(i=0;i<m;i++)printf("%d ",number[i]);
	
	sum=number[0];j=0;
	for(i=0;i<num_com;i++){
		//printf("%d ",sum);
		if(computor[i]=='+')sum+=number[++j];
		else if(computor[i]=='-')sum-=number[++j];
	}
	if(num_com>0)printf("%d",sum);
	return 0; 
}

