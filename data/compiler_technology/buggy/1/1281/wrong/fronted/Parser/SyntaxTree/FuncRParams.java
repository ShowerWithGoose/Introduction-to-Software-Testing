package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/12 23:26
 */
public class FuncRParams implements SyntaxNode{
    private final String name = "<FuncRParams>";
    private Exp necExp;
    private ArrayList<Token> commas; // commas
    private ArrayList<Exp> exps; // Exps

    public FuncRParams(Exp necExp, ArrayList<Token> commas, ArrayList<Exp> exps) {
        this.necExp = necExp;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.necExp.output());
        if (!this.commas.isEmpty() && !this.exps.isEmpty() && this.commas.size() == this.exps.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).output());
                sb.append(this.exps.get(i).output());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
