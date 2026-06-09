package frontend.Parser.Declaration;

import frontend.Lexer.Token;
import frontend.Parser.Terminators.BType;

import java.util.ArrayList;

public class VarDecl implements declEle {
    private BType bType;
    private VarDef firstVarDef;
    private ArrayList<Token> commaTokens;   // 可选
    private ArrayList<VarDef> varDefs;      // 可选
    private Token semicnToken;

    public VarDecl (BType bType,
                    VarDef firstVarDef,
                    ArrayList commaTokens,
                    ArrayList varDefs,
                    Token semicnToken) {
        this.bType = bType;
        this.firstVarDef = firstVarDef;
        this.commaTokens = commaTokens;
        this.varDefs = varDefs;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.printString());
        sb.append(firstVarDef.printString());
        for (int i = 0; i < commaTokens.size(); i++) {
            sb.append(commaTokens.get(i));
            sb.append(varDefs.get(i).printString());
        }
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        sb.append("<VarDecl>\n");
        return sb.toString();
    }
}
