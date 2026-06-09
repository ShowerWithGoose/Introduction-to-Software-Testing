#include  <string.h>
#include  <stdio.h>

typedef struct formula{
int num;
int pownum;
struct formula *next;
};
int judge(struct formula* outco,int num){
struct formula *coefficient1=&outco[0];
for(int i=0;i<num;i++,coefficient1=coefficient1->next){
    if(coefficient1->pownum==outco[num].pownum){//幂数相同
        coefficient1->num+=outco[num].num;
        num--;
        break;
    }
    else if((i<num-1)&&(coefficient1->pownum>outco[num].pownum)&&(coefficient1->next->pownum<outco[num].pownum)){//幂数处于两者之间且不为最后一个
        outco[num].next=coefficient1->next;
        coefficient1->next=&outco[num];//插入
        break;
    }
    else if(i==num-1)
        coefficient1->next=&outco[num];
}
return num;
}
typedef struct in{
int num;
int pownum;
};
int main(){
struct in coefficient1[100];
struct in coefficient2[100];
int num1=0,num2=0;
while(scanf("%d%d",&coefficient1[num1].num,&coefficient1[num1].pownum)){
    num1++;
    char ch;
    scanf("%c",&ch);
    if(ch=='\n')
        break;
}
while(scanf("%d%d",&coefficient2[num2].num,&coefficient2[num2].pownum)!=EOF)
    num2++;//输入阶段
struct formula outco[100];
int num=0;
//a为主序
for(int i=0;i<num1;i++){
    for(int j=0;j<num2;j++){
            outco[num].num=coefficient1[i].num*coefficient2[j].num;
            outco[num].pownum=coefficient1[i].pownum+coefficient2[j].pownum;
            num=judge(outco,num);
            num++;
    }
}//生成链表
struct formula*outin=&outco[0];
for(int i=0;i<num;i++){
    printf("%d %d ",outin->num,outin->pownum);
    outin=outin->next;
} //输出阶段

return 0;
}







