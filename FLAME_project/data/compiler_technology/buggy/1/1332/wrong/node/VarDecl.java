package node;

import token.Token;

import java.util.List;

/**
 * ClassName: VarDecl
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:25
 * @Version 1.0
 */
public class VarDecl extends Node{
    // VarDecl -> BType VarDef { ',' VarDef } ';'
    public BType bType;
    public List<VarDef> varDefs;
    public List<Token> commas;
    public Token semicnToken;

    public VarDecl(BType bType, List<VarDef> varDefs, List<Token> commas, Token semicnToken) {
        this.bType = bType;
        this.varDefs = varDefs;
        this.commas = commas;
        this.semicnToken = semicnToken;
        setLineNo(bType);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(bType.getPrintInfo());
        for (int i = 0; i < varDefs.size(); i++) {
            info.append(varDefs.get(i).getPrintInfo());
            if (i < commas.size()) {
                info.append(commas.get(i).getPrintInfo());
            }
        }
        info.append(semicnToken.getPrintInfo());
        info.append("<VarDecl>\n");
        return info;
    }
}
