package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 1:01
 */
public class ConstInitValNodeOfExpArray implements SyntaxNode{
    private Token leftBrace; // '{'
    private ConstExp mayConstExp; // may
    private ArrayList<Token> commas; // may
    private ArrayList<ConstExp> constExps; // may
    private Token rightBrace; // '}'

    public ConstInitValNodeOfExpArray(Token leftBrace, ConstExp mayConstExp, ArrayList<Token> commas, ArrayList<ConstExp> constExps, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.mayConstExp = mayConstExp;
        this.commas = commas;
        this.constExps = constExps;
        this.rightBrace = rightBrace;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.output());
        if (this.mayConstExp != null) {
            sb.append(this.mayConstExp.output());
            if (!this.commas.isEmpty() && !this.constExps.isEmpty()
                    && this.commas.size() == this.constExps.size()) {
                int len = this.commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.commas.get(i).output());
                    sb.append(this.constExps.get(i).output());
                }
            }
        }
        sb.append(this.rightBrace.output());
        return sb.toString();
    }
}
