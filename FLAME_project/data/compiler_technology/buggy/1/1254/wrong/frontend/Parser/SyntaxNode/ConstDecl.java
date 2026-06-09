package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

import java.util.ArrayList;

/*
 ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
 */

public class ConstDecl extends Decl {
    private final String name = "<ConstDecl>";
    private Token consttk; // const
    private BType btype;
    private ConstDef firstConstDef;
    private ArrayList<ConstDef> constDefs;
    private ArrayList<Token> commas; //,
    private Token semicn; //;

    public ConstDecl(Token consttk, BType btype, ConstDef firstConstDef, ArrayList<ConstDef> constDefs,
                     ArrayList<Token> commas, Token semicn) {
        this.consttk = consttk;
        this.btype = btype;
        this.firstConstDef = firstConstDef;
        this.semicn = semicn;
        this.constDefs = constDefs;
        this.commas = commas;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(consttk);
        sb.append(btype);
        sb.append(firstConstDef);
        for (int i = 0; i < constDefs.size(); i++) {
            sb.append(commas.get(i));
            sb.append(constDefs.get(i));
        }
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}
