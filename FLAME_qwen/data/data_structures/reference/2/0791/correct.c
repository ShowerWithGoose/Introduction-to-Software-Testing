#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
char ch[99999];
int mark[100];
int num[100];
int sum[100];
char ch0[999];
int main() 
{  gets(ch);
  int k=1,i,i1,shu,p,q,num0=0;
  mark[0]=-1;
  for(i=0;ch[i]!='=';i++){
  	if(ch[i]=='-'||ch[i]=='+'){
  		mark[k++]=i;
	  }
  }
  mark[k++]=i;
  k--;
  for(i=0;i<=k;i++){
  	q=p=0;
  	for(i1=mark[i]+1;i1<=mark[i+1]-1;i1++){
  		if(ch[i1]==' '){
	  		continue;
		  }
  		if(ch[i1]!='/'&&ch[i1]!='*'){
  			ch0[p++]=ch[i1];
		  }
  		else{
  			ch0[p]='\0';
  			shu=atoi(ch0);
  			num[q++]=shu;
  			p=0;
		  }	
  		
	  }
	  ch0[p]='\0';
  			shu=atoi(ch0);
  			num[q++]=shu;
	  p=1;
	  shu=num[0];
	  for(i1=mark[i]+1;i1<=mark[i+1]-1;i1++){
	  	if(ch[i1]==' '){
	  		continue;
		  }
	  	if(ch[i1]=='/'){
	  		shu/=num[p++];
		  }
		  else if(ch[i1]=='*'){
		  	shu*=num[p++];
		  }
	  }
	  sum[num0++]=shu;
  }
  num0=0;
  int ans=sum[num0++];
  for(i=0;ch[i]!='=';i++){
  	if(ch[i]=='+'){
  		ans+=sum[num0++];
	  }
	  else if(ch[i]=='-'){
	  	ans-=sum[num0++];
	  }
  }
  printf("%d",ans);

return 0; 
}

