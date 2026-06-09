#include<stdio.h>
#include<string.h>
#include<math.h> 
void kg (char *a,char *b);
long long justfy (char *p1,char *p2);
long long fuckfy (char *p1,char *p2);
int main()
{
    char p1[1005],p2[1005];long long num[1005]={0};long long move=0;
    gets(p1);
    kg(p1,p2);
    char *e[1005];long long ei=0;
    long long u=strlen(p2);
    for(long long i=0;i<=u;i++){
        if(p2[i]=='+'||p2[i]=='-'||p2[i]=='='){
        e[ei++]=&p2[i];    
        }
    
    }

    char *p=p2;
    p--;
    *p='+'; // @@ Error: This modifies memory before the array p2, which is undefined behavior. It corrupts the stack and can cause incorrect results or crashes.
    num[0]=fuckfy(p,e[0]);
    move=num[0];
    
    for(long long j=0;j<ei-1;j++){
        
        num[j+1]=fuckfy(e[j],e[j+1]);
        if(*e[j]=='+'){
            move+=num[j+1];
        }
        if(*e[j]=='-'){
            move-=num[j+1];
        }
        
    }
    printf("%ld",move);
    
    return 0;
 } 
void kg (char *a,char *b)
{
    long long i=0,j=0;
    while(a[i]!='\0'){
        if(a[i]!=' '){
            b[j]=a[i];
            j++; 
        }
        i++;
    }
    b[j]='\0';
}
long long justfy(char *p1,char *p2)
{
 long long y=p2-p1-2,move=0; // @@ Error: The calculation of y is incorrect. For a substring between two operators, the number of digits is p2-p1-1, not p2-p1-2. This causes incorrect parsing of numbers.
    long long i=1;
    while(y>=0){
        move+=(*(p1+i)-'0')*(pow(10,y)); // @@ Error: Using pow(10, y) with floating-point may cause precision issues for large numbers. Also, the loop logic is flawed because it doesn't correctly handle the digit positions.
        i++;y--;
    }
    return move;
    
}
long long fuckfy(char *p1,char *p2)
{
    long long i=0;
    char *a[1005];long long ai=0;
    for(i=0;i<=p2-p1;i++){
        if(*(p1+i)=='+'||*(p1+i)=='-'||*(p1+i)=='*'||*(p1+i)=='/'||*(p1+i)=='=')
        {
            a[ai++]=i+p1;
        }
        }
    long long move=justfy(p1,a[1]); // @@ Error: This assumes there is always at least one operator between p1 and p2, but for the first call with p pointing to the artificial '+', a[1] may not exist or point incorrectly.
    
    for(long long j=1;j<ai-1;j++){
        if(*(a[j])=='*'){
            move=move*justfy(a[j],a[j+1]);
        }
        if(*(a[j])=='/'){
            move=move/justfy(a[j],a[j+1]);
        }
    
    }
    return move;
    
}