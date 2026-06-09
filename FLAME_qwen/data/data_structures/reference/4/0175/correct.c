#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct word{
	int num;
	char s[100];
}Word;
int cmp(const void *p1,const void *p2){
	struct word *a=(struct word*)p1;
	struct word *b=(struct word*)p2;
	return strcmp(a->s,b->s);
}
char a,b[600];
Word op[1000];
int main(){
	int i=0,j,k=1,t=0,cnt=0;
	FILE *fp=fopen("article.txt","r");
	while((a=fgetc(fp))!=EOF){
		if(a>='A'&&a<='Z'){
			b[cnt]=a-'A'+'a';
			cnt++;
		}
		else if(a>='a'&&a<='z'){
			b[cnt]=a;
			cnt++;
		}
		else if(a==' '){
			b[cnt]=a;
			cnt++;
		}
		else{
			b[cnt]=' ';
			cnt++;
		}
    }
    
	for(i=0;i<cnt;i++){
		if(b[i]>='a'&&b[i]<='z'){
			op[t].s[0]=b[i];k=1;op[t].num=1;
			for(j=i+1;j<cnt;j++){
				if(b[j]==' '){
				break;	
				} 
				else{
				op[t].s[k]=b[j];
				k++;	
				} 
			}
		t++;
		i=j;
		}
		else continue;
		
	}
	for(i=0;i<t;i++){
		for(j=i+1;j<t;j++){
			if(strcmp(op[i].s,op[j].s)==0){
				op[i].num++;
				op[j].s[0]='*';
			}
		}
	}
	qsort(op,t,sizeof(Word),cmp);
	for(i=0;i<t;i++){
		if(op[i].s[0]!='*'){
			printf("%s %d\n",op[i].s,op[i].num);
		}
	}
	fclose(fp);
	return 0;
}

