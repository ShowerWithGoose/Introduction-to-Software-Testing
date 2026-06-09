#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct code {
       int xi;
       int zhi;
       struct code* link;
   };
       int m=0,n=0;
   struct code a[1000],b[1000],c[1000];
int main()
{
    struct code *head,*p,*q,*p0;
    head = p = NULL;
   scanf("%d%d",&a[m].xi,&a[m].zhi);
   for(m=1;getchar()!='\n';m++)
   {
       scanf("%d%d",&a[m].xi,&a[m].zhi);
   }
   
   scanf("%d%d",&b[n].xi,&b[n].zhi);
   for(n=1;getchar()!='\n';n++)
   {
       scanf("%d%d",&b[n].xi,&b[n].zhi);
   }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {  
            c[j].xi=a[i].xi*b[j].xi; // @@ [Incorrect indexing: should be a[j] and b[i] or consistent with loop variables; current logic uses a[i] with b[j] but outer loop is over i (b) and inner over j (a), yet a has m terms and b has n terms, so a[i] is out-of-bounds when i >= m]
            c[j].zhi=a[i].zhi+b[j].zhi; // @@ [Same indexing error: a[i] may access beyond valid range of array a which has m elements indexed 0 to m-1, but i goes up to n-1 which may be larger than m]
        }

        if(i==0)
        {
        for(int j=0;j<m;j++)
        {
        q =  (struct code *)malloc(sizeof(struct code));
        q->xi=c[j].xi; q->zhi=c[j].zhi; q->link = NULL;
        if( head == NULL) ///////////////////////////////////////////////////////////////////初始化？ 
             head = p = q;
        else {
            p->link = q;
            p = p->link;
                }
           }
       }
   else{
    for(int j=0;j<m;j++)
    { //将第二个多项式的每个项插入到第一个多项式链表中
        
        q = (struct code *)malloc(sizeof(struct code));
        q->xi=c[j].xi; q->zhi=c[j].zhi; q->link= NULL;
        p0=head;
        for(p=head; p!=NULL; p0=p,p=p->link) {
            if(q->zhi > p->zhi)
             { 
                 if(p==head) {
                  q->link= head; 
                  head = q;
                  break; }//插入到头节点前
                 else { 
                 q->link= p; 
                 p0->link=q; 
                 break;} //将q插入到p前
            }
            else if(q->zhi == p->zhi)  
            { p->xi+= q->xi; 
            break;}//指数相等，系数相加
         }
         if(p==NULL)  
         p0->link= q;   //将q插入到尾节点后
    } 
}
    
    
    }
    for(p=head; p!=NULL; p=p->link)
         {
         printf("%d %d ", p->xi,p->zhi);
         }
    return 0;
}