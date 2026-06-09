package frontend.Parser.declaration.constant;

import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.GrammarNode;
import frontend.Parser.declaration.BType;

import java.util.ArrayList;

public class ConstDecl implements GrammarNode {
    private final String grammarName = "<ConstDecl>";
    private Token constTk;
    private BType bType;
    private ConstDef firConstDef;
    private ArrayList<ConstDef> constDefs;
    private ArrayList<Token> commas;
    private Token semicn;

    public ConstDecl(Token constTk, BType bType, ConstDef firConstDef, Token semicn) {
        this.constTk = constTk;
        this.bType = bType;
        this.firConstDef = firConstDef;
        this.semicn = semicn;
    }

    public ConstDecl(Token constTk, BType bType,
                     ConstDef firConstDef, Token semicn,
                     ArrayList<ConstDef> constDefs, ArrayList<Token> commas) {
        this(constTk, bType, firConstDef, semicn);
        this.constDefs = constDefs;
        this.commas = commas;
    }

    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        if (constTk.getTokenType().equals(TokenType.CONSTTK)) {
            sb.append(constTk.grammarOutput());
        }
        sb.append(bType.grammarOutput());
        sb.append(firConstDef.grammarOutput());
        if (constDefs != null && this.commas != null && this.commas.size() == this.constDefs.size()) {
            int size = constDefs.size();
            for (int i = 0; i < size; i++) {
                sb.append(commas.get(i).grammarOutput());
                sb.append(constDefs.get(i).grammarOutput());
            }
        }
        sb.append(semicn.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
