package frontend.parser.decl.constdecl;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.BType;
import frontend.parser.decl.DeclNode;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

/*
 * 常量声明		ConstDecl      ==> 'const' BType ConstDef { ',' ConstDef } ';' // i
 */
public class ConstDecl implements DeclNode {
    private final String name = "<ConstDecl>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private BType bType;
    private ArrayList<ConstDef> constDefs = new ArrayList<>(); // at least one

    public ConstDecl(TokenIterator tokens) {
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
        if (!tokens.hasNext()) {
            return false;
        }

        Token token = tokens.next();
        children.add(token);

        bType = new BType(tokens);
        bType.parse();
        children.add(bType);

        ConstDef constDef = new ConstDef(tokens);
        constDef.parse();
        constDefs.add(constDef);
        children.add(constDef);

        while (tokens.hasNext()) {
            token = tokens.next();

            if (token.getType().equals(TokenType.COMMA)) {

                children.add(token);

                // ConstDef
                constDef = new ConstDef(tokens);
                constDef.parse();
                constDefs.add(constDef);
                children.add(constDef);

            } else {
                tokens.stepBack(1);
                ErrorHandler.handleIError(tokens, children);
                break;
            }

        }
        return true;
    }
}
