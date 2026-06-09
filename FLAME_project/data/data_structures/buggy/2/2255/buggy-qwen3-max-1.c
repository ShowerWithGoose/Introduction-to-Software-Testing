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
    if(in[j-1]!='=')in[j++]='='; // @@ [This line incorrectly appends '=' if not present, but the problem guarantees input ends with '=', so this may cause duplication or misalignment. However, the real issue is elsewhere.]
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
    int opcnt=cnt-1; // @@ [This is wrong: 'cnt' counts the number of operators, but also equals the number of numbers. So opcnt should be cnt, not cnt-1. Because for n numbers there are n-1 operators, but here 'cnt' is incremented per operator, so after loop, cnt = number of operators, and i = number of numbers = cnt + 1. Thus opcnt should be cnt, not cnt-1. This causes the later loops to process fewer operators than needed.]

    for(i=0;i<opcnt;) // @@ [Because opcnt is too small (off by one), this loop and subsequent ones skip the last operator(s).]
    {
        if(op[i]==-4)
        {
            num[i]=calc(num[i],-4,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;) // @@ [Same issue: opcnt is incorrect, so multiplication may not be fully processed.]
    {
        if(op[i]==-3)
        {
            num[i]=calc(num[i],-3,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;) // @@ [Addition and subtraction processing is also affected by wrong opcnt. Moreover, processing subtraction before addition changes associativity and breaks left-to-right evaluation for same-precedence operators. The correct approach is to process all * and / first (left to right), then + and - left to right. But here, subtraction is processed separately before addition, which can lead to wrong order when mixed. For example, "100 - 50 - 40" becomes (100 - 50) = 50, then 50 - 40 = 10 if done left-to-right. But if you process all '-' first in a single pass left-to-right, it's okay — however, the bigger issue is that after processing * and /, the remaining expression should be evaluated strictly left to right for + and -, but this code processes all '-' first, then all '+', which is incorrect. For instance, "10 - 5 + 3" would become: process '-' → 10-5=5, then array is [5,3] with op [+], then process '+' → 8. That actually works. But consider "10 + 5 - 3": process '-' first? There is no '-' at first index, so i increments, then later in '+' loop, it does 10+5=15, then 15-3? No — because after processing '+', the '-' operator is gone? Actually, no: the structure is flawed because after processing * and /, the op array contains only + and -, but then the code processes all '-' in one full pass, then all '+' in another. This breaks left-to-right associativity. Example: "1 - 2 + 3". Correct: (1-2)+3 = 2. But this code: first processes '-' at i=0: num[0]=1-2=-1, then deletes num[1] and op[0], so now num=[-1,3], op=[+]. Then in '+' loop: -1+3=2 → correct. Another: "1 + 2 - 3": no '-' at i=0, so i++ (but opcnt=1, so loop ends). Then in '+' loop: i=0, op[0]==+, so num[0]=1+2=3, delete num[1] and op[0], now num=[3], op empty. The '-' was never processed! Because after the first loop (for '-'), it didn't find '-' at i=0, so i became 1, but opcnt=1, so i<opcnt fails (1<1 false). So the '-' is skipped. Hence, the order of processing (- then +) is wrong. It should process + and - together in a single left-to-right pass.]
    {
        if(op[i]==-2)
        {
            num[i]=calc(num[i],-2,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    for(i=0;i<opcnt;) // @@ [As explained above, processing '+' after '-' misses cases where '+' comes before '-' in the original left-to-right sequence, because the '-' loop may have advanced i past a '+' that should be processed earlier, or more critically, the separate passes break the left-to-right evaluation order required for same-precedence operators. The correct method is to evaluate all remaining operations (after * and /) strictly left to right in a single pass.]
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