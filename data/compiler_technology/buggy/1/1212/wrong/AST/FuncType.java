package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class FuncType extends ASTNode{
    ASTNodes type = ASTNodes.FuncType;

    Token Btype;

    public FuncType(Token type) {
        this.Btype = type;
    }

    public ASTNodes getType() {
        return type;
    }

    public Token getBtype() {
        return Btype;
    }


    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(Btype.getType() + " " + Btype.getToken() + "\n");
        io.getParserWriter().write("<FuncType>\n");
    }

    
    public void postOrderNoPrint() {

    }
}
