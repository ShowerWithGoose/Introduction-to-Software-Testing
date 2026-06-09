package node;

import token.Token;

/**
 * ClassName: MainFuncDef
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:03
 * @Version 1.0
 */
public class MainFuncDef extends Node{
    // MainFuncDef => 'int' 'main' '(' ')' Block
    public Token intToken;
    public Token mainToken;
    public Token lparen;
    public Token rparen;
    public Block block;

    public MainFuncDef(Token intToken, Token mainToken, Token lparen, Token rparen, Block block) {
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.lparen = lparen;
        this.rparen = rparen;
        this.block = block;
        setLineNo(intToken);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(intToken.getPrintInfo());
        info.append(mainToken.getPrintInfo());
        info.append(lparen.getPrintInfo());
        info.append(rparen.getPrintInfo());
        info.append(block.getPrintInfo());
        info.append("<MainFuncDef>\n");
        return info;
    }

}
