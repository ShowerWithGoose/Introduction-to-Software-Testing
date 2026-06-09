package frontend.parser.func;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.block.Block;
import frontend.parser.terminal.Ident;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//函数定义		FuncDef ==> FuncType Ident '(' [FuncFParams] ')' Block // b g j
public class FuncDef implements SyntaxNode {
    private String name = "<FuncDef>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private FuncType funcType;
    private Ident ident;
    private FuncFParams funcFParams;

    public FuncDef(TokenIterator tokens) {
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
        funcType = new FuncType(tokens);
        funcType.parse();
        children.add(funcType);

        ident = new Ident(tokens);
        ident.parse();
        children.add(ident);

        if (!tokens.hasNext()) {
            return false;
        }

        Token token = tokens.next();
        children.add(token); // (

        token = tokens.next();
        if (!token.getType().equals(TokenType.LBRACE) && !token.getType().equals(TokenType.RPARENT)) {
            tokens.stepBack(1);
            this.funcFParams = new FuncFParams(tokens);
            this.funcFParams.parse();
            children.add(funcFParams);
        } else {
            tokens.stepBack(1);
        }

        ErrorHandler.handleJError(tokens, children);

        Block block = new Block(tokens);
        block.parse();
        children.add(block);

        return true;
    }

}
