package Parser.Exp;

import Lexer.Token;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class AddExp implements TreeNode {
    private final String value="<AddExp>";
    private MulExp first = null;
    private ArrayList<Token> operators = new ArrayList<>(); // '+' '-'
    private ArrayList<MulExp> mulExpArrayList = new ArrayList<>();
    public AddExp(MulExp first,ArrayList<Token> operators,ArrayList<MulExp> mulExpArrayList)
    {
        this.first=first;
        this.operators=operators;
        this.mulExpArrayList=mulExpArrayList;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.print_tree());
        sb.append(this.value).append("\n");
        if(!this.operators.isEmpty()){
            int cnt= operators.size();
            for(int i=0;i<cnt;i++){
                sb.append(operators.get(i).toStringprint());
                sb.append(mulExpArrayList.get(i).print_tree());
                sb.append(this.value).append("\n");
            }
        }
        return sb.toString();
    }
}
