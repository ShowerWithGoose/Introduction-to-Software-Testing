#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define arynum(x) (sizeof(x)/sizeof(x[0]))
#define uint unsigned int
#define uchar unsigned char

char s[10000],r[10000];

int count(int num1,int num2,char way);
int getnum(int pos1,int pos2);

int main(){
	int t[10000];
	int i,j,k,key=0,ans=0,num=0,num0;
	gets(s);
	for(i=0,j=0,k=0;i<strlen(s);i++){
		if(s[i]!=' '){
			s[j++]=s[i];
			if(s[j-1]<'0'||s[j-1]>'9'){
				key++;
				t[k++]=j-1;
				switch(s[j-1]){
					case '+':	r[k-1]=0;	break;
					case '-':	r[k-1]=0;	break;
					case '*':	r[k-1]=1;	break;
					case '/':	r[k-1]=1;	break;
					default: 	r[k-1]=0;	break;
				}
			}
		}
	}
	ans=getnum(-1,t[0]);
	for(i=0;i<key-1;i++){
		num=getnum(t[i],t[i+1]);
		j=i;
		if(r[i+1]>r[i]){
			num0=getnum(t[i+1],t[i+2]);
			num=count(num,num0,s[t[i+1]]);
			i++;
			while(r[i+1]){
				num0=getnum(t[i+1],t[i+2]);
				num=count(num,num0,s[t[i+1]]);
				i++;
			}
		}
		ans=count(ans,num,s[t[j]]);
	}
	printf("%d",ans); 
	return 0;
} 

int getnum(int pos1,int pos2){
	int ans=0,i;
	for(i=1;i<pos2-pos1;i++){
		ans+=s[pos1+i]-'0';
		ans*=10;
	}
	return ans/10;
}

int count(int num1,int num2,char way){
	switch(way){
		case '+':	return num1+num2;
		case '-':	return num1-num2;
		case '*':	return num1*num2;
		case '/':	return num1/num2;
	}
}




