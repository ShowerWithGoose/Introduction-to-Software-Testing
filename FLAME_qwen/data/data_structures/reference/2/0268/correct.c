#include<stdio.h>
#include<string.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define pr printf
char s[100000],c[100000];
int aos[100000];
int obj(int i,int j){
	int sum=0,rec,sr=0,jud;
	i++;
	rec=i;
	while(i<j){
		if(rec==i)	for(;c[i]>='0'&&c[i]<='9';i++) sum=sum*10+c[i]-'0';
		if(c[i]=='*') jud=1; else if(c[i]=='/') jud=0; else jud=-1;
		for(i++;c[i]>='0'&&c[i]<='9';i++) sr=sr*10+c[i]-'0';
		if(jud==1) sum*=sr; else if(jud==0) sum/=sr; else return sum;
		sr=0;
	}
	return sum;
}
int main(){
       int i=0,j=0,cnt=0,res=0;
       gets(s);
       for(i=0;s[i]!='\0';i++){
       	if(s[i]!=' ') c[j++]=s[i];
	   }
		for(i=0;i<strlen(c);i++){
			if(c[i]=='+'||c[i]=='-'||c[i]=='='){
				aos[cnt++]=i;
			}
		}
		res=obj(-1,aos[0]);
		fr(i,0,cnt-1){
			if(c[aos[i]]=='+') res+=obj(aos[i],aos[i+1]);
			else res-=obj(aos[i],aos[i+1]);
		}
		pr("%d",res);
return 0;
}

