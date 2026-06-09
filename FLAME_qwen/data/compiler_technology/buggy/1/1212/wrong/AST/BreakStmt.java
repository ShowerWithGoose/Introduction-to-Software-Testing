package AST;

import Lexer.Token;

import IO.*;

import java.io.IOException;

public class BreakStmt extends ASTNode{
    ASTNodes type = ASTNodes.BREAK;

    Token token;

    public BreakStmt(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }
    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("BREAKTK break\n");
        io.getParserWriter().write("SEMICN ;\n");
    }

    
    public void postOrderNoPrint() {

    }
}
