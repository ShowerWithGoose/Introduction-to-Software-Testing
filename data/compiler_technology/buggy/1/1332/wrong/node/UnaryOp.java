package node;

import token.Token;

/**
 * ClassName: UnaryOp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:33
 * @Version 1.0
 */
public class UnaryOp extends Node{
    // UnaryOp -> '+' | '-' | '!'
    public Token op;

    public UnaryOp(Token op) {
        this.op = op;
        setLineNo(op);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(op.getPrintInfo());
        info.append("<UnaryOp>\n");
        return info;
    }
}
