package Parser.Exp;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class EqExp implements TreeNode {
    private final String value="<EqExp>";
    private RelExp first;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<RelExp> operands = new ArrayList<>();

    public EqExp(RelExp first, ArrayList<Token> operators, ArrayList<RelExp> operands) {
        this.first = first;
        this.operators = operators;
        this.operands = operands;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.first.print_tree());
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
