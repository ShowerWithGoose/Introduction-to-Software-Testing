package node;

import token.Token;

/**
 * ClassName: ConstDef
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:32
 * @Version 1.0
 */
public class ConstDef extends Node {
    // ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public Token ident;
    // [  可选，用于定义数组
    public Token lbrack;
    public ConstExp constExp;
    public Token rbrack;
    // ]
    public Token assign;
    public ConstInitVal constInitVal;

    public ConstDef(Token ident, ConstExp constExp, ConstInitVal constInitVal, Token lbrack, Token rbrack, Token assign) {
        this.ident = ident;
        this.constExp = constExp;
        this.constInitVal = constInitVal;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
        this.assign = assign;
        setLineNo(ident);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        // Ident
        info.append(ident.getPrintInfo());
        // [ ConstExp ]
        if(lbrack != null){
            info.append(lbrack.getPrintInfo());
            info.append(constExp.getPrintInfo());
            info.append(rbrack.getPrintInfo());
        }
        // =
        info.append(assign.getPrintInfo());
        // ConstInitVal
        info.append(constInitVal.getPrintInfo());
        info.append("<ConstDef>\n");
        return info;
    }
}
