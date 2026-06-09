#include<stdio.h>
#include<string.h>
void fgetarticle(FILE *in,char s[10000]);
struct words
{
	char word[15];
	int num;
};
int getword(char s[],struct words a[]);
int cmp(const void *p1, const void *p2)
{
    struct words *x = (struct words *)p1;
    struct words *y = (struct words *)p2;
    return strcmp(x->word,y->word);
};
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	char s[10000]; 
	struct words a[2000];
	fgetarticle(in,s);
	int n;
	n=getword(s,a);
	int i,j;
	for(i=0;i<n;i++){
		if(a[i].num==1){
		    for(j=i+1;strcmp(a[i].word,a[j].word)==0;j++){
			    a[i].num+=1;
			    a[j].num-=1;
		    }
		}
	}
	for(j=0;j<n;j++){
		if(a[j].num!=0&&a[j].word[0]!=EOF){
			printf("%s",a[j].word);
			printf(" %d\n",a[j].num);
		}
	}
	return 0;
}

void fgetarticle(FILE *in,char s[10000]){
	char c;
	int i=0;
	c=fgetc(in);
	while(c!=EOF){
		s[i]=c;
		i++; 
		c=fgetc(in);
	}
	for(i=0;i<strlen(s);i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]=tolower(s[i]);
		}
	}
}
int getword(char s[],struct words a[]){
	int i,j,k,n=0,p;
	char tmp[15];
	for(i=0;i<strlen(s);i++){
		if(s[i]>='a'&&s[i]<='z'){
			k=0;
			for(j=i;j<strlen(s)&&s[j]>='a'&&s[j]<='z';j++){
				tmp[k]=s[j];
				k++;
			}
			for(p=0;p<k;p++){
				a[n].word[p]=tmp[p];
			}
			a[n].num=1;
			n+=1;
			i=j;	
		}	
	}
	qsort(a,n,sizeof(a[0]),cmp);
	return n;
}

