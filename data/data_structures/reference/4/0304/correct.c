#include <stdio.h>
#include <string.h>
typedef struct{
	char a[20];
	int n;
}word;
int sort(word *d,int *dn,int i){
	int j=0,k=0;
	int t;
	for(j=0;j<i-1;j++){
		for(k=0;k<i-1;k++){
			if(strcmp(d[dn[k]].a,d[dn[k+1]].a)>0){
				t=dn[k];
				dn[k]=dn[k+1];
				dn[k+1]=t;
			}
		}
	}
	for(k=0;k<i-1;k++){
		if(strcmp(d[dn[k]].a,d[dn[k+1]].a)==0){
			d[dn[k]].n+=1;
			for(j=k+1;j<i-1;j++){
				dn[j]=dn[j+1];
			}
			i--;
			k--;
		}
	}
	return i;
}
word d[200];
int dn[200];
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int c;
	char t[20];
	int i=0,j=0,k;
	while((c=fgetc(in))!=EOF){
		if(c>=65&&c<=90){
			t[j]=c+32;
			j++;
		}
		else if(c>=97&&c<=122){
			t[j]=c;
			j++;
		}
		else if(j!=0){
			dn[i]=i;
			for(k=0;k<j;k++){
				d[i].a[k]=t[k];
			}
			d[i].n=1;
			i++;	
			j=0;
		}
	}
	i=sort(d,dn,i);
	for(j=0;j<i;j++){
		printf("%s %d\n",d[dn[j]].a,d[dn[j]].n);
	}
	return 0;
}

