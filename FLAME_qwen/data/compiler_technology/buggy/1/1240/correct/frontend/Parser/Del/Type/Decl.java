package frontend.Parser.Del.Type;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class Decl {
    // Decl → ConstDecl | VarDecl
    // VarDecl → BType VarDef { ',' VarDef } ';'
    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private final LexType constToken;
    private final LexType BType;
    private final ArrayList<LexType> pauses;
    private final ArrayList<Def> defs;
    private final LexType semicolon;

    public Decl(LexType constToken, LexType Btype, ArrayList<LexType> pauses,
                ArrayList<Def> defs, LexType semicolon){
        this.constToken = constToken;
        this.BType = Btype;
        this.pauses = pauses;
        this.defs = defs;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (constToken != null){
            sb.append(constToken);
        }
        sb.append(BType.toString());
        sb.append(defs.get(0));
        for (int i = 0; i < pauses.size(); i++) {
            sb.append(pauses.get(i).toString()).append(defs.get(i+1));
        }
        if (this.semicolon != null) {
            sb.append(semicolon);
        }
        if (constToken != null) {
            sb.append("<ConstDecl>\n");
        } else {
            sb.append("<VarDecl>\n");
        }
        return sb.toString();
    }
}
