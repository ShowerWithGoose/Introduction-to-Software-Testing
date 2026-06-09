package Parser.Func;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Exp.Exp;
import Parser.TreeNode;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncRParams implements TreeNode {
    private final String value = "<FuncRParams>";
    /* FuncRParams Attributes */
    private Exp firstExp = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParams( Exp firstExp, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.firstExp = firstExp;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.firstExp.print_tree());
        int cnt=commas.size();
        for(int i=0;i<cnt;i++){
            sb.append(this.commas.get(i).toStringprint());
            sb.append(this.exps.get(i).print_tree());
        }
        sb.append(value).append("\n");
        return sb.toString();
    }
}
