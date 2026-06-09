#include<stdio.h>
#include<stdlib.h>
struct line{
    int start[2];
    int end[2];
    int flag;
    int count;
    struct line *p;
};
int compare1(const void *a,const void *b){
    struct line *str1=(struct line*)a;
    struct line *str2=(struct line*)b;
    if(str1->start [0]>str2->start [0]){
        return 1;
    }else{
        return -1;
    }
} // @@ Missing closing brace for compare1 function; the function body is not properly terminated before compare2 starts.
int compare2(const void *a,const void *b){
    struct line *str1=(struct line*)a;
    struct line *str2=(struct line*)b;
    if(str1->count<str2->count){
        return 1;
    }else{
        return -1;
    }
}
struct line string[105];
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&string[i].start[0],&string[i].start [1],&string[i].end [0],&string[i].end [1]);
        string[i].count =1;
    }
    qsort(string,n,sizeof(struct line),compare1);
    /*for(i=0;i<10;i++){
        printf("%d ",string[i].start [0]);
    }*/
    for(i=n-1;i>=0;i--){
        for(j=i+1;j<n;j++){
            if(string[i].end[0]==string[j].start [0]&&string[i].end[1]==string[j].start [1]){
                string[i].count +=string[j].count; 
            }
        }
    }
    qsort(string,n,sizeof(struct line),compare2);
    //for(i=0;i<n;i++)
    printf("%d ",string[0].count );
    printf("%d %d\n",string[0].start [0],string[0].start [1]);
    return 0;
}