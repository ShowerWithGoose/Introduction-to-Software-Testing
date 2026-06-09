#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i,j=0,k=0,m,sum=0,a1[1000],a2[1000];
	char s1[1000],s2[1000];
	gets(s1);
	for(i=j=0;s1[i]!=0;i++)
	if(s1[i]!=' ')
	s1[j++]=s1[i];
	s1[j]='\0';
	j=0;
	for(i=0;;){
		a1[j]=s1[i]-'0';
		while(s1[i+1]!='+'&&s1[i+1]!='-'&&s1[i+1]!='*'&&s1[i+1]!='/'&&s1[i+1]!='='){
			a1[j]=a1[j]*10+s1[++i]-'0';
		}
		s2[k++]=s1[++i];
		if(s1[i]=='=')
		break;
		i++;
		j++;
	}
	if(s2[0]=='='){
		printf("%d",a1[0]);
		return 0;
	}
    for(i=0,j=0,k=0;;){
    	a2[j]=a1[k];
    	while(s2[i]!='+'&&s2[i]!='-'&&s2[i]!='='){
    		if(s2[i]=='*')
    		a2[j]=a2[j]*a1[++k];
    		if(s2[i]=='/')
    		a2[j]=a2[j]/a1[++k];
    		i++;
		}
		if(s2[i]=='=')
		break;
		k++;
		j++;
		i++;
	}
	m=j;
    for(i=j=0;s2[i]!=0;i++)
	if(s2[i]!='*')
	s2[j++]=s2[i];
	s2[j]='\0';
	j=0;
	for(i=j=0;s2[i]!=0;i++)
	if(s2[i]!='/')
	s2[j++]=s2[i];
	s2[j]='\0';
	j=0;
	for(i=j=0;s2[i]!=0;i++)
	if(s2[i]!='=')
	s2[j++]=s2[i];
	s2[j]='\0';
	j=0;
	sum=a2[0];
	for(i=0;i+1<=m;i++){
		if(s2[i]=='+')
		sum+=a2[i+1];
		else
		sum-=a2[i+1];
	}
	printf("%d",sum);
    return 0;
}


