#include  <string.h>
#include  <stdio.h>

typedef struct formula{
int num;
int pownum;
struct formula *next;
};
int judge(struct formula* ans,int count){
struct formula *a=&ans[0];
for(int i=0;i<count;i++,a=a->next){
    if(a->pownum==ans[count].pownum){//幂数相同
        a->num+=ans[count].num;
        count--;
        break;
    }
    else if((i<count-1)&&(a->pownum>ans[count].pownum)&&(a->next->pownum<ans[count].pownum)){//幂数处于两者之间且不为最后一个
        ans[count].next=a->next;
        a->next=&ans[count];//插入
        break;
    }
    else if(i==count-1)
        a->next=&ans[count];
}
return count;
}
typedef struct in{
int num;
int pownum;
};
int main(){
struct in a[100];
struct in b[100];
int num1=0,num2=0;
while(scanf("%d%d",&a[num1].num,&a[num1].pownum)){
    num1++;
    char ch;
    scanf("%c",&ch);
    if(ch=='\n')
        break;
}
while(scanf("%d%d",&b[num2].num,&b[num2].pownum)!=EOF)
    num2++;//输入阶段
struct formula ans[100];
int count=0;
//a为主序
for(int i=0;i<num1;i++){
    for(int j=0;j<num2;j++){
            ans[count].num=a[i].num*b[j].num;
            ans[count].pownum=a[i].pownum+b[j].pownum;
            count=judge(ans,count);
            count++;
    }
}//生成链表
struct formula*k=&ans[0];
for(int i=0;i<count;i++){
    printf("%d %d ",k->num,k->pownum);
    k=k->next;
} //输出阶段

return 0;
}







