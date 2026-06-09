package Parser.Exp;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class MulExp implements TreeNode {
    private final String value="<MulExp>";
    private UnaryExp first ;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<UnaryExp> unaryExpArrayList = new ArrayList<>();

    public MulExp(UnaryExp first, ArrayList<Token> operators, ArrayList<UnaryExp> unaryExpArrayList) {
        this.first = first;
        this.operators = operators;
        this.unaryExpArrayList = unaryExpArrayList;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(first.print_tree());
        sb.append(this.value).append("\n");
        if(!this.operators.isEmpty()){
            int cnt= operators.size();
            for(int i=0;i<cnt;i++){
                sb.append(operators.get(i).toStringprint());
                sb.append(unaryExpArrayList.get(i).print_tree());
                sb.append(this.value).append("\n");
            }
        }
        return sb.toString();
    }
}
