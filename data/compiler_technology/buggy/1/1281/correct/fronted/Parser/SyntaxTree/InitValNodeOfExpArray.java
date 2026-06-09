package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 1:33
 */
public class InitValNodeOfExpArray implements SyntaxNode{
    private Token leftBrace; // '{'
    private Exp mayExp; // may
    private ArrayList<Token> commas; // may
    private ArrayList<Exp> Exps; // may
    private Token rightBrace; // '}'

    public InitValNodeOfExpArray(Token leftBrace, Exp mayExp, ArrayList<Token> commas, ArrayList<Exp> Exps, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.mayExp = mayExp;
        this.commas = commas;
        this.Exps = Exps;
        this.rightBrace = rightBrace;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.output());
        if (this.mayExp != null) {
            sb.append(this.mayExp.output());
            if (!this.commas.isEmpty() && !this.Exps.isEmpty()
                    && this.commas.size() == this.Exps.size()) {
                int len = this.commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.commas.get(i).output());
                    sb.append(this.Exps.get(i).output());
                }
            }
        }
        sb.append(this.rightBrace.output());
        return sb.toString();
    }
}
