package frontend.parser.exp.unaryexp;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.func.FuncRParams;
import frontend.parser.terminal.Ident;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//	MyFuncCallUnaryExp  == > Ident '(' [FuncRParams] ')' // c d e j 
public class MyFuncCallUnaryExp implements UnaryExpNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Ident ident;
    private FuncRParams funcRParams; // optional

    public MyFuncCallUnaryExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        return sb.toString();
    }

    @Override
    public boolean parse() {
        ident = new Ident(tokens);
        ident.parse();
        children.add(ident);

        Token token = tokens.next();
        children.add(token);

        token = tokens.next();
        // FuncRParams
        if (token.getType().equals(TokenType.SEMICN)) {
            tokens.stepBack(1);
            ErrorHandler.handleJError(tokens, children);
        } else if (!token.getType().equals(TokenType.RPARENT)) {
            tokens.stepBack(1);

            funcRParams = new FuncRParams(tokens);
            funcRParams.parse();
            children.add(funcRParams);

            ErrorHandler.handleJError(tokens, children);
        } else {
            children.add(token);
        }

        return true;
    }

}
