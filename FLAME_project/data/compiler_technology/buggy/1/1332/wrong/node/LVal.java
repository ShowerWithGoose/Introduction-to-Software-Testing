package node;

import token.Token;

/**
 * ClassName: LVal
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:49
 * @Version 1.0
 */
public class LVal extends Node{
    // LVal -> Indent['[' Exp ']']
    // 变量或数组元素
    public Token indent;
    public Token lbrack;
    public Exp exp;
    public Token rbrack;

    public LVal(Token indent, Token lbrack, Exp exp, Token rbrack) {
        this.indent = indent;
        this.lbrack = lbrack;
        this.exp = exp;
        this.rbrack = rbrack;
        setLineNo(indent);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(indent.getPrintInfo());
        if(lbrack != null){
            info.append(lbrack.getPrintInfo());
            info.append(exp.getPrintInfo());
            info.append(rbrack.getPrintInfo());
        }
        info.append("<LVal>\n");
        return info;
    }

}
