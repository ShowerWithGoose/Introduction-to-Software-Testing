#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
struct s{
	char *p;
	int sum;
}num[1000];
int cmp(const void* a,const void*b){
	struct s *j ,*k;
	j=(struct s*)a;
	k=(struct s*)b;
	return strcmp(j->p,k->p);
}
int main()
{
	FILE *in;
	char buf[1010]="",ch[100]="";
	int i,q,flag,s=0,j;
	in=fopen("article.txt","r");
	while(fgets(buf,1000,in)!=NULL){
		i=0;
		while(buf[i]!='\0'){
			if((tolower(buf[i])>='a'&&tolower(buf[i])<='z')){
				q=0;
				while(buf[i]!=' '&&buf[i]!='\0'&&(tolower(buf[i])>='a'&&tolower(buf[i])<='z')){
					ch[q]=tolower(buf[i]);
					q++;i++;
				}
				ch[q]='\0';flag=0;
				for(j=0;j<s;j++){
					if(strcmp(ch,num[j].p)==0){
						num[j].sum++;
						flag=1;
						break;
					}
				}
				if(flag!=1){
					num[s].p=(char*)malloc(strlen(ch));
					strcpy(num[s].p,ch);
					num[s].sum=1;
					s++;
				}
			}
			i++;
		}
	}
	
	qsort(num,s,sizeof(num[0]),cmp);
	for(i=0;i<s;i++){
		printf("%s %d\n",num[i].p,num[i].sum);
	}
	return 0;
}

