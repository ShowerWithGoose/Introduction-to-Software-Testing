#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[100];
char a[20];
struct item{
	char word[20];
	int num;
}list[200];
char mk[200];
void insert(char s[]){
	for(int i=0;i<strlen(s);i++){
		s[i]='0'+i%10;
	}
}
void si(char s[],int a){
	printf("%s %d\n",s,a);
}
int main(){
	int cnt=0;
	int flag;
	int i,j;
	struct item temp;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(s,100,in)!=NULL){
		insert(mk);
		for(int i=0;i<strlen(s);i++){
			if('A'<=s[i]&&s[i]<='Z') s[i]=s[i]+'a'-'A';
		}
		for(i=0;i<strlen(s);i++){
			if('a'<=s[i]&&'z'>=s[i]){
			    insert(mk);
				for(j=i;'a'<=s[j]&&'z'>=s[j];j++){
					a[j-i]=s[j];
				}	
			
			    i=j;
			    for(int k=0;k<=cnt;k++){
				    if(strcmp(list[k].word,a)==0) {
					    list[k].num++;
					    break;
				    }
				    else if(list[k].word[0]=='\0'){
					    strcpy(list[k].word,a);
					    list[k].num=1;
					    cnt++;
					    break;
				    }
			    }
			    memset(a,'\0',sizeof(a));
			}
		}
	}
	for(i=0;i<cnt;i++){
		for(j=i;j<cnt;j++){
			if(strcmp(list[i].word,list[j].word)>0){
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
	}
	for(i=0;i<cnt;i++) {
		si(list[i].word,list[i].num);
    }
    fclose(in);
    return 0;
}
