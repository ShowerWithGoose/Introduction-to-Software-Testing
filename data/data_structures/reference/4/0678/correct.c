#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct wr{
	int p;
	char w[32];
};
int Cmp(struct wr* a,struct wr* b){
	return(strcmp(a->w,b->w));
}
int main(){
	FILE* f;
	char wd[32],nu[32];
	int c,i=0,j=0,k=0,u;
	struct wr m[512];
	f=fopen("article.txt","r");
	while((c=getc(f))!=EOF){
		if(c>='A'&&c<='Z'){
			c=c-'A'+'a';
			wd[i]=c;
			i++;
		}
		else if(c>='a'&&c<='z'){
			wd[i]=c;
			i++;
		}
		else{
			wd[i]='\0';
			i=0;
			for(k=0,u=0;k<j;k++){
				if(strcmp(m[k].w,wd)==0){
					m[k].p++;
					u=1;
					}
			}
			if(u==0){
				strcpy(m[j].w,wd);
				m[j].p=1;
				j++;
			}
			strcpy(wd,nu);
		}
	}
	fclose(f);
	
	qsort(m,j,sizeof(struct wr),Cmp);
	for(i=0;i<j;i++){
		if(strlen(m[i].w)>0)
			printf("%s %d\n",m[i].w,m[i].p);
	}
	return 0;
}

