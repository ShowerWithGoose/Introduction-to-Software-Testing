#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct word{
	char c[40];
}Word[2000];
int cmp( void* s1, void* s2){
	struct word *C=(struct word *)s1;
	struct word *D=(struct word *)s2;
	if (strcmp((*C).c,(*D).c)!=0) return strcmp((*C).c,(*D).c);
	
}
/*void replace(struct word Word[],int k){
	char temp[40];
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(strcmp(Word[i].c,Word[j].c)>0){
				strcpy(temp, Word[j].c);
                strcpy(Word[j].c, Word[i].c);
                strcpy(Word[i].c, temp);
			}
		}
	}
}*/
int main()
{
	FILE *fp=fopen("article.txt","r");
	int k=0,kk=0;
	char ch;
	while((ch=fgetc(fp))!=EOF){
		if(isalpha(ch)){
			Word[k].c[kk]=ch;
			kk++;
		}
		else if (ispunct(ch) || isspace(ch)){
			Word[k].c[kk]='\0';
			kk=0;
			k++;
		}
	}
	//±‰–°–¥ 
	for(int i=0;i<k;i++){
		for(int j=0;j<40;j++){
			if(Word[i].c[j]>='A' && Word[i].c[j]<='Z'){
				Word[i].c[j]=Word[i].c[j]-'A'+'a';
			}
		}
	}
	
		qsort(Word,k,sizeof(struct word),cmp);
	/*for(int i=0;i<k;i++){
		replace(Word,k);
	}*/
	//≈≈–Ú
	
	int num=1;
	int flag[2000];
	for(int i=1;i<2000;i++) flag[i]=0;
	flag[0]=-1;
	int i=0;
	//for(i=0;i<k;i++) printf("%s\n",Word[i].c);

	num=1;
	for(int i=0;i<k;i++){
		num=1;
		if(flag[i]==-1) ;
		else{
		
		for(int j=i+1;j<k;j++){
			if(strcmp(Word[i].c,Word[j].c)==0){
				num++;
				flag[j]=-1;
				}
		}
			if(Word[i].c[0]!=' ' && Word[i].c[0]!='\0')
				printf("%s %d\n",Word[i].c,num);
				flag[i]=-1;
			
		}
	}
	/*	if(Word[i].c[0]!=' ' && Word[i].c[0]!='\0')
		printf("%s %d\n",Word[i].c,num);
		flag[i]=-1;
		for(int j=k-1;j>=i+1;j--){
			if(flag[j]==-1) {
				i=j+1;
				flag[i]=-1;
				num=1;
				break;
			}
		}*/
		
		
	
	fclose(fp);
	return 0;
}

