#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define tolower(c)  (c>='A'&&c<='Z'?'a'-'A'+ c : c)
int number[105]={},flag=0;
char word[105][105]={},s[200]={},temp[105]={};
int main(){
 FILE *in,*out;
 in=fopen("article.txt","r");
 int i=0,j=0,k=0;
 while(fgets(s,200,in)!=NULL){
  for(i=0;s[i]!='\0';i++){
   if(tolower(s[i])<'a'||tolower(s[i])>'z'){
       j=0;
       k++;
      }
      else{
    word[k][j++]=tolower(s[i]);
   }
  } 
 }
 for(i=0;i<k;i++){
  for(j=0;j<k;j++){
   if(strcmp(word[i],word[j])<=0&&strcmp(word[i],word[j])!=0){
    strcpy(temp,word[i]);
    strcpy(word[i],word[j]);
    strcpy(word[j],temp);
   }
  }
 }
 for(i=0;i<k-1;i++){
  for(j=i;j<k;j++){
   if(j==k-1)
   flag=1;
   if(strcmp(word[i],word[j])==0)
    number[i]++;
   else{
    i=j-1;
    break;
   }
   }
   if(flag==1)
   break;
  }
  if(strcmp(word[k-2],word[k-1])!=0)
  number[k-1]=1;
 for(i=1;i<k;i++){
  if(number[i]!=0){
   printf("%s %d\n",word[i],number[i]);
  }
 }
 fclose(in);
}


