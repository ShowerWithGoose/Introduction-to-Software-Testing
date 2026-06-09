#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct worfrey{
	char word[100];
	int number;
};

void sort(struct worfrey x[],int y);
int main(){
	FILE *fp;
	fp=fopen("article.txt","r");
	if(fp==NULL){
		printf("Can't open the file!\n");
		return -1;
	}
	char f[1024],s[1000][100];
	struct worfrey w[1000];
	int i,j,k=0,l=0,m,n,flag=0;
	while(fgets(f,1023,fp)!=NULL){
		n=strlen(f);
		for(i=0;i<n;i++){
			if(isupper(f[i]))
				f[i]=tolower(f[i]);
		}
		
		for(i=0;i<n;i++){
			if(isalpha(f[i])){
				for(j=i;isalpha(f[j]);j++){
					s[l][j-i]=f[j];
				}
				s[l][j-i]='\0';
				l++;
				i=j;
				for(m=0;m<k;m++){
					if(strcmp(w[m].word,s[l-1])==0){
						w[m].number++;
						flag++;
						break;
					}
				}
				if(flag==0){
					strcpy(w[k].word,s[l-1]);
					w[k].number++;
					k++;
				}
				flag=0;
			}
		}
	}
	sort(w,k);
	for(i=0;i<k;i++){
		printf("%s %d\n",w[i].word,w[i].number);
	}
	fclose(fp);
	return 0;
}

void be_low(char fl[]){
	
}
void sort(struct worfrey x[],int y){
	int i,j;
	struct worfrey temp;
	for(i=0;i<y;i++){
		for(j=i;j<y;j++){
			if(strcmp(x[i].word,x[j].word)>0){
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}

