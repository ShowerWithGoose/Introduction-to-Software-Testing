package AST;

import Lexer.Token;

import IO.*;

import java.io.IOException;

public class ContinueStmt extends ASTNode{

    ASTNodes type = ASTNodes.CONTINUE;

    Token token;

    public ContinueStmt(Token token) {
        this.token = token;
    }

    public ASTNodes getType() {
        return type;
    }

    public Token getToken() {
        return token;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("CONTINUETK continue\n");
        io.getParserWriter().write("SEMICN ;\n");
    }

    
    public void postOrderNoPrint() {

    }
}
