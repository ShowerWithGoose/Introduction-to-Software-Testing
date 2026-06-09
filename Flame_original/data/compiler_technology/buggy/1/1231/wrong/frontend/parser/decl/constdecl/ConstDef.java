package frontend.parser.decl.constdecl;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.ConstExp;
import frontend.parser.terminal.Ident;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 常量定义        ConstDef          == > Ident [ '[' ConstExp ']' ] '=' ConstInitVal // b k
public class ConstDef implements SyntaxNode {
    private final String name = "<ConstDef>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Ident ident;
    private ConstExp constExp; // optional
    private ConstInitVal constInitVal;

    public ConstDef(TokenIterator tokens) {
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
        ident = new Ident(tokens);
        ident.parse();
        children.add(ident);

        Token token = tokens.next();
        if (token.getType() == TokenType.LBRACK) {
            // is an array
            children.add(token);

            constExp = new ConstExp(tokens);
            constExp.parse();
            children.add(constExp);

            ErrorHandler.handleKError(tokens, children);
        } else {
            // not an array
            tokens.stepBack(1);
        }

        token = tokens.next();
        children.add(token);

        constInitVal = new ConstInitVal(tokens);
        constInitVal.parse();
        children.add(constInitVal);

        return true;
    }
}
