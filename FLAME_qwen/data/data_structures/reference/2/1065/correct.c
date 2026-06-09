#include<stdio.h>
#include<string.h>
char eq[100];

void move();
int number(int od);

int main(){
	
	int i,j,flag=1;
	int sum=0,ans=0;
	
	gets(eq);
	move();
	
	for(i=0,j=0;eq[i]!='\0';i++){
		sum=0;
		if(eq[i]=='+' || eq[i]=='-'||eq[i]=='='){
			sum+=number(j);
			while(j<i){
				if(eq[j]=='*'){
					sum*=number(j+1);
				}
				else if(eq[j]=='/'){
					sum/=number(j+1);
				}
				j++;
			}
		
		ans+=sum*flag;
		if(eq[i]=='=')
			break;
		flag=eq[i]=='-'?-1:1;
		j=i+1;
	}
	}
	printf("%d",ans);
	return 0;
}

void move(){
	int i,j;
	for(i=0,j=0;eq[i]!='\0';i++){
		if(eq[i]!=' ')
			eq[j++]=eq[i];
	}
	eq[j]='\0';
}

int number(int od){
	int i;
	int num=0;
	for(i=od;eq[i]>='0'&&eq[i]<='9';i++){
		num=num*10+eq[i]-'0';
	}
	
	return num;
}


