#include<stdio.h>
#include<string.h>

#define maxsive 10000
#define OK 1
#define Fail -1
#define maxline 1024

typedef struct ElemType{
    char word[50];
    int times;
}ElemType;
ElemType list[maxsive];
int length=0;

int searchitem_judge(ElemType*,char*);
int insertItem(ElemType*,char*);
int searchitem(ElemType*,char*);
void change(char*);
int main()
{
    int times[maxsive];
    char item[30]="";
    char line[maxline]="";

        FILE *in;
        in=fopen("article.txt","r");
    int i=0;
    while(fgets(line,maxline-1,in)!=NULL){
        int judging=0,count=0;
        for(int j=0;j<strlen(line);j++){
            if(line[j]>='a'&&line[j]<='z'){ // @@ Only checks for lowercase letters, ignoring uppercase letters which should be part of words and converted to lowercase.
                if(judging==0){
                    judging=1;
                    item[count++]=line[j];
                }
                else{
                    item[count++]=line[j];
                }
            }
            else{
                if(judging==0){
                    continue;
                }
                else{
                    judging=0;
                    
                    change(item); // @@ 'item' is not null-terminated before calling change() and strlen(), causing undefined behavior. Need to add item[count] = '\0'; before this line.
                    int length0=strlen(item);
                    
                    int judge=searchitem_judge(list,item);
                    if(judge==Fail){
                        insertItem(list,item);
                    }
                    else{
                        list[judge].times+=1;
                    }
                    for(int t=0;t<length0;t++){
                        item[t]='\0';
                    }
                    count=0;
                }
            }
        } // @@ If a line ends with a letter, the last word is not processed. Need to check if judging==1 after the for loop and process the remaining word.
    }
        fclose(in);
    for(int j=0;j<length;j++){
        printf("%s %d\n",list[j].word,list[j].times);
    }
    return 0;
}

int searchitem_judge(ElemType* list,char* item){
    int low=0;
    int high=length-1;
    int mid=0;
    while(low<=high){
        mid=(high+low)/2;
        if(strcmp(item,list[mid].word)>0){
            low=mid+1;
        }
        else if(strcmp(item,list[mid].word)<0){
            high=mid-1;
        }
        else{
            return mid;
        }
    }
    return Fail;
}
int searchitem(ElemType* list,char* item){
    int low=0;
    int high=length-1;
    int mid=0;
    while(low<=high){
        mid=(high+low)/2;
        if(strcmp(item,list[mid].word)>0){
            low=mid+1;
        }
        else if(strcmp(item,list[mid].word)<0){
            high=mid-1;
        }
        else{
            return mid;
        }
    }
    return low;
}
int insertItem(ElemType* list,char* item){
    int i=0;
    if(length==maxsive) return -1;
    i=searchitem(list,item);
    for(int j=length-1;j>=i;j--){
        list[j+1]=list[j];
    }
    strcpy(list[i].word,item);
    list[i].times=1;
    length+=1;
    return OK;
}
void change(char* item){
    for(int i=0;i<strlen(item);i++){
        if(item[i]>='A'&&item[i]<='Z'){
            item[i]=item[i]-'A'+'a';
        }
        else{
            continue;
        }
    }
}