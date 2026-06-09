package Parser.Exp;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class RelExp implements TreeNode {
    private final String value="<RelExp>";
    private AddExp firstAddExp = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<AddExp> operands = new ArrayList<>();

    public RelExp(AddExp firstAddExp, ArrayList<Token> operators, ArrayList<AddExp> operands) {
        this.firstAddExp = firstAddExp;
        this.operators = operators;
        this.operands = operands;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.firstAddExp.print_tree());
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
