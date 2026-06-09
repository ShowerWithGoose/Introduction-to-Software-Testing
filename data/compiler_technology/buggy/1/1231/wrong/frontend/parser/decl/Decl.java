package frontend.parser.decl;

import frontend.TokenIterator;
import frontend.parser.block.BlockItemNode;
import frontend.parser.decl.constdecl.ConstDecl;
import frontend.parser.decl.vardecl.VarDecl;
import nodes.Token;
import nodes.TokenType;

/*
 * 声明	Decl ==> ConstDecl | VarDecl
 */
public class Decl implements BlockItemNode {

    private static String name = "<Decl>";
    private TokenIterator tokens;
    private DeclNode declNode;

    public Decl(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        // NOTE: Decl no need to output
        StringBuilder sb = new StringBuilder();
        sb.append(declNode.syntaxPrinter());
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Token checkConst = tokens.next();
        if (checkConst.getType().equals(TokenType.CONSTTK)) {
            tokens.stepBack(1);
            declNode = new ConstDecl(tokens);
        } else {
            tokens.stepBack(1);
            declNode = new VarDecl(tokens);

        }
        return declNode.parse();
    }

}
