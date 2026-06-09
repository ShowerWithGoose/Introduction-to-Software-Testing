package Parser.Exp;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class LOrExp implements TreeNode {
    private final String value="<LOrExp>";
    private LAndExp firstLAndExp = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<LAndExp> operands = new ArrayList<>();

    public LOrExp(LAndExp firstLAndExp, ArrayList<Token> operators, ArrayList<LAndExp> operands) {
        this.firstLAndExp = firstLAndExp;
        this.operators = operators;
        this.operands = operands;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.firstLAndExp.print_tree());
        sb.append(this.value).append("\n");
        for(int i=0;i< operators.size();i++)
        {
            sb.append(this.operators.get(i).toStringprint());
            sb.append(this.operands.get(i).print_tree());
            sb.append(this.value).append("\n");
        }
        return sb.toString();
    }
}
