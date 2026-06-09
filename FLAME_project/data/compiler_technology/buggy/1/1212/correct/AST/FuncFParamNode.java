package AST;

import Lexer.Token;
import IO.*;

import java.io.IOException;

public class FuncFParamNode extends ASTNode {

    ASTNodes type = ASTNodes.FuncFParam;
    Token Btype;

    Token ident;

    boolean isArray;
    public FuncFParamNode(Token Btype, Token ident, boolean isArray) {
        this.Btype = Btype;
        this.ident = ident;
        this.isArray = isArray;
    }

    public ASTNodes getType() {
        return type;
    }

    public boolean isArray() {
        return isArray;
    }

    public Token getBtype() {
        return Btype;
    }

    public Token getIdent() {
        return ident;
    }


    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(Btype.getType() + " " + Btype.getToken() + "\n");
        io.getParserWriter().write(ident.getType() + " " + ident.getToken() + "\n");
        if (isArray) {
            io.getParserWriter().write("LBRACK [\n");
            io.getParserWriter().write("RBRACK ]\n");
        }
        io.getParserWriter().write("<FuncFParam>\n");
    }

    
    public void postOrderNoPrint() {

        if (isArray) {

        }
    }
}
