#include <stdio.h>
#include <stdlib.h>
#define max 1024

typedef struct{
    int xishu;
    int xiangshu;
}multi;

multi exp1[max],exp_2[max],temp[max];

int tempsize;

void move(int pos){
    int i;
    for (i=pos;i<tempsize;i++){
        temp[i].xiangshu=temp[i+1].xiangshu;
        temp[i].xishu=temp[i+1].xishu;
    }
    tempsize--;
}

int cmp(const void *a,const void *b){
    return -(*(multi *)a).xiangshu+(*(multi *)b).xiangshu;
}

int main()
{
    int i,j,k,l,m,s,t;
    char ch,ch2;

    for (i=0;ch!='\n';i++)
        scanf ("%d %d%c",&exp1[i].xishu,&exp1[i].xiangshu,&ch);//i是输入个数 0 1 2 i=3

    for (j=0;ch2!='\n';j++)
        scanf ("%d %d%c",&exp_2[j].xishu,&exp_2[j].xiangshu,&ch2); //01234 j=5 总15-1

    for (k=0;k<i;k++){
        for (l=0;l<j;l++){
            temp[tempsize].xiangshu=exp1[k].xiangshu+exp_2[l].xiangshu;
            temp[tempsize].xishu=exp1[k].xishu*exp_2[l].xishu;
            tempsize++;
        }
    }

    for (s=0;s<tempsize-1;s++){
        for (t=s+1;t<tempsize;t++){
            if (temp[t].xiangshu==temp[s].xiangshu){
                temp[s].xishu+=temp[t].xishu;
                move(t);
            }
        }
    }

    qsort(temp,tempsize-1,sizeof(temp[0]),cmp);

    for (m=0;m<tempsize;m++){
        printf ("%d %d ",temp[m].xishu,temp[m].xiangshu);
    }


    return 0;
}

