#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct s{
		char word[50];
		int num;
	}l[50];
int search(char *a , int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(a,l[i].word) == 0){
			l[i].num++;
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
            if (strcmp(l[i].word, l[j].word) > 0)
            {
                strcpy(temp, l[j].word);
                strcpy(l[j].word, l[i].word);
                strcpy(l[i].word, temp);
                k=l[j].num;
                l[j].num=l[i].num;
                l[i].num=k;
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
		l[m].num=0;
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
					l[i].word[m]=a[m];
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
		squrt(l[i].word,n);
	}
	for(i=2;i<=n;i++){
		if(l[i].word[0]!=' '){
			printf("%s %d\n",l[i].word,l[i].num+1);
		}
	}
	fclose(in);
 	return 0;
}


