#include<stdio.h>
#include<string.h>
char a[9000];
int num[5];
char op[5];

void squeez(char s[],char c) //È¥¿Õ¸ñ 
{ 
	int i,j; 
	for(i=j=0;s[i]!='\0';i++) 
	if(s[i]!=c) s[j++]=s[i];
	s[j]='\0';
}

int funop(int a,int b,char c)
{
	if(c==1) return a+b;
	if(c==2) return a-b;
	if(c==3) return a*b;
	if(c==4) return a/b;
}

int main()
{
	int i;
	int nf=1,of=1;
	gets(a);
	squeez(a,' ');
	for(i=0;a[i]!='\0';i++){
		if('0'<=a[i]&&a[i]<='9'){
			num[nf]=a[i]-'0';
			for(;'0'<=a[i+1]&&a[i+1]<='9';i++){
				num[nf] = 10*num[nf]+a[i+1]-'0';
			}
			nf++;
		}
		else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			if(a[i]=='+') op[of] = 1;
			else if(a[i]=='-') op[of] = 2;
			else if(a[i]=='*') op[of] = 3;
			else if(a[i]=='/') op[of] = 4;
			of++;
		}
		else if(a[i]=='='){
			break;
		}
		
		if(nf==4&&of==3){
			if((op[1]<3&&op[2]<3)||(op[1]>2&&op[2]>2)||(op[1]>op[2])){
				num[1] = funop(num[1],num[2],op[1]);
				num[2] = num[3];
				op[1] = op[2];
				of--;nf--;
			}
			else {
				num[2] = funop(num[2],num[3],op[2]);
				of--;nf--;
			}	
		}
	}
	if(nf==2) printf("%d",num[1]);
	else if(nf==3) printf("%d",funop(num[1],num[2],op[1]));
	return 0;
}

