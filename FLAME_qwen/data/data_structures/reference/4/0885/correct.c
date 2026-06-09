#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
typedef struct words *ptr;
struct words {
	char s[1000];
	int time,len;
} a[MAXSIZE];
int compare(const void *p1,const void *p2)
{
	ptr a,b;
	a=(ptr)p1;
	b=(ptr)p2;
	return strcmp(p1+1,p2+1);
}
char in[MAXSIZE],temp[MAXSIZE];
int size,l;
int main() {
	FILE *IN,*OUT;
	IN=fopen("article.txt","r");
	//OUT=fopen("","w");
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,flag=0,k,p,f;
	while(fgets(in,1026,IN)!=NULL) {
		l=strlen(in);
		for(j=0; j<l; j++) {
			f=0;
			if((in[j]<='z'&&in[j]>='a')||(in[j]<='Z'&&in[j]>='A')) {

				for(i=1; i<=size; i++) {
					flag=0;
					p=j;
					for(k=1; k<=a[i].len; k++) {
						if(a[i].s[k]==in[p]||a[i].s[k]==in[p]-'A'+'a')
							p++;
						else {
							flag=1;
							break;
						}
					}
					if(flag==1) {
						continue;
					}
					else {
						if((in[p]<='z'&&in[p]>='a')||(in[p]<='Z'&&in[p]>='A'))
						continue;
						a[i].time++;
						j+=a[i].len;
						f=1;
					}
				}
				if(f==0) {
					size++;
					while((in[j]<='z'&&in[j]>='a')||(in[j]<='Z'&&in[j]>='A')) {
						a[size].s[++a[size].len]=tolower(in[j]);
						j++;
					}
					a[size].time=1;
				}
			}
		}
	}
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=a[i].len;j++)
		a[i].s[j]=tolower(a[i].s[j]);
	}
	qsort(a+1,size,sizeof(struct words),compare);
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=a[i].len;j++)
		printf("%c",a[i].s[j]);
		printf(" %d\n",a[i].time);
	}
	fclose(IN);
	//fclose(OUT);
	return 0;
}


