package frontend.parser.func;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.block.Block;
import nodes.SyntaxNode;

// 主函数定义		MainFuncDef    ==> 'int' 'main' '(' ')' Block // g j
public class MainFuncDef implements SyntaxNode {
    private String name = "<MainFuncDef>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Block block;

    public MainFuncDef(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();

        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");

        return sb.toString();
    }

    @Override
    public boolean parse() {
        children.add(tokens.next());
        children.add(tokens.next());
        children.add(tokens.next());

        ErrorHandler.handleJError(tokens, children);

        block = new Block(tokens);
        block.parse();
        children.add(block);
        return true;
    }
}
