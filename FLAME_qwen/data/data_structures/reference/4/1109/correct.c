#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char ch,s[100000];
int i=0,j=0,k=0,cnt=0;
struct wo
{
    char word[300];
    int time;
}a[300];

// char fetart(FILE *in){


// return s[100000];
// }
int cmp(const void*p1,const void *p2)
{
	struct wo *a=(struct wo *)p1;struct wo *b=(struct wo *)p2;
	return strcmp(a->word,b->word);
}
// void getword(char s[]){
//     char tmp[100000];


//     for(i=0;i<strlen(s);i++){
//         if(isalpha(s[i])){
//           for(j=i;j<strlen(s);j++) {
//              if(!isalpha(s[j])) //遇到非字母的元素 
//              { break; 
//              }
//           }
//           for(k=0;k<j-i;k++) { tmp[k]=s[i+k]; //存储单词 
//           }strcpy(a[cnt].word,tmp); 
//           //拷贝单词
//            cnt++; i=j;
//         }
        
//     }
//     qsort(a,cnt,sizeof(),cmp)
// }

int main(){
    FILE *in,*out;
in=fopen("article.txt","r");
    ch=fgetc(in);
    i=0; while(ch!=EOF) { 
    s[i]=ch; 
    i++; 
    ch=fgetc(in); 
    }
    for(i=0;i<strlen(s);i++) { 
        if(isalpha(s[i]))
         s[i]=tolower(s[i]); //全部转化为小写 }
}

for(i=0;i<strlen(s);i++){
    if(isalpha(s[i])){
        a[cnt].word[j]=s[i];
    j++;
    }
    else if(strlen(a[cnt].word)){
        a[cnt].time=1;cnt++;j=0;
    }
}
qsort(a,cnt,sizeof(a[0]),cmp);
for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0)
		a[i+1].time+=a[i].time;
		else if(strlen(a[i].word))
		printf("%s %d\n",a[i].word,a[i].time);
	}
	return 0;


}

