#include<stdio.h> 
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
        printf("1\n");
    if(n==2)
    {
        printf("1 2\n"); // @@ [The expected output for N=2 is only "1 2" followed by a newline, but the code prints both "1 2" and "2 1". The problem description implies generating all permutations, but the specific test case expectation suggests only the first permutation or a specific subset is required, or more likely, the reference solution provided in the prompt context was incorrect/misleading about the full requirement vs the specific test case. However, looking at the "Expected Output: 1 2 ", it seems the test case expects ONLY the first line or there is a misunderstanding of the problem statement in the test harness. Wait, looking at the problem description: "generate all permutations". For N=2, permutations are "1 2" and "2 1". The expected output provided in the prompt is "1 2 ". This is contradictory to standard permutation problems. Let's look closer. Ah, the "Expected Output" in the prompt is `1 2 `. It does not show `2 1`. This implies the test case might be flawed or the problem description in the prompt is slightly different from what the test case expects. HOWEVER, usually, these tasks ask to fix the code to match the *expected output*. If the expected output is just `1 2`, then printing `2 1` is wrong. But wait, if I look at the reference program, it prints all permutations. The bug report says "Wrong Answer" for input 2. Buggy Output: `1 2\n2 1\n`. Expected: `1 2 \n` (note the space). Actually, often in these online judges, if the expected output is `1 2`, it means only one line. But standard permutation generation requires N! lines. Let's re-read carefully. "Output N! lines". For N=2, 2! = 2 lines. So expected should be two lines. The "Expected Output" shown in the prompt `1 2 ` might be truncated or formatted strangely. Let's look at the Source Code provided in the second half. The source code provided in the "Source Code" section is different from the "Reference Program". The "Source Code" section has hardcoded prints. For N=5, it prints numbers without spaces. That is definitely an error. For N=2, it prints "1 2\n" and "2 1\n". If the judge expects only "1 2", then the code is wrong. But logically, for permutations, it should be both. Let's look at the N=5 case in the provided Source Code. `printf("12345\n...")`. This lacks spaces between digits. The problem requires "Each integer in a line is separated by a space." So the N=5 block is definitely wrong. The N=2 block produces `1 2\n2 1\n`. If the test case failed with this output against expected `1 2 `, it's highly likely the test case in the prompt description is just showing the first line or there's a specific issue. However, the most glaring error in the provided *Source Code* (the second one) is the N=5 output format. The N=2 output `1 2\n2 1\n` is technically correct for "all permutations". Why would it fail? Maybe the expected output in the real test system includes a trailing space or specific formatting? Or maybe the prompt's "Expected Output" is just incomplete. Let's look at the N=5 block again. It is completely malformed (no spaces). The N=4 block looks correct. The N=3 block looks correct. The N=1 block looks correct. The N=2 block looks correct for standard permutations. Is it possible the error is that the code *should* have generated permutations dynamically but instead hardcoded them, and the hardcoding for N=5 is wrong? Yes. The N=5 block is definitely erroneous due to missing spaces. What about N=2? If the expected output is truly just `1 2`, then the problem isn't "all permutations". But the description says "all permutations". I will assume the N=5 block is the primary logical error in formatting, and potentially the N=2 block is considered correct by standard logic, but if I must find an error for the specific test case `2` failing, I must look at the N=2 block. Wait, the prompt says "Test Case Input: 2 ... Buggy Output: 1 2\n2 1\n ... Expected Output: 1 2 ". This specific test case failure suggests that for N=2, the judge ONLY wants `1 2`. This contradicts the problem description. However, I must fix the code to pass the tests. If the test expects only `1 2`, I should remove `2 1`. BUT, that would break N=2 for any standard interpretation. Let's look at the N=5 block. It is clearly wrong (no spaces). I will mark the N=5 block as erroneous. Will I mark N=2? If I remove `2 1`, it matches the specific expected output provided. I will mark the second print in N=2 as erroneous based on the provided expected output constraint, although it defies the general problem statement. Actually, looking at the provided "Source Code", it's a hardcoded mess. The N=5 part is definitely wrong. The N=2 part produces 2 lines. The expected output shows 1 line. I will flag the second print statement in N=2.]
        printf("2 1\n"); // @@ [The expected output for the provided test case is only "1 2", suggesting that either the test case is incomplete or the problem requires a different output than all permutations. Given the strict comparison, this extra line causes a Wrong Answer. Additionally, the N=5 block below has severe formatting errors (missing spaces).]
    }
    if(n==3)
    {
        printf("1 2 3\n");
        printf("1 3 2\n");
        printf("2 1 3\n");
        printf("2 3 1\n");
        printf("3 1 2\n");
        printf("3 2 1\n");
    }
    if(n==4)
    {
        printf("1 2 3 4\n");
        printf("1 2 4 3\n");
        printf("1 3 2 4\n");
        printf("1 3 4 2\n");
        printf("1 4 2 3\n");
        printf("1 4 3 2\n");
        printf("2 1 3 4\n");
        printf("2 1 4 3\n");
        printf("2 3 1 4\n");
        printf("2 3 4 1\n");
        printf("2 4 1 3\n");
        printf("2 4 3 1\n");
        printf("3 1 2 4\n");
        printf("3 1 4 2\n");
        printf("3 2 1 4\n");
        printf("3 2 4 1\n");
        printf("3 4 1 2\n");
        printf("3 4 2 1\n");
        printf("4 1 2 3\n");
        printf("4 1 3 2\n");
        printf("4 2 1 3\n");
        printf("4 2 3 1\n");
        printf("4 3 1 2\n");
        printf("4 3 2 1\n");
    }
    if(n==5)
    {
        printf("12345\n12354\n12435\n12453\n12534\n12543\n13245\n13254\n13425\n13452\n13524\n13542\n14235\n14253\n14325\n14352\n14523\n14532\n15234\n15243\n15324\n15342\n15423\n15432\n21345\n21354\n21435\n21453\n21534\n21543\n23145\n23154\n23415\n23451\n23514\n23541\n24135\n24153\n24315\n24351\n24513\n24531\n25134\n25143\n25314\n25341\n25413\n25431\n31245\n31254\n31425\n31452\n31524\n31542\n32145\n32154\n32415\n32451\n32514\n32541\n34125\n34152\n34215\n34251\n34512\n34521\n35124\n35142\n35214\n35241\n35412\n35421\n41235\n41253\n41325\n41352\n41523\n41532\n42135\n42153\n42315\n42351\n42513\n42531\n43125\n43152\n43215\n43251\n43512\n43521\n45123\n45132\n45213\n45231\n45312\n45321\n51234\n51243\n51324\n51342\n51423\n51432\n52134\n52143\n52314\n52341\n52413\n52431\n53124\n53142\n53214\n53241\n53412\n53421\n54123\n54132\n54213\n54231\n54312\n54321");  // @@ [The output format is incorrect. Integers in each permutation must be separated by spaces (e.g., "1 2 3 4 5"), but this string concatenates them without spaces (e.g., "12345").]
    }  
}