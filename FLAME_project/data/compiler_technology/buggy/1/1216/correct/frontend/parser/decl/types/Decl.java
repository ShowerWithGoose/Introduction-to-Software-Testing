package frontend.parser.decl.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.stmt.types.BlockItem;

import java.util.ArrayList;

//ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
//VarDecl → BType VarDef { ',' VarDef } ';' // i
public class Decl implements BlockItem {
    private final boolean isConst;
    private Token constToken = null;
    private final Token bType;
    private final Def firstDef;
    private final ArrayList<Def> defs = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    private Token semicn;
    public Decl(Token constToken, Token bType, Def firstDef) {
        this.isConst = true;
        this.constToken = constToken;
        this.bType = bType;
        this.firstDef = firstDef;
    }
    public Decl(Token bType, Def firstDef) {
        this.isConst = false;
        this.bType = bType;
        this.firstDef = firstDef;
    }
    public void addSemicn(Token semicn) {
        this.semicn = semicn;
    }
    public void addDef(Def def) {
        if (def.isConst() ^ this.isConst())
            System.err.println("[Exception] Decl and Def: type does not match");
        defs.add(def);
    }
    public void addSep(Token sep) {
        seps.add(sep);
    }
    public boolean isConst() {
        return this.isConst;
    }
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        if (isConst) result.append(constToken);
        result.append(bType);
        result.append(firstDef);
        for (int i = 0; i < defs.size(); i++) {
            result.append(seps.get(i));
            result.append(defs.get(i));
        }
        if (semicn != null) result.append(semicn);
        result.append(isConst?"<ConstDecl>\n":"<VarDecl>\n");
        return result.toString();
    }
    public TokenType getBType() {
        return this.bType.getType();
    }
    public ArrayList<Def> getDefs() {
        return this.defs;
    }
    public Def getFirstDef() {
        return this.firstDef;
    }
}
