#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		char w[15];
		int num;
}word;
int comp(const void *,const void *);
int main()
{
	word outp[500];
	char inp[15], c;
	int i, len=0, j=0;
	FILE *in;
	in = fopen("article.txt","r"); 
	while((c=fgetc(in))!=EOF){
		if(islower(c)){
			inp[j] = c;
			j++;}
		else if(isupper(c)){
			inp[j] = 'a'+(c-'A');
			j++;}
		else{
			for(i=0;i<len;i++){
				if(strcmp(inp,outp[i].w)==0){
					outp[i].num++;
					break;}
			}
			if(i==len){
				strcpy(outp[i].w,inp);
				outp[i].num++;
				len++;
			}
			memset(inp,0,j);
			j = 0; 
		}
	}
	qsort(outp,len,sizeof(word),comp);
	for(i=1;i<len;i++)
		printf("%s %d\n",outp[i].w,outp[i].num);
	fclose(in);
    return 0;
}

int comp(const void *a, const void *b){
	word *p1 = (word *)a;
	word *p2 = (word *)b;
	if(strcmp(p1->w,p2->w)>0) return 1;
	if(strcmp(p1->w,p2->w)<0) return -1;
	return 0;
}

