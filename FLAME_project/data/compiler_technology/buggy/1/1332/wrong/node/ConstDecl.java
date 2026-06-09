package node;

import token.Token;

import java.util.List;

/**
 * ClassName: ConstDecl
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:25
 * @Version 1.0
 */
public class ConstDecl extends Node{
    // ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
    public Token constToken;
    public BType bType;
    public List<ConstDef> constDefs;
    public List<Token> commas;
    public Token semicnToken;

    public ConstDecl(Token constToken, BType bType, List<ConstDef> constDefs, List<Token> commas, Token semicnToken) {
        this.constToken = constToken;
        this.bType = bType;
        this.constDefs = constDefs;
        this.commas = commas;
        this.semicnToken = semicnToken;
        setLineNo(constToken);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(constToken.getPrintInfo());
        info.append(bType.getPrintInfo());
        for (int i = 0; i < constDefs.size(); i++) {
            info.append(constDefs.get(i).getPrintInfo());
            if (i < commas.size()) {
                info.append(commas.get(i).getPrintInfo());
            }
        }
        info.append(semicnToken.getPrintInfo());
        info.append("<ConstDecl>\n");
        return info;
    }
}
