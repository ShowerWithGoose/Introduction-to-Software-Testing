#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int x,y;
}point;
typedef struct{
    point st,ed;
    int len;
}line;
line l[110];
int cmp(const void*a,const void*b);
int f[100];

int main()  
{
    int n,i,j,k,num=1,flag=0;
    int x1,y1,x2,y2;
    point st,ed; 
    scanf("%d",&n);
    //struct sed *max,*nx,*t,*r; 
    //r=nx->next;
    scanf("%d%d%d%d",&l[0].st.x ,&l[0].st.y ,&l[0].ed.x ,&l[0].ed.y );
    l[0].len =1;
    for(i=1;i<n;i++)
    {
        flag=0;
        scanf("%d%d%d%d",&st.x ,&st.y ,&ed.x ,&ed.y );
        for(j=0;j<num;j++)
        {
            if(st.x ==l[j].ed.x &&st.y ==l[j].ed.y&&f[j]==0)//终止端改变 
            {
                l[j].ed.x=ed.x;
                l[j].ed.y=ed.y;
                l[j].len++;
                flag=1;
                //break;
            }
            else if(ed.x==l[j].st.x&&ed.y==l[j].st.y&&f[j]==0)//起始端改变 
            {
                l[j].st.x=st.x;
                l[j].st.y=st.y;
                l[j].len++;
                flag=2;
                //break;
            }
            if(flag==2)
            {
                for(k=0;k<num;k++)
                {
                    if(l[k].ed.x==l[j].st.x&&l[k].ed.y==l[j].st.y&&f[k]==0&&k!=j)
                    {
                        l[j].st.x=l[k].st.x;
                        l[j].st.y=l[k].st.y;
                        l[j].len++;
                        f[k]=1;
                        break;
                    }
                }
                break;
            }
            else if(flag==1)
            {
                for(k=0;k<num;k++)
                {
                    if(l[k].st.x==l[j].ed.x&&l[k].st.y==l[j].ed.y&&f[k]==0&&k!=j)
                    {
                        l[j].ed.x=l[k].ed.x;
                        l[k].ed.y=l[k].ed.y; // @@ [Logic Error: This line updates the merged segment's endpoint instead of the current segment's endpoint. It should be l[j].ed.y = l[k].ed.y to correctly extend the current chain.]
                        f[k]=1;
                        //memset(l[k].len,0,sizeof(l[0].len));
                        break;
                    }
                }
                break;
            }
        }
        if(j==num)
        {
            l[num].st=st;
            l[num].ed=ed;
            l[num].len=1;
            num++;
        }
    }
    /*for(i=0;i<num;i++)
    {
        if(f[i]==0)
        printf("%d %d %d\n",l[i].len ,l[i].st.x ,l[i].st.y );
    }*/
    qsort(l,num,sizeof(line),cmp);
    for(i=0;i<num;i++)
    {
        if(f[i]==0)
        {
            printf("%d %d %d",l[i].len ,l[i].st.x ,l[i].st.y);
            break;
        }
    }

    return 0;
}

int cmp(const void*p,const void*q){
    line *a=(line*)p,*b=(line*)q;
    if(a->len>b->len ) return -1;
    else return 1;
}