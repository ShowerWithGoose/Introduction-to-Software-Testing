#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct s{
		char word[50];
		int num;
	}word[50];
int search(char *a , int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(a,word[i].word) == 0){
			word[i].num++;
			return 0;
		}
	}
	return 1;
}
void squrt(char *a,int n){
	char temp[20];
	int i,j,k;
    for (i = 0; i <=n; i++)
    {
        for (j = i + 1; j <=n; j++)
        {
            if (strcmp(word[i].word, word[j].word) > 0)
            {
                strcpy(temp, word[j].word);
                strcpy(word[j].word, word[i].word);
                strcpy(word[i].word, temp);
                k=word[j].num;
                word[j].num=word[i].num;
                word[i].num=k;
            }
        }
    }
}
int main()
{
	char c,a[50];
	int i=0,j=0,n,m,flag=0;
	FILE *in;
	in=fopen("article.txt","r");
	for(m=0;m<50;m++){
		word[m].num=0;
	}
	c=fgetc(in);
	while(c!=EOF){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
			c=tolower(c);
			a[j]=c;
			j++;
		}
		else{
			if(search(a,i)==1){
				for(m=0;m<=j;m++){
					word[i].word[m]=a[m];
				}
				i++;
			}
			j=0;
			for(m=0;m<50;m++){
				a[m]='\0';
			}
		}
		c=fgetc(in);
	} 
	n=i;
	for(i=0;i<=n;i++){
		squrt(word[i].word,n);
	}
	for(i=2;i<=n;i++){
		if(word[i].word[0]!=' '){
			printf("%s %d\n",word[i].word,word[i].num+1);
		}
	}
	fclose(in);
 	return 0;
}


