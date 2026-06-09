#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int cmp(const void*p1,const void*p2);
struct voc{  
	char w[200];
	int t;
};
typedef struct voc V;
V a[1000];
int i,j,k,p=0;
char s[200],tmp[200],c;
int main(){
	FILE *fp;
    fp=fopen("article.txt","r");
	c=fgetc(fp);
	i=0;
	while(c!=EOF){
		s[i]=c;
		c=fgetc(fp);
		i++;
	}
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i]))
			s[i]=tolower(s[i]);
	}
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])){
			for(j=i;j<strlen(s);j++){
				if(!isalpha(s[j])){
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++){
				tmp[k]=s[i+k];
			}
			strcpy(a[p].w,tmp); 
			p++;
			i=j;
		}
		else
			continue;
	}
	qsort(a,p,sizeof(V),cmp);
	for(i=0;i<p;i++) a[i].t=1;
	for(i=0;i<p;i++)
	{
		if(strcmp(a[i].w,a[i+1].w)==0) 
		{
			a[i+1].t+=a[i].t;
			a[i].t=0;
		}
	}
	qsort(a,p,sizeof(V),cmp);
	for(i=0;i<p;i++){
		if(a[i].t==0){
			continue;
		}
		else{
			printf("%s %d\n",a[i].w,a[i].t);
		}
	}
	return 0;
}
int cmp(const void *p1,const void *p2) 
{
	struct voc *a=(struct voc*)p1;
	struct voc *b=(struct voc*)p2;
	return strcmp(a->w,b->w);
}



