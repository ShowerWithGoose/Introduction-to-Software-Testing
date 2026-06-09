package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;

import java.util.List;
import frontend.Parser;
public class BlockNode {
    // Block → '{' { BlockItem } '}'
    public Token lBrace; // 指向 '{' 的叶节点
    public List<BlockItemNode> blockItems; // 块内项列表
    public Token rBrace; // 指向 '}' 的叶节点

    public BlockNode(Token lBrace, List<BlockItemNode> blockItems, Token rBrace) {
        this.lBrace = lBrace;
        this.blockItems = blockItems;
        this.rBrace = rBrace;
    }

    public void print() {
        IO.write(lBrace.toString());
        for (BlockItemNode blockItem : blockItems) {
            blockItem.print();
        }
        IO.write(rBrace.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.Block));
    }
}
