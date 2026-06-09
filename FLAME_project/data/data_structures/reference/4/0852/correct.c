#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long
FILE *in;
struct letter{
	char s[50];
	int count;
}link[500]; 
int main(){
	int i,j,k,m;
	in=fopen("article.txt","r");
	char c;
	i=j=0;
	while((c=fgetc(in))!=EOF){
		if(c>='a'&&c<='z'){
			link[i].s[j]=c;
			j++;
			link[i].count=1;
		}
		else if(c>='A'&&c<='Z'){
			link[i].s[j]=c-'A'+'a'; 
			j++;
			link[i].count=1;
		}
		else{
			if(j!=0)
			i++;
			j=0;
		}
	}
	char x[50];
	int t;
	for(k=0;k<i-1;k++){
		for(m=k+1;m<i;m++){
			if(strcmp(link[k].s,link[m].s)>0){
				strcpy(x,link[k].s);
				strcpy(link[k].s,link[m].s);
				strcpy(link[m].s,x);
				t=link[k].count;
				link[k].count=link[m].count;
				link[m].count=t;
			}
			else if(strcmp(link[k].s,link[m].s)==0){
				link[k].count++;
				link[m].s[0]=126;
			}
		}
	}
	for(k=0;k<i;k++){
		if(link[k].s[0]<='z'&&link[k].s[0]>='a'){
			printf("%s %d\n",link[k].s,link[k].count);
		}
	}
	fclose(in);
}

