package Parser.Exp;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class LAndExp implements TreeNode {
    private final String value="<LAndExp>";
    private EqExp firstEqExp = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<EqExp> operands = new ArrayList<>();

    public LAndExp(EqExp firstEqExp, ArrayList<Token> operators, ArrayList<EqExp> operands) {
        this.firstEqExp = firstEqExp;
        this.operators = operators;
        this.operands = operands;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.firstEqExp.print_tree());
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
