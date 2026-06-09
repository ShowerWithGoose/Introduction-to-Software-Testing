#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	char a[200];
    gets(a);
    int i=0,m=0,j=0,l=0,q=0;
    char b[200];
    int  c[200]={};
    int k[200]={};
    while(i<strlen(a)){
    	if(a[i]==' '){
    		i++;
    		continue;
		}
    	if(!isdigit(a[i])){
    		b[m]=a[i];
    		i++;
    		m++;
		}else{
			l=0;
	    while(isdigit(a[i])){
	    	k[l]=a[i]-'0';
	    	l++;
	    	i++;
		}
		q=1;
		l--;
		while(l>=0){
	    c[j]=c[j]+q*k[l];
	    q=q*10;
	    l--;
		}
		j++;
		}
	}
i=0;	
//int len=strlen(b);
int sum=1;
int poin=0;
while(i<m){
if(b[i]=='*'){
	poin=i;
while(b[i]=='*'){
	sum=sum*c[i];
	i++;
}
sum=sum*c[i];
c[i]=sum;

while(poin<i){
	c[poin]=0;
	poin++;
}
}	
else if(b[i]=='/'){
	poin=i;
	sum=c[i];
while(b[i]=='/'){
	sum=sum/c[i+1];
	i++;
}
c[i]=sum;

while(poin<i){
	c[poin]=0;
	poin++;
}
}else{
	i++;
	continue;
}		
}
int sumk=0;
int poin1=0;
while(poin1<m){
	if(b[poin1]=='*'||b[poin1]=='/'){
		if(b[poin1-1]=='+'){
		while(b[poin1]=='*'||b[poin1]=='/'){
			b[poin1]='+';
		}
	}else if(b[poin1-1]=='-'){
		while(b[poin1]=='*'||b[poin1]=='/'){
			b[poin1]='-';
		}
	}else{
		b[poin1]='+';
	}
	}
	poin1++;
}
poin1=0;
sumk=c[0];
while(poin1<j){
	if(b[poin1]=='+'){
		sumk+=c[poin1+1];
	}else if(b[poin1]=='-'){
		sumk-=c[poin1+1];
	}
	poin1++;
}
printf("%d",sumk);
		
	return 0;
}


