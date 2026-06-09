#include <stdio.h>
#include <stdlib.h>
struct mul{
	int x1;
	int x2;
}a[100],b[100],c[10000],change;
char s[1000];
char s1[1000];
int main(){
	int i,j;
	int k=0;
	int flag=0;
	int m=0;
	int turn=0;
	gets(s);
	gets(s1);
    for(i=0;s[i]!='\0';i++){
    	if(s[i]!=' '&&s[i]!='\n')
    	m=10*m+s[i]-'0';
    	if(s[i]==' '||s[i+1]=='\0'){
    		if(turn==0){
    			a[k].x1 =m;
    			m=0;
    			turn=1;
			}
			else if(turn==1){
				a[k].x2=m;
				m=0;
				k++;
				turn=0;
			}
		}
	}
	int len1=k;
	k=0;
	turn=0;
	char launch[10000]={0};
	for(i=0;s1[i]!='\0';i++){
    	if(s1[i]!=' '&&s1[i]!='\n')
    	m=10*m+s1[i]-'0';
    	if(s1[i]==' '||s1[i+1]=='\0'){
    		if(turn==0){
    			b[k].x1 =m;
    			m=0;
    			turn=1;
			}
			else if(turn==1){
				b[k].x2=m;
				m=0;
				k++;
				turn=0;
			}
		}
	}	
	int len2=k;
	k=0;
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			c[k].x1=a[i].x1 *b[j].x1 ;
			c[k].x2=a[i].x2+b[j].x2;
			k++;
		}
	}
	int sum=0;//±£´æ¼ÓÊı 
	for(i=0;i<len1*len2;i++){
		for(j=i+1;j<len1*len2;j++){
			if(c[i].x2 <c[j].x2){
			change=c[i];
			c[i]=c[j];
			c[j]=change;
			}
		}
	}
	for(i=0;i<len1*len2;i++){
		k=i;
		while(c[k].x2 ==c[k+1].x2&&c[k].x2!=0){
			launch[k+1]=1;
			sum+=c[k+1].x1;
			k++;
		}
		c[i].x1+=sum;
		sum=0;
	}
	for(i=0;i<len1*len2;i++){
		if(c[i].x1!=0&&launch[i]!=1)
		printf("%d %d ",c[i].x1,c[i].x2);
	}
	return 0;
}



