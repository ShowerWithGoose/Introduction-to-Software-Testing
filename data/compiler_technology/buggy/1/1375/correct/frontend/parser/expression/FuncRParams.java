package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

import java.util.ArrayList;

public class FuncRParams implements SyntaxNode {
    public final String name = "<FuncRParams>";
    public Exp first;
    /* commas 和 exps大小应当相同，且commas应当只有逗号一种Token */
    /* 这里可能需要进行某种验证 */
    public ArrayList<Token> commas;
    public ArrayList<Exp> exps;

    public FuncRParams(Exp first, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.first = first;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        if (commas != null && exps != null && commas.size() == exps.size()) {
            int len = commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(commas.get(i).syntaxOutput());
                sb.append(exps.get(i).syntaxOutput());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        if(!exps.isEmpty()){
            return exps.get(exps.size()-1).my_line_num();
        }else{
            return first.my_line_num();
        }
    }
}
