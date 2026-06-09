#include<stdio.h>
#include<stdlib.h>
int mark[10001];
int max=-100;
struct node{
    int a,b,c,d;
}line[10001];
int o,h,temp1,temp2,temp3,temp4;
int cmp(const void* a,const void* b);
int find(int l,int r);
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&line[i].a,&line[i].b,&line[i].c,&line[i].d);
    }
    qsort(line,n,sizeof(struct node),cmp);
    for(int i=0;i<n;i++){
        o=line[i].c;
        temp1=line[i].a; 
        h=line[i].d;
        temp2=line[i].b;
        cnt=0;
        while(find(0,n-1)){
            cnt++;
        }
        if(cnt>max){
            max=cnt;
            temp3=temp1;
            temp4=temp2;
        }
    }
    printf("%d %d %d",max+1,temp3,temp4);
    return 0;
}
int cmp(const void* a,const void* b)
{
    int* m = (int*)a; 
    int* n = (int*)b;
    return *m - * n; // @@ The comparison function is incorrect; it compares only the first integer of the struct, but qsort expects comparison of struct node objects. This leads to incorrect sorting of line segments.
}
int find(int l,int r){
    int mid=(l+r)/2;
    if(l>r){
        return 0;
    }
    if(o==line[mid].a){
        if(h==line[mid].b){
        o=line[mid].c;
        h=line[mid].d;
        return 1;
        }
        else{
            for(int i=1;line[mid+i].a==line[mid].a;i++){
                if(line[mid+i].b==h){
                o=line[mid+i].c;
                h=line[mid+i].d;
                return 1;
            }
                }
            for(int i=1;line[mid-i].a==line[mid].a;i++){
                if(line[mid-i].b==h){
                o=line[mid-i].c;
                h=line[mid-i].d;
                return 1;
                }
            }
            return 0;
        }
    }
    else if(o>line[mid].a){
        l=mid+1;
        return find(l,r);
    }
    else if(o<line[mid].a){
        r=mid-1;
        return find(l,r);
    }
    return 0;
}