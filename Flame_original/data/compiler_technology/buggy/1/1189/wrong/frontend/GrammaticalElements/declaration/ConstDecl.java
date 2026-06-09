package frontend.GrammaticalElements.declaration;

import frontend.Token;

import java.util.ArrayList;

public class ConstDecl {
    /*Token _const;
    BType* bType;
    ConstDef* constDef;
    vector<Token> commas;
    vector<ConstDef> constDefs;
    Token semicolon;*/
    private final String name = "<ConstDecl>";
    private Token _const;
    private BType bType;
    private ConstDef constDef;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstDef> constDefs = new ArrayList<>();
    private Token semicolon;

    public ConstDecl(Token _const, BType bType, ConstDef constDef, Token semicolon) {
        this._const = _const;
        this.bType = bType;
        this.constDef = constDef;
        this.semicolon = semicolon;
    }

    public ConstDecl(Token _const, BType bType, ConstDef constDef, ArrayList<Token> commas, ArrayList<ConstDef> constDefs, Token semicolon) {
        this._const = _const;
        this.bType = bType;
        this.constDef = constDef;
        this.commas = commas;
        this.constDefs = constDefs;
        this.semicolon = semicolon;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(_const.toString());
        sb.append(bType.toString());
        sb.append(constDef.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i).toString());
            sb.append(constDefs.get(i).toString());
        }
        sb.append(semicolon.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
