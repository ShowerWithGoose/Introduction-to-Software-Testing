#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int x[1000];
int fun(char* s){
int i=0,j=-1,n=0,k=0,ans=0;

for(i=0;s[i]!='=';i++){
	if(isdigit(s[i])){
	n=n*10+(int)(s[i]-'0');if(s[i+1]=='='){x[++j]=n;
	}
	}
	else{	 if(s[i]!=' '||s[i+1]=='='){switch (k) {
		case 0:
    x[++j] = n;n=0;
   break;
    case 1:
   x[++j] = -n;n=0;
   	break;
  case 2:
  x[j] *= n;n=0;
   break;
    case 3:
    x[j] /= n;n=0;
    break;
   }
 }
	if(s[i]=='+'){
		k=0;
	}else if(s[i]=='-'){
		k=1;
	}
	else if(s[i]=='*'){
		k=2;
	}else if(s[i]=='/'){k=3;
	}
	
	}
	}
	 

for(i=0;i<=j;i++){
ans+=x[i];
}
return ans;
}
int main(){
int ans;
char s[1000];
gets(s);
ans=fun(s);
printf("%d",ans);



return 0;}


