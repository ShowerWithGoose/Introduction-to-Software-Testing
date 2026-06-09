#include<stdio.h>
#include<ctype.h>
int s[10000],c[10000];
char ch[10000],l[10000];
int save(char *l){
	int flag=0,k=0,j=0,num=0;
	for(int i=0;l[i]!=0;i++){
		if(isdigit(l[i])){
			s[k]=s[k]*10+l[i]-'0';flag++;
			}
		else if(l[i]==' ')continue;
		else{
			k++;
			ch[j++]=l[i];
			num++;
		}
	}
	return num;
}
int main(){
	int ans=0;
	gets(l);
	int num=save(l);
	c[0]=1;
	for(int i=0;;i++){
		if(ch[i]=='+')
			c[i+1]=1;
		else if(ch[i]=='-')
			c[i+1]=-1;
		else if(ch[i]=='=')
			break;
		else
			for(int k=i;;i++){
				if(ch[i]=='+'||ch[i]=='-'){i--;break;}
				else if(ch[i]=='*')s[k]*=s[i+1];
				else if(ch[i]=='/')s[k]/=s[i+1];
				else goto A;
				c[i+1]=0;
			}
	}
	A:for(int i=0;i<num;i++)
		ans+=s[i]*c[i];
	printf("%d",ans);
}



