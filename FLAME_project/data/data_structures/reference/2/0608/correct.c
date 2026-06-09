#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int n[100];
int main()
{
char s[500],s1[500];
int i,j,k,t,len,p[100],sum=0,tmp=0;
gets(s);
len=strlen(s);
//printf("%d\n",len);
for (i=0,j=0;i<=len;i++){//注意结尾的'\0'!!!!! 
	if (s[i]!=' ')
	s1[j]=s[i],j++;
}//去除空格 
len=strlen(s1);
//puts(s1);
//printf("%d\n",len);
p[0]=-1;
for (i=0,j=1;i<len-1;i++){
	if (s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')
	p[j]=i,j++;
}
p[j]=len-1;//p[1]-p[t]为符号所在位置 
t=j;
/*for (i=0;i<=t;i++)
printf("%d\n",p[i]);*/
if (j==1){
	for (i=0;i<len-1;i++)
	printf("%c",s1[i]);
}//若只有一个数字，直接输出 
else{
	k=0;
    for (i=0;i<t;i++){
    	for (j=p[i]+1;j<p[i+1];j++){
    		n[k]=10*n[k]+s1[j]-'0';
		}
		k++;
	}
	/*for (i=0;i<t;i++)
	printf("%d\n",n[i]);*/
	tmp=n[0];
	for (i=1;i<t;i++){
		if (s1[p[i]]=='+'){
			sum+=tmp,tmp=n[i];
		}
		else if (s1[p[i]]=='-'){
			sum+=tmp,tmp=-n[i];
		}
		else if (s1[p[i]]=='*'){
			tmp*=n[i];
		}
		else if (s1[p[i]]=='/'){
			tmp/=n[i];
		}
		//printf("%d %d\n",sum,tmp);
	}
	sum+=tmp;
	printf("%d",sum);
}
return 0;
}









