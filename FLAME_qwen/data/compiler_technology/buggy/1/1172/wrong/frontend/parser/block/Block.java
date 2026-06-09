package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;

import java.util.LinkedList;

/**
 * 表示代码块的类，实现了 SyntaxOutput 接口。
 */
public class Block implements SyntaxOutput {
    // 语法节点名称常量
    private static final String NODE_NAME = "<Block>";
    // 左大括号 Token
    private Token leftBraceToken;
    // 代码块项的列表
    private LinkedList<BlockItem> blockItemList;
    // 右大括号 Token
    private Token rightBraceToken;

    /**
     * 构造函数，初始化代码块的各个部分。
     *
     * @param leftBraceToken  左大括号 Token
     * @param blockItemList   代码块项的列表
     * @param rightBraceToken 右大括号 Token
     */
    public Block(Token leftBraceToken, LinkedList<BlockItem> blockItemList, Token rightBraceToken) {
        this.leftBraceToken = leftBraceToken;
        this.blockItemList = blockItemList;
        this.rightBraceToken = rightBraceToken;
    }

    /**
     * 生成代码块的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();
        syntaxBuilder.append(leftBraceToken.toSyntaxString());
        for (BlockItem blockItem : blockItemList) {
            syntaxBuilder.append(blockItem.toSyntaxString());
        }
        syntaxBuilder.append(rightBraceToken.toSyntaxString());
        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
