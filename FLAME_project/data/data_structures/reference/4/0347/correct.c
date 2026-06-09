#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sta{
	char word[100];
	int cnt;
};
struct sta words[10000];
char cin[10000][10000];
int comp(const void *p1,const void *p2){
	struct sta *a = (struct sta*)p1;
	struct sta *b = (struct sta*)p2;
	return strcmp(a->word,b->word);
}
int main()
{
	FILE *in;
	in = fopen("article.txt","r");
	char ch;
	int i,j,k,l;
	i = 0;
	int flag;
	ch = fgetc(in);
	if(ch>='A'&&ch<='Z'){
		ch = tolower(ch);
	}
	while(ch!=EOF){
	    if(ch>='a'&&ch<='z'){
			cin[i][j] = ch;
			j++;
			flag = 1;
		}
		else{
	        if(flag==1){
		    	cin[i][j]='\0';
		    	i++;
		    	j = 0;
		    	flag = 0;
			}
	    }
		ch = fgetc(in);
		if(ch>='A'&&ch<='Z'){
			ch = tolower(ch);
		}
	}
	int len = i;
	for(i=0,k=0;i<len;i++){
		flag = 0;
		for(j=0;j<i;j++){
			if(strcmp(cin[i],cin[j])==0){
				flag = 1;
				for(l=0;l<=k;l++){
					if(strcmp(words[l].word,cin[i])==0){
						words[l].cnt++;
						break;
					}
				}
			}
			if(flag==1){
				break;
			}
	    }
			if(flag==0){
				strcpy(words[k].word,cin[i]);
				words[k].cnt = 1;
				k++;
			}
	}
	qsort(words,k,sizeof(words[0]),comp);
	for(i=0;i<k;i++){
		printf("%s %d\n",words[i].word,words[i].cnt);
	}
	fclose(in);
	return 0;
}



