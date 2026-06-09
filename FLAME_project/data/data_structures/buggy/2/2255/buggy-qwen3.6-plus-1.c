#include<stdio.h>
#include<string.h>
#include<ctype.h>
char in[10000];
int num[10000];
int op[10000],post[1000];
void delete(int a[],int *n,int i) //传的是第几个 不是下标 
{
    for(int j=i;j<*n;j++) a[j-1]=a[j];
    (*n)--;
}
int calc(int a,int op,int b)  //-1= +  -2= -  -3= *  -4= /
{
    if(op==-1)return a+b;
    if(op==-2)return a-b;
    if(op==-3)return a*b;
    if(op==-4)return a/b;
}
int main()
{
    int i=0,j=0;    
    gets(in);
    for(int i=0;i<strlen(in);i++) //去空格 
    {
        if(in[i]!=' ')
        {
            in[j++]=in[i];    
        }
    }
    if(in[j-1]!='=')in[j++]='=';
    in[j]='\0';

    i=0,j=0; 
    int cnt=0;
    int cnum=0,pt=0;
    for(;in[pt]!='\0';pt++)  //数字和运算符分别存到num op 
    {
        if(isdigit(in[pt]))
        {
            cnum=10*cnum+in[pt]-'0';
        }
        else
        {
            num[i++]=cnum;
            cnum=0;
            cnt++;
            if(in[pt]=='+') op[j++]=-1;
            if(in[pt]=='-') op[j++]=-2;
            if(in[pt]=='*') op[j++]=-3;
            if(in[pt]=='/') op[j++]=-4;
        }
    }
    int opcnt=cnt-1;
    for(i=0;i<opcnt;)
    {
        if(op[i]==-4)
        {
            num[i]=calc(num[i],-4,num[i+1]);
            delete(num,&cnt,i+2); // @@ The delete function shifts elements left starting from index i (1-based logic applied to 0-based array incorrectly or inconsistent with usage). Specifically, delete(num, &cnt, i+2) attempts to remove the operand at index i+1 (the second operand). However, the implementation `a[j-1]=a[j]` starting at `j=i` effectively removes the element at `i-1` if interpreted as 1-based, or shifts incorrectly. More critically, after calculating `num[i] = num[i] op num[i+1]`, we need to remove `num[i+1]` and shift subsequent numbers left. The current delete logic is flawed for maintaining alignment between `num` and `op` arrays when indices are shifted. The standard approach is to shift `num` from `i+2` onwards to `i+1`, and `op` from `i+1` onwards to `i`. The custom delete function here is error-prone. Let's look closer: `delete(num, &cnt, i+2)` calls delete with index `i+2`. Inside delete: `for(j=i+2; j<*n; j++) a[j-1]=a[j]`. This shifts `a[i+2]` to `a[i+1]`, `a[i+3]` to `a[i+2]`, etc. This correctly removes the element at original index `i+1` (which was `num[i+1]`) from the perspective of the array storage if we consider that `num[i]` has been updated. Wait, `num[i]` is the result. `num[i+1]` is the consumed operand. We want to remove `num[i+1]`. Shifting `i+2` to `i+1` does exactly that. So `delete(num, &cnt, i+2)` is actually correct for removing the second operand. Similarly `delete(op, &opcnt, i+1)` shifts `op[i+1]` to `op[i]`, removing the operator. This seems logically okay for removal. 
            // However, there is a major logical error in the order of operations. The problem requires standard precedence: * and / before + and -. The code processes / first, then *, then -, then +. This is incorrect because * and / have equal precedence and should be processed left-to-right. By processing all / first, then all *, it violates left-to-right associativity for mixed * and / expressions. For example, 10 / 2 * 3 should be (10/2)*3 = 15. If we process / first: 10/2=5, then 5*3=15. This works. But 10 * 2 / 5 should be (10*2)/5 = 4. If we process / first: it sees no / initially? No, it scans left to right. 
            // Let's trace 24 / 4 / 3 / 2. 
            // Pass 1 (/): i=0, op[0]=-4. num[0]=24/4=6. Delete num[1], op[0]. Array becomes num: [6, 3, 2...], op: [-4, -4...]. i stays 0.
            // Next loop i=0. op[0]=-4. num[0]=6/3=2. Delete num[1], op[0]. Array becomes num: [2, 2...], op: [-4...]. i stays 0.
            // Next loop i=0. op[0]=-4. num[0]=2/2=1. Delete num[1], op[0]. Array becomes num: [1...], op: [...]. i stays 0.
            // Loop ends. Result 1. Correct for this part.
            
            // Now consider the interaction with *. The code does ALL divisions first, then ALL multiplications.
            // Expression: 10 * 20 * 30 * 40 / 40 / 30
            // Initial nums: 10, 20, 30, 40, 40, 30. Ops: *, *, *, /, /
            // Pass 1 (/):
            // i=0 (*), skip. i=1 (*), skip. i=2 (*), skip. i=3 (/). 
            // num[3] = 40 / 40 = 1. Delete num[4] (40), op[3] (/).
            // Nums: 10, 20, 30, 1, 30. Ops: *, *, *, /
            // i stays 3. op[3] is now / (the second one).
            // num[3] = 1 / 30 = 0. Delete num[4] (30), op[3] (/).
            // Nums: 10, 20, 30, 0. Ops: *, *, *
            // Pass 2 (*):
            // i=0 (*). num[0] = 10 * 20 = 200. Delete num[1], op[0].
            // Nums: 200, 30, 0. Ops: *, *
            // i stays 0. op[0] = *.
            // num[0] = 200 * 30 = 6000. Delete num[1], op[0].
            // Nums: 6000, 0. Ops: *
            // i stays 0. op[0] = *.
            // num[0] = 6000 * 0 = 0.
            // Result 0.
            // Expected: 10*20*30*40/40/30 = 240000 / 40 / 30 = 6000 / 30 = 200.
            // The error is that division happened before multiplication in a way that consumed operands incorrectly relative to left-to-right evaluation of equal precedence operators? 
            // Actually, 10*20*30*40/40/30. Left to right:
            // 10*20=200
            // 200*30=6000
            // 6000*40=240000
            // 240000/40=6000
            // 6000/30=200.
            
            // The code's strategy of "all / then all *" is fundamentally flawed for mixed expressions because it doesn't respect left-to-right ordering across different operator types of same precedence. It prioritizes / over * globally instead of locally.
            
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;)
    {
        if(op[i]==-3)
        {
            num[i]=calc(num[i],-3,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;)
    {
        if(op[i]==-2)
        {
            num[i]=calc(num[i],-2,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    for(i=0;i<opcnt;)
    {
        if(op[i]==-1)
        {
            num[i]=calc(num[i],-1,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    printf("%d\n",num[0]);
        
    return 0;
}