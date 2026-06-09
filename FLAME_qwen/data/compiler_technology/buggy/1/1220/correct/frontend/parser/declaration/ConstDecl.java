package frontend.parser.declaration;

import frontend.lexer.Token;

import java.util.ArrayList;

public class ConstDecl implements DeclUnit{
    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private final String name = "<ConstDecl>";
    private Token constTk;
    private BType bType;
    private ConstDef firstConstDef;
    private ArrayList<Token> commas;
    private ArrayList<ConstDef> constDefs;
    private Token semicn; //;

    public ConstDecl(Token constTk, BType bType, ConstDef firstConstDef,
                     ArrayList<Token> commas, ArrayList<ConstDef> constDefs,
                     Token semicn) {
        this.constTk = constTk;
        this.bType = bType;
        this.firstConstDef = firstConstDef;
        this.commas = commas;
        this.constDefs = constDefs;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        //// ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        StringBuilder sb = new StringBuilder();
        sb.append(constTk.syntaxPrint());
        sb.append(bType.syntaxPrint());
        sb.append(firstConstDef.syntaxPrint());
        if (commas != null && !commas.isEmpty()
        && constDefs != null && !constDefs.isEmpty()) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).syntaxPrint());
                sb.append(constDefs.get(i).syntaxPrint());
            }
        }
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
