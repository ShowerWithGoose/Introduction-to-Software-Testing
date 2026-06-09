package frontend.GrammaticalElements.declaration;

import frontend.Token;

import java.util.ArrayList;

public class VarDecl {
    /*BType* bType;
    VarDef* varDef;
    vector<Token> commas;
    vector<VarDef> varDefs;
    Token semicolon;*/
    private final String name = "<VarDecl>";
    private BType bType;
    private VarDef varDef;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private Token semicolon;

    public VarDecl(BType bType, VarDef varDef, Token semicolon) {
        this.bType = bType;
        this.varDef = varDef;
        this.semicolon = semicolon;
    }

    public VarDecl(BType bType, VarDef varDef, ArrayList<Token> commas, ArrayList<VarDef> varDefs, Token semicolon) {
        this.bType = bType;
        this.varDef = varDef;
        this.commas = commas;
        this.varDefs = varDefs;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString());
        sb.append(varDef.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i).toString());
            sb.append(varDefs.get(i).toString());
        }
        sb.append(semicolon.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
