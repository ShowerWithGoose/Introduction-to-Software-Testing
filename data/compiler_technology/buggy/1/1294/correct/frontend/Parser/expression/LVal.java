package frontend.Parser.expression;


import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.primaryexp.PrimaryExpPort;
import frontend.Parser.terminal.Ident;

// LVal -> Ident ['['Exp']']
public class LVal implements PrimaryExpPort {
    private final String grammarName = "<LVal>";
    private Ident ident;
    private Token lBrack;
    private Exp exp;
    private Token rBrack;
    public LVal(Ident ident) {
        this.ident = ident;
    }
    public LVal(Ident ident, Token lBrack, Exp exp, Token rBrack) {
        this(ident);
        this.lBrack = lBrack;
        this.exp = exp;
        this.rBrack = rBrack;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.getToken().grammarOutput());
        if(lBrack != null) {
            sb.append(this.lBrack.grammarOutput());
            sb.append(this.exp.grammarOutput());
            sb.append(this.rBrack.grammarOutput());
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
