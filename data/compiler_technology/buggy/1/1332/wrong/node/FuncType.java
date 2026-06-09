package node;

import token.Token;

/**
 * ClassName: FuncType
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 15:58
 * @Version 1.0
 */
public class FuncType extends Node{
    // FuncType => 'void' | 'int' | 'char'
    public Token type;

    public FuncType(Token type) {
        this.type = type;
        setLineNo(type);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(type.getPrintInfo());
        info.append("<FuncType>\n");
        return info;
    }
}
