#include <stdio.h>
#include <ctype.h>
#include <string.h>
FILE *fp;
char line[1000];
int num=-1;
typedef struct {
	char s[1000];
	int cnt;
}*pword,Word;
int comp_word(const void *a,const void *b){
	int tmp;
	pword word1=(pword) a;
	pword word2=(pword) b;
	return strcmp(word1->s,word2->s);
}
int main(){
	Word word[1000];
	int i,j,k;
	fp=fopen("article.txt","r");
	if(fp==NULL){
		perror("No");
		return 1;
	}
	while(fgets(line,1000,fp)!=NULL){	
	for(i=0;line[i]!='\0';i++){
		if(isalpha(line[i])){
			for(j=i+1;line[j]!='\0';j++){
				if(!isalpha(line[j]))
				    break;
			}
			num++;
			for(k=i;k<j;k++){
				word[num].s[k-i]=tolower(line[k]);
		    }
			word[num].s[k-i]='\0';
			word[num].cnt=1;
			i=j;	
		}
	}	
    }
    qsort(word,num+1,sizeof(Word),comp_word);
    for(i=0;i<num;i++){
    	for(j=i+1;j<=num;j++){
    		if(strcmp(word[i].s,word[j].s)!=0)
    		    break;
    		else{
    			for(k=j;k<num;k++)
    			    word[k]=word[k+1];
    			--num;
    			word[i].cnt+=word[j].cnt;
    			--j;
			}
		}
	}
	for(i=0;i<=num;i++)
	    printf("%s %d\n",word[i].s,word[i].cnt);
    return 0;
}

