package frontend.Parser.function;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.declaration.BType;
import frontend.Parser.terminal.Ident;

public class FuncFParam implements GrammarNode {
    private final String grammarName = "<FuncFParam>";
    private BType bType; //int or char
    private Ident ident; //变量名
    private Token lBrack; // '['
    private Token rBrack; // ']'

    public FuncFParam(BType bType, Ident ident, Token lBrack, Token rBrack) {
        this.bType = bType;
        this.ident = ident;
        this.lBrack = lBrack;
        this.rBrack = rBrack;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.bType.grammarOutput());
        sb.append(this.ident.getToken().grammarOutput());
        if(lBrack != null && rBrack != null) {
            sb.append(this.lBrack.grammarOutput());
            sb.append(this.rBrack.grammarOutput());
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
