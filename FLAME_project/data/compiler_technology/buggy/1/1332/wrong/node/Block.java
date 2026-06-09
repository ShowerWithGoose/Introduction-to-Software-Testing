package node;

import token.Token;

import java.util.List;

/**
 * ClassName: Block
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:01
 * @Version 1.0
 */
public class Block extends Node{
    // Block => '{' {BlockItem} '}'
    public Token lbrace;
    public List<BlockItem> blockItems;
    public Token rbrace;

    public Block(Token lbrace, List<BlockItem> blockItems, Token rbrace) {
        this.lbrace = lbrace;
        this.blockItems = blockItems;
        this.rbrace = rbrace;
        setLineNo(lbrace);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(lbrace.getPrintInfo());
        for (BlockItem blockItem : blockItems) {
            info.append(blockItem.getPrintInfo());
        }
        info.append(rbrace.getPrintInfo());
        info.append("<Block>\n");
        return info;
    }
}
