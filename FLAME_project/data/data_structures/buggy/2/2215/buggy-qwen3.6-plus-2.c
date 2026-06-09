#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s0[200]={'\0'},s[200]={'\0'};
    int record1=0,record2=0;
    gets(s0);
    for(int i=0,j=0;s0[i]!='\0';i++)
    {
        if(s0[i]!=' ')
        {
            s[j]=s0[i];
            if(s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='*'||s[j]=='/'||s[j]=='=')
                record1++; 
            if(s[j]=='+'||s[j]=='-'||s[j]=='=')
                record2++;
            j++;
        }
    }
    int NUM[200]={0},num[200]={0},i=0;
    for(int j=1;j<=record1;j++)
    {
        int flag=0;
        for(;s[i]!='=';i++)
        {
            if(flag==0&&s[i]>='0'&&s[i]<='9')
            {
                num[j]=s[i]-'0';
                flag=1;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                num[j]=10*num[j]+s[i]-'0';
            }
            else
            {
                i++; // @@ The index `i` is incremented here to skip the operator, but the outer loop also increments `j` and expects the next number. However, the critical error is in the logic of how numbers are associated with operators. The current parsing logic stores numbers in `num` indexed by the count of operators seen so far (`j`). This mapping is fragile and incorrect for the subsequent calculation steps which rely on `count1`.
                flag=0;
                break;
            }
        }
    }//记所有小数 
    int count1,count2,count;
    for(i=0,count1=0,count2=0;s[i]!='\0';i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
            count1++;//记现在出现的小数 
        if(s[i]=='*')
        {
            num[count1+1]*=num[count1]; // @@ Logic Error: The indices for `num` are incorrect. `count1` is incremented *before* this check when an operator is found. If `s[i]` is `*`, `count1` represents the number of operators encountered up to and including this one. The operands for this `*` are not correctly aligned with `num[count1]` and `num[count1+1]` due to the flawed parsing and indexing strategy. Specifically, `num` was filled based on `j` (operator count) in the previous loop, but here `count1` is used. Even if they matched, `num[count1]` would be the number *before* the operator and `num[count1+1]` the number *after*. But standard precedence requires processing `*` and `/` first. This line attempts to do that but modifies `num` in place. The real issue is that `num` array values are being overwritten incorrectly or accessed with wrong indices relative to the parsed data. For `10 + 20 * 30`, when `*` is at index `count1=2` (assuming `+` is 1, `*` is 2), it tries `num[3] *= num[2]`. `num[2]` is 20, `num[3]` is 30. Result 600. This part might seem okay for simple cases, but the accumulation into `NUM` below is where it breaks.
        }
        else if(s[i]=='/')
        {
            num[count1+1]/=num[count1]; // @@ Similar logic error as above for division.
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count2++;//记出现的大数 
            NUM[count2]=num[count1]; // @@ Logic Error: `NUM` is supposed to store the terms to be added/subtracted. `count1` here is the count of operators seen so far. When we see `+` or `-`, we want to store the value of the term that just ended. However, because `*` and `/` modify `num` in place, `num[count1]` might not represent the correct accumulated value of the term ending at this operator. More importantly, the index `count1` corresponds to the operator just seen. The number *preceding* this `+`/`-`/`=` is associated with the previous operator or start. The mapping between `num` indices and `NUM` indices is broken. For `10 + 20 * 30 - ...`, when `+` is processed, `count1=1`. `NUM[1] = num[1]` (which is 10). Correct. When `*` is processed, `num[3]` becomes 600. When `-` is processed, `count1=3`. `NUM[2] = num[3]` (which is 600). Correct so far? Wait. The problem is `num` indices. In the parsing loop, `num[1]`=10, `num[2]`=20, `num[3]`=30. `count1` increments on operators. `+` makes `count1=1`. `*` makes `count1=2`. Inside `*` block: `num[3] *= num[2]` -> `num[3]=600`. `-` makes `count1=3`. Inside `-` block: `NUM[2] = num[3]` -> `NUM[2]=600`. This seems to work for the second term. What about the first term? `NUM[1]=10`. Then `40 / 5`. `/` makes `count1=4`. `num[5] /= num[4]` -> `num[5]=8`. `=` makes `count1=5`. `NUM[3] = num[5]` -> `NUM[3]=8`. So `NUM` has `10, 600, 8`. Operators were `+`, `-`, `=`. `record2` counts `+`, `-`, `=`. So `record2=3`. Final loop calculates `NUM`.
        }
    }
    for(i=0,count=0;s[i]!='=';i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='=')
        {
            count++;//记出现的大数
        }
        if(s[i]=='+')
        {
            NUM[count+1]+=NUM[count]; // @@ Logic Error: This accumulates results into `NUM[count+1]`. For `10 + 600 - 8`. `count` increments on `+` to 1. `NUM[2] += NUM[1]` -> `NUM[2] = 600 + 10 = 610`. `count` increments on `-` to 2. `NUM[3] -= NUM[2]` -> `NUM[3] = 8 - 610 = -602`. `count` increments on `=` to 3. Loop ends. Output `NUM[record2]` which is `NUM[3]` = -602. The expected output is 602. The sign is wrong. Why? `10 + 600 - 8` should be `610 - 8 = 602`. The code does `8 - 610`. The subtraction `NUM[count+1] -= NUM[count]` uses the *current* term (`NUM[count+1]`) minus the *accumulated previous result* (`NUM[count]`). It should be `accumulated result` +/- `current term`. i.e., `NUM[count+1] = NUM[count] +/- NUM[count+1]` or simply accumulate into a running total. Here, `NUM[count]` holds the running total from previous steps. `NUM[count+1]` holds the current term. The operation `NUM[count+1] -= NUM[count]` computes `current_term - running_total`, which is the reverse of `running_total - current_term`.
        }
        else if(s[i]=='-')
        {
            NUM[count+1]-=NUM[count]; // @@ Logic Error: As explained above, this performs `current_term - running_total` instead of `running_total - current_term`. For `A - B`, it computes `B - A`.
        }
    }
    printf("%d",NUM[record2]);
    return 0;
}