#include<stdio.h>
#include<stdlib.h>
struct node{
    int hx,hy,ex,ey;
};
int function(void*a,void*b){
    struct node *pa=(struct node*)a,*pb=(struct node*)b;
    if(pa->hx<pb->hx)return 1;
    else if(pa->hx>pb->hx)return 0;
    else if(pa->hy<pb->hy)return 1;
    else if(pa->hy>pb->hy)return 0;
    else if(pa->ex<pb->ex)return 1;
    else if(pa->ex>pb->ex)return 0;
    else if(pa->ey<pb->ey)return 1;
    else if(pa->ey>pb->ey)return 0;
    else return 1;
}
void fucgsort(void*variable,const int elemsize,const int len,int (*function)(void*,void*)){
    char*va=(char*)variable,*tem[len+1],*pva[len+1],tot[len*elemsize+elemsize];
    int i=0,len1,len2,end1,end2,check,k,begin;
    while(i<len)pva[i]=va+i*elemsize,i++;//最后函数可输入NULL,若为NULL则默认int行升序
    i=1;                                 //需要stdio.h库
    while(i<len){                        //循环归并基础框架
        i<<=1;len1=begin=0;len2=i>>1;
        while(len2<len){
            k=0;end1=len2;end2=(len1+i)<=len?(len1+i):len;
            while(len1<end1&&len2<end2){
                if(function==NULL)check=*((int*)pva[len1])-*((int*)pva[len2]);
                else check=function(pva[len1],pva[len2]);
                if(check)tem[k++]=pva[len1],len1++;
                else tem[k++]=pva[len2],len2++;
            }
            while(len1<end1)tem[k++]=pva[len1],len1++;
            while(len2<end2)tem[k++]=pva[len2],len2++;
            while(k--)pva[begin+k]=tem[k];
            begin=len1=end2;len2=len1+(i>>1);
        }
    }
    for(i=0;i<len;i++)
        for(k=0;k<elemsize;k++)
            tot[k+i*elemsize]=*(pva[i]+k);
    k=elemsize*len;
    for(i=0;i<k;i++)*(va+i)=tot[i];
    return;
}
int main(){
    struct node a[103],b[103]={};
    int n=0,i,k=0,j,ans[103]={},AnS=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d%d%d",&a[i].hx,&a[i].hy,&a[i].ex,&a[i].ey);
    fucgsort(a,sizeof(struct node),n,function);
    for(i=0;i<n;i++){
        for(j=0;j<k;j++){
            if(b[j].ex==a[i].hx&&b[j].ey==a[i].hy){
                ans[j]++;b[j].ex=a[i].ex;b[j].ey=a[i].ey;
                if(ans[AnS]<ans[j])AnS=j;
                break;
            }
        }
        if(j==k){
            ans[j]++;b[j]=a[i];
            k++;
        }
    }
    printf("%d %d %d",ans[AnS],b[AnS].hx,b[AnS].hy);
    return 0;
}


