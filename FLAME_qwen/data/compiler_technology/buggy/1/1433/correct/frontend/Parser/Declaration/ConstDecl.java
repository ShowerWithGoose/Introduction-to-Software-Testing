package frontend.Parser.Declaration;

import frontend.Lexer.Token;
import frontend.Parser.Terminators.BType;

import java.util.ArrayList;

public class ConstDecl implements declEle {
    private Token constToken;
    private BType bType;
    private ConstDef firstConstDef;
    private ArrayList<Token> commaTokens;       // 可选
    private ArrayList<ConstDef> constDefs;      // 可选
    private Token semicnToken;

    public ConstDecl (Token constToken,
                      BType bType,
                      ConstDef firstConstDef,
                      ArrayList commaTokens,
                      ArrayList constDefs,
                      Token semicnToken) {
        this.constToken = constToken;
        this.bType = bType;
        this.firstConstDef = firstConstDef;
        this.commaTokens = commaTokens;
        this.constDefs = constDefs;
        this.semicnToken =semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(constToken);
        sb.append(bType.printString());
        sb.append(firstConstDef.printString());
        if (!commaTokens.isEmpty()) {
            for (Token commaToken : commaTokens) {
                sb.append(commaToken.toString());
                sb.append(constDefs.get(commaTokens.indexOf(commaToken)).printString());
            }
        }
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        sb.append("<" + "ConstDecl" + ">\n");
        return sb.toString();
    }
}
