#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct word{
    char name[50];
    int p;
};

int check(char c){
    if(c>='a'&&c<='z'||c>='A'&&c<='Z')  return 1;
    else return 0;
}

int getword(char a[],FILE *fp){  //从文件中读取英文单词
    int i=0;
    char c;
    while(check(c=fgetc(fp))==0){
        if(c==EOF)  return c;
        else continue;
    }
    a[i]=tolower(c);
    while(check(c=fgetc(fp))==1){
        a[++i]=tolower(c);
    }
    a[i+1]='\0';
    return 1;
}

int search(struct word list[],int n,char a[]){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(list[i].name,a)==0){
            return i;
        }
    }
    if(i==n)  return -1;
}

void pai(struct word list[],int n){
    int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			struct word tmp;
			if(strcmp(list[i].name,list[j].name)>0){
				tmp=list[i];
				list[i]=list[j];
				list[j]=tmp;
			}
		}
	}
}

int main(){
    FILE *fp;
    struct word list[1000];
    char a[50];
    int i,n=0;
    if((fp=fopen("article.txt","r"))==NULL){
		printf("Cann't open file:%s!\n","article");
		return -1;
    }
    while(getword(a,fp)!=EOF){
        if(search(list,n,a)==-1){
            strcpy(list[n].name,a);
            list[n].p=1;
            n++;
        }
        else{
            list[search(list,n,a)].p++;
        }
    }
    pai(list,n);
    for(i=0;i<n;i++){
        printf("%s %d\n",list[i].name,list[i].p);
    }
    fclose(fp);
    return 0;
}
