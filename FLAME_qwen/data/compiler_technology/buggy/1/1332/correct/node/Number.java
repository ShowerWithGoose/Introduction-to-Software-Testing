package node;

import token.Token;

/**
 * ClassName: Number
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:50
 * @Version 1.0
 */
public class Number extends Node {
    // Number -> IntConst
    public Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
        setLineNo(intConst);
    }

    public StringBuilder getPrintInfo() {
        StringBuilder info = new StringBuilder();
        info.append(intConst.getPrintInfo());
        info.append("<Number>\n");
        return info;
    }
}
