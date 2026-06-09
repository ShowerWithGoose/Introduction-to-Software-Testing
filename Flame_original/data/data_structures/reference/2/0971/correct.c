#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>



int main()
{
	char a[100],b[100];
	int t2,t,l,i,nb1,nb2,len;nb1=nb2=0,l=10;
	int jj,cengc,ci,s,q,j,k,cns;jj=cengc=s=q=ci=cns=i=j=k=0;
	gets(a);
	len=strlen(a);
	b[0]='0';
	b[1]='+';
	j=2; 
	for(i=0;i<len;i++){
		if(a[i]!=' '){
			b[j]=a[i];
			j++;
		}
	}	
	i=0;
v:	j=0;
	memset(a,'a',strlen(a));
	len=strlen(b);
	for(i;i<len;i++){
			if(b[i]=='+'||b[i]=='-'){
			s=i;//s为首个加减号位置
			if(b[i]=='+'){
				t2=1;
			}
			else{
				t2=0;
			}
			for(k=i+1;b[k]!='+'&&b[k]!='-';k++){
				a[j]=b[k];
				j++;
				q++;
				if(b[k]=='='){
					break;
				}
			}
			break;
		}
ss:		if(ci==0){
			while(b[i]!='+'&&b[i]!='-'&&b[i]!='='&&b[i]!='*'&&b[i]!='/'){
				cns*=l;
				cns+=b[i]-'0';
				i++;
			}
			ci++;
		}
		if(b[i]=='='){
			printf("%d",cns);
			return 0;
		}
		i--;
	}
	
	//q为下一个加减号位置 
	for(i=0;i<strlen(a);i++){
		while(a[i]!='*'&&a[i]!='/'&&a[i]!='a'&&a[i]!='='){
			nb1*=l;
			nb1+=a[i]-'0'; 
			i++;
		}
x:		if(a[i]=='*'){
			t=1;
		}
		else if(a[i]=='/'){
			t=0;
		}
		else if(a[i]=='='){
			goto r;
		}
		i++;
		if(a[i]=='a'){
			break;
		}
		while(a[i]!='*'&&a[i]!='/'&&a[i]!='a'&&a[i]!='='){
			nb2*=l;
			nb2+=a[i]-'0'; 
			i++;
		}
		if(t==1){
			nb1*=nb2;
		}
		else{
			nb1/=nb2;
		}
		nb2=0;
		if(a[i]!='='&&a[i]!='0'&&a[i]!='a'&&a[i]!='='){
			goto x;
		}
		else{
			break;
		}
	}
r:	if(t2==1){
		cns+=nb1;
	}
	else{
		cns-=nb1;
	}
	nb1=0;
	i=s+q+1;	
	//还给你，回去算 
	if(b[s+q]!='='){
		q=0;
		goto v;
	}
vvv:	printf("%d",cns);
 	return 0;
}

