package parser_part.declaration.constance;

import lexer_part.Token;
import parser_part.declaration.BType;
import parser_part.declaration.DeclComponent;
import parser_part.declaration.Def;

import java.util.ArrayList;

public class ConstDecl implements DeclComponent {
    private Token constToken;
    private BType bType;
    private Def constDef;
    private ArrayList<Token> commas;
    private ArrayList<Def> constDefs;
    private Token semicn;

    public ConstDecl(Token constToken, BType bType, ConstDef constDef, ArrayList<Token> commas,
                     ArrayList<Def> constDefs, Token semicn) {
        this.constToken = constToken;
        this.bType = bType;
        this.constDef = constDef;
        this.commas = commas;
        this.constDefs = constDefs;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(constToken.toString());
        sb.append(bType.toString()).append(constDef.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i));
            sb.append(constDefs.get(i));
        }
        sb.append(semicn.toString()).append("<ConstDecl>\n");
        return sb.toString();
    }

    @Override
    public Def getFirstDef() {
        return constDef;
    }

    @Override
    public ArrayList<Def> getDefs() {
        return constDefs;
    }
}
