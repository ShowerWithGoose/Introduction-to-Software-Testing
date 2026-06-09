package AST;

import Lexer.Token;

import java.io.IOException;
import java.util.Objects;

import java.util.ArrayList;
import IO.*;
public class StringConst extends ASTNode{

    ASTNodes type = ASTNodes.StringConst;
    Token string;

    public StringConst(Token string) {
        this.string = string;
    }

    public Token getString() {
        return string;
    }

    public boolean isNullString() {
        return Objects.equals(string, "\n");
    }

    public ASTNodes getType() {
        return type;
    }


    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write(string.getType() + " " + string.getToken() + "\n");
    }

    
    public void postOrderNoPrint() {

    }

    public ArrayList<String> getFormatChars() {
        ArrayList<String> formatChars = new ArrayList<>();
        for (int i = 0; i < string.getToken().length(); i++) {
            if (string.getToken().charAt(i) == '%') {
                int j = i + 1;
                if (j < string.getToken().length() && string.getToken().charAt(j) == 'c') {
                    formatChars.add("%c\n");
                    i += 1;
                }
                else if (j < string.getToken().length() && string.getToken().charAt(j) == 'd') {
                    formatChars.add("%s\n");
                    i += 1;
                }
            }
        }
        return formatChars;
    }
}
