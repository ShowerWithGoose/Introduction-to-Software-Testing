#include<stdio.h>
#include<string.h>
int main(){
	char s1[10000],s2[10000];
	int i=0,j=0,k=0,x=0,sum=0;
	gets(s1);
	for(i=0;s1[i-1]!='=';i++){
		if(s1[i]!=' '){
			s2[j]=s1[i];
			j++;
		}
	}
	for(i=0;s2[i-1]!='=';i++){
		if(s2[i]!='+'&&s2[i]!='-'&&s2[i]!='=')  x++;
		else{
			int y=0,pro=1;
			for(j=i-x;j<=i;j++){
				if(s2[j]>='0'&&s2[j]<='9')   y++;
				else{
					int num=0,t=1;
					for(k=j-1;k>=j-y;k--){
						num+=(s2[k]-'0')*t;
						t*=10;
					}
					if(s2[j-y-1]=='*'||j-y==i-x){
					    pro*=num;
					}
					else   pro/=num;
				    t=1;num=0;y=0;				
				}
			}
			if(s2[i-x-1]=='+'||i-x==0){
				sum+=pro;
				pro=1;
			}
			else   sum-=pro;
			x=0;	
		}	
	}
	printf("%d",sum);	
} 

