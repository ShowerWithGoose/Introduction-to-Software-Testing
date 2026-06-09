#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],d[100],e[100];
    int i,j=0,ans,m=0,k,n=0;
    int c[100]={0};
    gets(e);
    for(i=0;i<strlen(e);i++){
        if(e[i]!=' '){
            a[j]=e[i];
            j++;
            
        }
    }
    
    j=0;
    
    
    for(i=0;i<strlen(a);i++){
        if(a[i]<='9'&&a[i]>='0'){
            b[j]=a[i];
            
            j++;
        }//连续的数字读入 
        else if(a[i]>'9'||a[i]<'0'){//读到符号后停止 
            for(k=0;k<j;k++){
                c[m]=c[m]*10+b[k]-48; // @@ [This loop incorrectly builds the number: it processes each digit as if starting from zero, but c[m] is already being multiplied by 10 each time. For example, for "24", it does: c[m]=0*10+'2'-'0'=2, then c[m]=2*10+'4'-'0'=24 — which seems okay, BUT the issue is that b[k] contains characters, and this logic assumes all digits are processed in one go. However, the real problem is that after processing a number, m is incremented, but the next number starts with c[m] = 0 (due to initialization), so this part actually works. The deeper issue is elsewhere.]
            }
            
            m++;
            j=0;
        }//c[0]代表了第一个数，以此类推 m
    }
    ans=c[0];
    
    for(i=0;i<strlen(a);i++){
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
            d[n]=a[i];
            n++;
        }//将符号剔除出来 d[n]
    }
    double x=0; // @@ [Using double for integer division violates requirement #3 which specifies integer division. Also, mixing integer and floating point can cause truncation issues, though in this case it's assigned back to int via ans. But more critically, the algorithm logic is flawed.]
    for(i=0;i<m;i++){ // @@ [Loop runs for i from 0 to m-1, where m is count of numbers. But d[] includes '=' and has length n, and the relationship between operators and operands is misaligned. Also, the logic tries to handle operator precedence manually but fails for sequences like "/ / * ...".]
        if((d[i]=='+'||d[i]=='-')&&d[i+1]!='*'&&d[i+1]!='/'){ // @@ [This condition assumes that if next operator is not * or /, then current + or - can be applied immediately. But this ignores that * and / should be grouped together regardless of position. Also, d[i] corresponds to operator AFTER c[i], but indexing is off because d includes '=' and the number of operators is m (since m numbers => m operators including '=').]
            
            if(d[i]=='+'){
                ans+=c[i+1];
            }
            else if(d[i]=='-'){
                ans-=c[i+1];
            }
            
        }
        else  if(d[i]=='*'||d[i]=='/'){
            if(d[i]=='*'){
                x=c[i]*c[i+1]; // @@ [Here, c[i] is used, but in an expression like "24 / 4 / 3 ...", the first number is c[0]=24, then c[1]=4, etc. However, when i=0, d[0] is '/', so this block runs. But the algorithm assumes that the multiplication/division chain starts at c[i], but in reality, the left operand for the first / is c[0], which is correct. However, the bigger flaw is in how the result x is merged back into ans.]
            }
            else if(d[i]=='/'){
                x=c[i]/c[i+1];
            }
            for(j=i+1;j<m;j++){ // @@ [This inner loop continues processing * and /, but uses c[j+1], which goes out of bounds when j = m-1 (since c has indices 0..m-1). Also, the break condition depends on encountering a non-* / operator, but the logic for updating 'ans' is incorrect: it uses d[i-1] to decide sign, but if the expression starts with multiplication/division (like this test case), i=0, so d[i-1] is invalid (accessing d[-1]).]
                if(d[j]=='*'){
                    x*=c[j+1];
                }
                else if(d[j]=='/'){
                    x/=c[j+1];
                }
                else {
                    if(i>=1){
                    if(d[i-1]=='-'){
                        ans-=x;
                    }
                    else {
                        ans+=x;
                    }
                    }
                    else if(i==0){
                        ans=x; // @@ [This sets ans = x for the first group, which for "24/4/3/2*2*3*4" would compute x = ((((24/4)/3)/2)*2)*3)*4 = (((6/3)/2)*2)*3*4 = ((2/2)*2)*3*4 = (1*2)*3*4 = 24. So why output is 144? Because the parsing of numbers is wrong. Let's check: input "24 / 4 / 3 / 2 * 2 * 3 * 4 =". After removing spaces: "24/4/3/2*2*3*4=". The number extraction loop: when it hits '/', it converts b[] (which is ['2','4']) into c[0] = 0*10+'2'-48=2, then 2*10+'4'-48=24 → correct. Then m=1, j=0. Next, reads '4', then hits '/', so c[1] = 4. Similarly c[2]=3, c[3]=2, c[4]=2, c[5]=3, c[6]=4. So m=7 numbers. Then d[] will be: ['/', '/', '/', '*', '*', '*', '='], so n=7. Now in the operator loop: i from 0 to 6 (m=7). At i=0: d[0]=='/', so enter else if. x = c[0]/c[1] = 24/4=6. Then j starts at i+1=1. d[1]=='/', so x = 6 / c[2] = 6/3=2. j=2: d[2]=='/', x=2/c[3]=2/2=1. j=3: d[3]=='*', x=1*c[4]=2. j=4: d[4]=='*', x=2*c[5]=6. j=5: d[5]=='*', x=6*c[6]=24. j=6: now j < m (7) → true. Check d[6] == '=' → not * or /, so enter else. Since i==0, set ans = x = 24. Then break. So why output 144? There must be an error in number parsing. Wait: in the number parsing loop, after the last number '4', the loop ends because a[i] becomes '='. But the else if condition triggers only when a non-digit is found. However, after the last '4', the next char is '=', which is non-digit, so it triggers the else if, and converts b[] (which has '4') into c[6]. That seems okay. But what about the '='? The loop runs for i up to strlen(a)-1. The string a is "24/4/3/2*2*3*4=". So the last character is '='. When i points to '=', it is non-digit, so it triggers the else if, but at that point, b[] is empty (j=0) because after processing '4', j was reset to 0, and then '=' is encountered, so j=0, and the for(k=0;k<0;k++) does nothing, then m increments to 7. So c[6] was set when processing the '4' before '=', and then an extra m++ happens for '=', leading to m=7, but c[6] is valid, and c[7] is never used. However, in the operator loop, i goes from 0 to m-1 = 6. But d has 7 operators (including '='). Now, in the inner loop, when j=6, d[6] is '=', so it breaks and sets ans=24. So why 144? Let's simulate the actual buggy code behavior. The critical bug is in the number parsing: the else if block runs for EVERY non-digit, including the '='. But after the last number '4', the code reads '4' into b, j=1. Then next char is '=', which is non-digit, so it enters else if, and runs for(k=0; k<1; k++): c[m] = 0*10 + b[0]-48 = '4'-'0'=4. So c[6]=4, m becomes 7. Then the loop ends. So numbers are correct. Now, the operator array d: it collects every operator including '='. So d[0]='/', d[1]='/', d[2]='/', d[3]='*', d[4]='*', d[5]='*', d[6]='='. Now, in the for(i=0; i<m; i++) loop, m=7, so i=0 to 6. At i=0: d[0]=='/', so enter the multiplication/division block. x = c[0]/c[1] = 24/4=6. Then j starts at 1. d[1]=='/' → x = 6 / c[2] = 6/3=2. j=2: d[2]=='/' → x=2/c[3]=2/2=1. j=3: d[3]=='*' → x=1*c[4]=1*2=2. j=4: d[4]=='*' → x=2*c[5]=2*3=6. j=5: d[5]=='*' → x=6*c[6]=6*4=24. j=6: now j=6 < m=7 → true. Check d[6]=='=' → not * or /, so enter else. Since i=0, set ans = x = 24. Break inner loop. Then i increments to 1,2,...6. For i=1: d[1]=='/', so again enter the multiplication block! This is the critical error: the algorithm does not skip the operators that were already processed in the inner loop. So it reprocesses the same division/multiplication sequence multiple times. Specifically, after processing i=0 and handling up to j=6, the outer loop continues with i=1, which is still '/', and repeats the calculation, using c[1]=4, c[2]=3, etc., leading to x=4/3=1 (integer division), then 1/2=0, then 0*2=0, etc., but then when merging, since i=1>=1, it checks d[0]=='/', which is not '-' or '+', so it does ans += x (which is 0), so ans remains 24. But wait, why 144? Let's see: maybe the inner loop doesn't break properly. Actually, after the first pass (i=0), ans=24. Then i=1: d[1]=='/', so x = c[1]/c[2] = 4/3 = 1. Then j=2: d[2]=='/' → x=1/c[3]=1/2=0. j=3: d[3]=='*' → x=0*c[4]=0. j=4: '*' → 0. j=5: '*' → 0. j=6: '=' → break. Then since i=1>=1, check d[0]=='/' → which is not '-' or '+', so it does ans += x → 24+0=24. Similarly for i=2: x = c[2]/c[3]=3/2=1, then *2*3*4=24, then since i=2, check d[1]=='/' → not +/-, so ans +=24 → 48. i=3: d[3]=='*', x=c[3]*c[4]=2*2=4, then *3*4=48, then check d[2]=='/' → not +/-, so ans +=48 → 96. i=4: x=2*3=6, *4=24, ans +=24 → 120. i=5: x=3*4=12, ans +=12 → 132. i=6: d[6]=='=', so the first if condition: (d[6]=='+'||...) is true, but d[7] is out of bounds (undefined), and also c[7] is 0 (since c was initialized to 0), so if it enters, ans += c[7] → no change. But why 144? Alternatively, perhaps the number parsing is wrong. Another possibility: in the number parsing loop, when it encounters a non-digit, it converts the current b[] into a number. But what if there are consecutive operators? Not in this case. Or, the issue is that the '=' causes an extra number to be parsed. But we saw that's handled. Wait, let's look at the number parsing loop again:

for(i=0;i<strlen(a);i++){
    if digit: add to b, j++
    else: convert b to number, m++, j=0
}

But after the last number '4', the next char is '=', which is non-digit, so it converts b (which has '4') to c[m], m++. So c[0]=24, c[1]=4, c[2]=3, c[3]=2, c[4]=2, c[5]=3, c[6]=4. m=7.

But the expression has 7 numbers and 7 operators (including '='). However, the number of operators between numbers is 6, plus '=' makes 7. So d has 7 elements.

Now, the outer loop runs i from 0 to m-1 = 6. For each i, it looks at d[i], which is the operator after c[i].

The algorithm's fatal flaw is that it processes every operator position independently, without marking which parts have been consumed by higher-precedence operations. Thus, the multiplication/division chains are processed repeatedly for every starting index i where d[i] is * or /, leading to multiple additions of partial results.

In particular, for the given input, the first chain (i=0) computes 24 correctly and sets ans=24. But then i=3 (where d[3] is '*'), it will compute c[3]*c[4]*c[5]*c[6] = 2*2*3*4=48, and since i=3>=1 and d[2] is '/' (not '-' or '+'), it adds 48 to ans → 24+48=72. Similarly, i=4: 2*3*4=24 → ans=96. i=5: 3*4=12 → ans=108. But 144 suggests something else.

Alternatively, the use of double x might cause issues, but 24 is integer.

Wait, another possibility: in the number parsing, when converting b[] to number, the loop is:

for(k=0;k<j;k++){
    c[m]=c[m]*10+b[k]-48;
}

But c[m] is initially 0 (from int c[100]={0};). So for "24", j=2, b[0]='2', b[1]='4'.

k=0: c[m] = 0*10 + '2'-48 = 2
k=1: c[m] = 2*10 + '4'-48 = 24 → correct.

So numbers are fine.

The real issue is the repeated processing of the same multiplication/division sequence from different starting points, and the incorrect accumulation into 'ans'.

Specifically, the algorithm should process * and / in a single left-to-right pass, combining numbers as it goes, and then handle + and -.

But this code tries to do it in a convoluted way that revisits operators.

For the input "24/4/3/2*2*3*4=", the correct result is 24.

But the buggy code, due to processing i=0, then i=1, i=2, etc., and adding intermediate products multiple times, ends up with 144.

How 144? 24 * 6 = 144. Notice that 2*2*3*4=48, and 24+48+... doesn't give 144. Alternatively, if the first chain is computed as 24, and then later chains are added, but perhaps the initial ans is not reset.

Wait, ans is initialized to c[0]=24.

Then in the operator loop, for i=0: it sets ans = x = 24 (overwriting the initial 24).

Then for i=3: it computes x=2*2*3*4=48, and since d[2] is '/', which is not '-' or '+', it does ans += x → 24+48=72.

i=4: x=2*3*4=24 → ans=96

i=5: x=3*4=12 → ans=108

Not 144.

Unless... in the inner loop, when j goes beyond, and c[j+1] is accessed when j+1 >= m.

For example, when i=5, j starts at 6. Then d[6] is '=', so it breaks immediately. x = c[5]*c[6] = 3*4=12. Then since i=5>=1, check d[4] which is '*', not +/-, so ans +=12.

Still not 144.

Another possibility: the number parsing includes the '=' as a number? No, because when '=' is encountered, j=0 (since after '4', j was set to 1, then after processing '4' into c[6], j is reset to 0. Then '=' is read, j=0, so the for loop does nothing, but m is still incremented to 7. So c[6]=4, and c[7] remains 0. But m=7, so the numbers are c[0] to c[6].

But in the operator loop, when i=6, it accesses c[7] which is 0.

But d[6] is '=', so the first if condition: (d[6]=='+'||...) is true, and it checks d[7] which is uninitialized (probably 0), so d[7]!='*' and !='/', so it would do: if d[6]=='+', ans+=c[7], but d[6] is '=', so neither '+' nor '-', so nothing happens.

So why 144?

Let me consider: perhaps the multiplication chain is computed incorrectly because of the order.

In the inner loop for i=0:

x = c[0]/c[1] = 24/4=6

j=1: d[1]=='/' → x = x / c[2] = 6/3=2

j=2: d[2]=='/' → x = 2 / c[3] = 2/2=1

j=3: d[3]=='*' → x = 1 * c[4] = 1*2=2

j=4: d[4]=='*' → x = 2 * c[5] = 6

j=5: d[5]=='*' → x = 6 * c[6] = 24

j=6: d[6]=='=' → break, set ans=24.

Then i=1:

d[1]=='/', so x = c[1]/c[2] = 4/3=1

j=2: d[2]=='/' → x=1/c[3]=1/2=0

j=3: '*' → x=0*c[4]=0

... → x=0, ans +=0.

i=2:

x=c[2]/c[3]=3/2=1

j=3: '*' → 1*2=2

j=4: '*' → 2*3=6

j=5: '*' → 6*4=24

Then, since i=2>=1, check d[1]=='/' → not '-' or '+', so ans +=24 → 24+24=48.

i=3:

x=c[3]*c[4]=2*2=4

j=4: '*' → 4*3=12

j=5: '*' → 12*4=48

ans +=48 → 96

i=4:

x=2*3=6

j=5: '*' → 6*4=24

ans +=24 → 120

i=5:

x=3*4=12

ans +=12 → 132

i=6: nothing.

Still not 144.

Unless... the initial ans is c[0]=24, and then for i=0, it sets ans=x=24 (same), but then for i=3,4,5, it adds more.

But 24+48+24+12=108.

Wait, 24 (from i=0) + 24 (i=2) + 48 (i=3) + 24 (i=4) + 12 (i=5) = 132.

How to get 144? 144 = 24 * 6, or 12*12, etc.

Another idea: perhaps the number parsing is wrong for multi-digit numbers after the first. But in this input, all numbers are single-digit except the first.

Or, the issue is that the '=' is not handled, and the loop continues.

But the most likely root cause is that the algorithm does not account for operator precedence correctly and processes segments multiple times, but the exact reason for 144 is less important than the structural flaws.

The key errors are:

1. The number parsing loop may work for this case, but the operator processing logic is fundamentally flawed because it doesn't consume the tokens it processes, leading to reprocessing.

2. The use of double for integer arithmetic is unnecessary and against requirements.

3. The indexing between c[] and d[] is off because d[] includes the '=' and has length equal to the number of operators including '=', while there are m numbers and m-1 binary operators plus '='.

4. The condition in the first if of the operator loop checks d[i+1], which can be out of bounds.

5. The inner loop accesses c[j+1] which can be out of bounds when j = m-1.

Given the test case fails with 144 instead of 24, and the reference program uses a two-pass approach (first split by + and -, then evaluate each segment for * and /), the buggy program's approach is incorrect.

The most critical error locations are in the operator processing loop where it attempts to handle precedence manually but fails.

Thus, the annotations should highlight:

- The double x usage
- The flawed logic in the operator loop that reprocesses operators
- The potential out-of-bounds accesses
- The incorrect accumulation strategy

But per instructions, we add @@ after the line where error occurs.
        }
    }
    printf("%d",ans);
}