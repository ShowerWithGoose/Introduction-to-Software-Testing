package node;

import token.Token;

/**
 * ClassName: BType
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:32
 * @Version 1.0
 */
public class BType extends Node{
    // BType -> 'int' | 'char'
    public Token typeToken;

    public BType(Token typeToken) {
        this.typeToken = typeToken;
        setLineNo(typeToken);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(typeToken.getPrintInfo());
        return info;
    }

}
