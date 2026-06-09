package node;

import token.Token;

/**
 * ClassName: FuncFParam
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:00
 * @Version 1.0
 */
public class FuncFParam extends Node{
    // FuncFParam => BType Ident ['[' ']' ]

    public BType bType;
    public Token ident;
    public Token lbrack;
    public Token rbrack;

    public FuncFParam(BType bType, Token ident, Token lbrack, Token rbrack) {
        this.bType = bType;
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
        setLineNo(bType);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(bType.getPrintInfo());
        info.append(ident.getPrintInfo());
        if(lbrack != null){
            info.append(lbrack.getPrintInfo());
            info.append(rbrack.getPrintInfo());
        }
        info.append("<FuncFParam>\n");
        return info;
    }
}
