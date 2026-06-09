#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1};
    char ch2[20]={'0'};
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i);
        if(ch1[i]!=-1){ // @@ This condition fails if the input number is -1, causing incorrect indexing and potentially skipping a number.
            i++;
        }
        scanf(" %c",ch2+j);
        if(ch2[j]!='0'){ // @@ This condition fails if the operator is '0', which is unlikely but still a logical error. Also, the initial value '0' is not a safe sentinel.
            j++;
        }
        if(ch2[j-1]=='='){
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){ // @@ The loop should only process operators up to len-1 (excluding '='), but it processes all len operators. When i = len-1, the operator is '=', and accessing ch1[i+1] is out-of-bounds if len equals the array size (20) and always reads an uninitialized element.
            if(ch2[i]=='/'){
                x1/=ch1[i+1];
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1); // @@ This debug output prints intermediate results, which is not allowed by the problem specification. It produces extra output.
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ Treating '=' as '+' is logically incorrect; the '=' should not be processed as an operator. This also leads to accessing ch1[i+1] when i is the last index.
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ When i = len-1, this accesses ch1[len] which is out-of-bounds (if len == 20) or contains an uninitialized value.
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ Same out-of-bounds issue when i = len-1.
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1];
            }
            
        }
        printf("%d",sum);
        return 0;

}