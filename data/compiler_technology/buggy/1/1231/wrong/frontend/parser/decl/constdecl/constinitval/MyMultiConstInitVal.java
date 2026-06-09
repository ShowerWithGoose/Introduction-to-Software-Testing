package frontend.parser.decl.constdecl.constinitval;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.exp.ConstExp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// '{' [ ConstExp { ',' ConstExp } ] '}' 
public class MyMultiConstInitVal implements ConstInitValNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private ConstExp first; // optional
    private ArrayList<ConstExp> constExps = new ArrayList<>(); // optional

    public MyMultiConstInitVal(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder str = new StringBuilder();
        children.forEach(child -> str.append(child.syntaxPrinter()));
        return str.toString();
    }

    @Override
    public boolean parse() {
        Token token = tokens.next();
        if (!token.getType().equals(TokenType.LBRACE)) {
            tokens.stepBack(1);
            return false;
        }
        children.add(token);

        // NOTE: first is optional
        // NOTE: no need to handle K_MISSING_RIGHT_BRACKET error

        token = tokens.next();
        if (!token.getType().equals(TokenType.RBRACE)) {
            tokens.stepBack(1);
            first = new ConstExp(tokens);
            first.parse();
            children.add(first);
        } else {
            tokens.stepBack(1);
        }

        while (tokens.hasNext()) {
            token = tokens.next();
            if (token.getType().equals(TokenType.COMMA)) {
                children.add(token);

                ConstExp constExp = new ConstExp(tokens);
                constExp.parse();
                constExps.add(constExp);
                children.add(constExp);
            } else {
                tokens.stepBack(1);
                break;
            }
        }

        token = tokens.next();
        children.add(token);

        return true;
    }

}
