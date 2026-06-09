package frontend.parser.decl.vardecl;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.BType;
import frontend.parser.decl.DeclNode;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 变量声明		VarDecl        ==> BType VarDef { ',' VarDef } ';' // i
public class VarDecl implements DeclNode {
    private final String name = "<VarDecl>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private BType bType;
    private ArrayList<VarDef> varDefs = new ArrayList<>(); // at least one

    public VarDecl(TokenIterator tokens) {
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
        bType = new BType(tokens);
        bType.parse();
        children.add(bType);

        VarDef varDef = new VarDef(tokens);
        varDef.parse();
        varDefs.add(varDef);
        children.add(varDef);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            if (token.getType().equals(TokenType.COMMA)) {
                children.add(token);

                // VarDef
                varDef = new VarDef(tokens);
                varDef.parse();
                varDefs.add(varDef);
                children.add(varDef);

            } else {
                tokens.stepBack(1);
                ErrorHandler.handleIError(tokens, children);
                break;
            }

        }
        return true;
    }

}
