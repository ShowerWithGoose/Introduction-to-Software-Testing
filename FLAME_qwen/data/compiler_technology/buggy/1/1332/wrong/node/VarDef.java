package node;

import token.Token;

/**
 * ClassName: VarDef
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 15:36
 * @Version 1.0
 */
public class VarDef extends Node{
    // VarDef => Ident[ '[' ConstExp ']' ] | Ident[ '[' ConstExp ']' ] '=' InitVal
    // VarDef => Ident[ '[' ConstExp ']' ] ('=' InitVal | ε)

    public Token ident;

    // 是否为数组
    public Token lbrack;
    public ConstExp constExp;
    public Token rbrack;

    // 初始化与否
    public Token assign;
    public InitVal initVal;

    public VarDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token assign, InitVal initVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.initVal = initVal;
        setLineNo(ident);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(ident.getPrintInfo());
        if(lbrack != null){
            info.append(lbrack.getPrintInfo());
            info.append(constExp.getPrintInfo());
            info.append(rbrack.getPrintInfo());
        }
        if(assign != null){
            info.append(assign.getPrintInfo());
            info.append(initVal.getPrintInfo());
        }
        info.append("<VarDef>\n");
        return info;
    }
}
