package node;

import token.Token;

/**
 * ClassName: Character
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:50
 * @Version 1.0
 */
public class Character extends Node{
    // Character -> CharConst
    public Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
        setLineNo(charConst);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(charConst.getPrintInfo());
        info.append("<Character>\n");
        return info;
    }
}
