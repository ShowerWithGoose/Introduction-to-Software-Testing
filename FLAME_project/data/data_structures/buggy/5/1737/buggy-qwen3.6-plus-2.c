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
    
    for(int i=0;i<n;i++) // @@ The loop bounds are swapped. 'n' is the count of terms in polynomial b, and 'm' is the count for polynomial a. The outer loop should iterate through one polynomial (e.g., b) and the inner through the other (a). Here it iterates 'n' times for b, which is correct for the outer loop if we assume i indexes b. However, the inner loop uses 'j<m' and accesses 'a[i]' and 'b[j]', which is incorrect indexing. It should be a[j] and b[i] or similar, depending on which poly is outer/inner. Specifically, if i iterates b (0 to n-1), j should iterate a (0 to m-1). The multiplication line below uses a[i] and b[j], implying i indexes a and j indexes b. But the loop limits are i<n (size of b) and j<m (size of a). This means we are iterating i up to size of b but using it as index for a, and j up to size of a but using it as index for b. This is a logical error in loop bounds vs array usage.
    {
        for(int j=0;j<m;j++) // @@ See above. If i is indexing b (0..n-1), j should index a (0..m-1). The multiplication line uses a[i] and b[j]. If i goes up to n-1, a[i] is out of bounds if n > m or just logically wrong if a has m elements. The standard approach is: for each term in B, multiply by each term in A. So outer loop i from 0 to n-1 (for b[i]), inner loop j from 0 to m-1 (for a[j]). Then product is b[i]*a[j]. The code has a[i]*b[j]. So either swap the arrays in multiplication or swap the loop variables/limits. Given the next lines use c[j], it seems j is the index for the temporary storage.
        {  
            c[j].xi=a[i].xi*b[j].xi; // @@ Logical Error: Index mismatch. If outer loop i iterates through polynomial b (size n) and inner loop j iterates through polynomial a (size m), this line accesses a[i] (out of bounds if i >= m) and b[j] (out of bounds if j >= n). It should likely be b[i].xi * a[j].xi.
            c[j].zhi=a[i].zhi+b[j].zhi; // @@ Logical Error: Same index mismatch as above. Should be b[i].zhi + a[j].zhi.
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