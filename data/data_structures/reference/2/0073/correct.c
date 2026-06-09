#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


int cul(int a,char c,int b){
	if(c=='+'){
		return a+b;
	}
	if(c=='-'){
		return a-b;
	}
	if(c=='*'){
		return a*b;
	}
	if(c=='/'){
		return a/b;
	}
}
int comp(char a,char b){
	if(a=='*'||a=='/'){
		return 1;
	}

    else if(b=='*'||b=='/'){
    	return 0;
    	
	} 
	else{
		return 1;
	}
}

char sign()
{
	char s;
	scanf("%c",&s);
	while(s==' '){
		scanf("%c",&s);
	}
	return s;
}

int main(){


int num[300];
int left,mid,right;
char s1,s2;

scanf("%d",&left);
s1=sign();
if(s1=='='){
	printf("%d",left);
	
}
else{
	scanf("%d",&mid);
	s2=sign();
	if(s2=='='){
		printf("%d",cul(left,s1,mid));
	}
	else{
		
		while(s2!='='){
		scanf("%d",&right);
		if(comp(s1,s2)==1){
			left=cul(left,s1,mid);
			s1=s2;
			mid=right;
			s2=sign();
			
			
		}
		else if(comp(s1,s2)==0){
			left=left;
			s1=s1;
			mid=cul(mid,s2,right);
			s2=sign();
		}
		}
		printf("%d",cul(left,s1,mid));
	}
}


}


