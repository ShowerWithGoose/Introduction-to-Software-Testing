#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define Maxword 50
#define Maxsize 1000
int getword(char a[],FILE *in);
int searchword(char a[],int len);
void insertword(char a[],int len);
void Strset(char a[],char b,int len);
struct Dic{
	char word[Maxword];
	int count;
}dic[Maxsize];
char a[Maxword];
int N=0;
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	while(getword(a,in)){
		if(searchword(a,N)!=-1){
			dic[searchword(a,N)].count++;
		}
		else{
			insertword(a,N);
			N++;
		}
		Strset(a,'\0',Maxword);
	}
	for(int i=0;i<N;i++){
	    printf("%s %d\n",dic[i].word,dic[i].count);
	}
	fclose(in);
	return 0;
}
int getword(char a[],FILE *in){
	char ch,*p;
	int n=0;
	p=a;
	ch=fgetc(in);
	if(ch==EOF) return 0;
	while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))) {
		ch=fgetc(in);
		if(ch==EOF) return 0;
	}
	while ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
		if(ch>='A'&&ch<='Z'){
			ch=ch-'A'+'a';
		}
		*p++=ch;
		n++;
		ch=fgetc(in);
	}
	return 1;
}
int searchword(char a[],int len){
	int low,mid,high;
	low=0;high=len-1;mid=(low+high)/2;
	while(low<=high){
		if(strcmp(a,dic[mid].word)>0){
			low=mid+1;
		}
		else if(strcmp(a,dic[mid].word)<0){
			high=mid-1;
		}
		else{
			return mid;
		}
		mid=(low+high)/2;
	}
	return -1;
}
void insertword(char a[],int len){
	int i,low=0,mid,high=len-1;
	struct Dic p,temp,add;
	strcpy(add.word,a);
	add.count=1;
	mid=(low+high)/2;
	while(low+4<=high){
		if(strcmp(a,dic[mid].word)>0){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	for(i=low;i<=high;i++){
		if(strcmp(a,dic[low].word)>0){
			low++;
		}
	}
	temp=dic[low];dic[low]=add;
	for(i=low+1;i<=len;i++){
		p=dic[i];dic[i]=temp;temp=p;
	}
}
void Strset(char a[],char b,int len){
	for(int i=0;i<len;i++){
		a[i]=b;
	}
}



