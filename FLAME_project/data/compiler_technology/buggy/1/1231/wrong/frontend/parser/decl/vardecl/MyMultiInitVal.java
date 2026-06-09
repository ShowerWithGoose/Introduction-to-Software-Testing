package frontend.parser.decl.vardecl;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// MyMultiInitVal     == > '{' [ Exp { ',' Exp } ] '}'
public class MyMultiInitVal implements InitValNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Exp first; // optional
    private ArrayList<Exp> exps = new ArrayList<>(); // optional

    public MyMultiInitVal(TokenIterator tokens) {
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

        first = new Exp(tokens);
        first.parse();
        children.add(first);

        while (tokens.hasNext()) {
            token = tokens.next();
            if (token.getType().equals(TokenType.COMMA)) {
                children.add(token);

                Exp exp = new Exp(tokens);
                exp.parse();
                exps.add(exp);
                children.add(exp);
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
