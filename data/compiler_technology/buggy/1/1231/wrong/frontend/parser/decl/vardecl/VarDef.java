package frontend.parser.decl.vardecl;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.ConstExp;
import frontend.parser.terminal.Ident;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

/* 变量定义	VarDef  ==> Ident [ '[' ConstExp ']' ] [ '='InitVal ] // b k
*/
public class VarDef implements SyntaxNode {
    private final String name = "<VarDef>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Ident ident;
    private ConstExp constExp; // optional
    private InitVal initVal; // optinal

    public VarDef(TokenIterator tokens) {
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
        if (token.getType().equals(TokenType.LBRACK)) {
            // is an array
            children.add(token); // '['

            constExp = new ConstExp(tokens);
            constExp.parse();
            children.add(constExp);

            ErrorHandler.handleKError(tokens, children);
        } else {
            tokens.stepBack(1);
        }

        token = tokens.next();
        // check init value
        if (token.getType().equals(TokenType.ASSIGN)) {
            // has init value
            children.add(token);
            initVal = new InitVal(tokens);
            initVal.parse();
            children.add(initVal);
        } else {
            // no init value
            tokens.stepBack(1);
        }

        return true;
    }

}
