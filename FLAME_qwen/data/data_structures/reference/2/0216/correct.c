#include<stdio.h>
#include<math.h>
#include<string.h> 
char s[10000]={},sg[10000]={};int num[10000]={},i=0,j=0,k=0,w=0;
void cl(int a){
	int b; 
	for(b=a;b<k;b++){
		sg[b]=sg[b+1],num[b+1]=num[b+2];
	}5/
	k--;
}
int main(){
	gets(s);
	for(;s[i]!='\0';i++){
		if (s[i]==' ') continue;
		else if (s[i]=='=') break;
		else {
			s[w++]=s[i];
		}
	}
	int u=0;
	for(u=0;u<w;u++){
		if (s[u]>='0'&&s[u]<='9') num[j]=num[j]*10+(s[u]-'0');
		else {
			sg[k++]=s[u],j++;
		}
	}
	int a;
	for(a=0;a<k;){
		if(sg[a]=='*'){
			num[a]=num[a]*num[a+1];cl(a);a=0;
		}
		else if(sg[a]=='/'){
			num[a]=num[a]/num[a+1];cl(a);a=0;
		}
		else a++;
	}
	for(a=0;a<k;){
		if(sg[a]=='+'){
			num[a]=num[a]+num[a+1];cl(a);a=0;
		}
		else if(sg[a]=='-'){
			num[a]=num[a]-num[a+1];cl(a);a=0;
		}
		else a++;
	}
	printf("%d",num[0]);num,sg;
	
return 0;
} 



