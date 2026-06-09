#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _word{
	char content[20];
	int num;
}word,*pword;
int cmp(const void *p1,const void *p2){
	int ans;
	pword word1=(pword) p1;
	pword word2=(pword) p2;
	ans=strcmp(word1->content,word2->content);
	return ans;
}
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int c;
	word a[50];
	char s[20];
	int i=0,j=0,flag=0,k=0,p=0;
	if(NULL==in){
		printf("Failed to open the file!\n");
		exit(0);
	}
	while((c=fgetc(in))!=EOF){
		if(c>='a'&&c<='z'){
			flag=1;
			s[j]=c;
			j++;
		}else if(c>='A'&&c<='Z'){
			flag=1;
			s[j]=c-'A'+'a';
			j++;
		}else{
			if(flag==1){
				for(k=0;k<=i;k++){
					if(strcmp(s,a[k].content)==0){
						a[k].num++;
						flag=2;
						break;
					}
				}
				if(flag!=2){
					for(p=0;s[p]!='\0';p++){
						a[i].content[p]=s[p];
					}
					a[i].num=1;
					i++;
				}
				for(j=0;s[j]!='\0';j++){
					s[j]='\0';
				}
				j=0;
				flag=0;
			}
		}
	}
	qsort(a,i,sizeof(word),cmp);
	for(j=0;j<i;j++){
		printf("%s %d\n",a[j].content,a[j].num);
	}
	fclose(in);
	return 0;
} 



