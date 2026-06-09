package frontend.Parser.Class;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class UnaryOp {
    private Token.tokenType type;

    public UnaryOp(Token.tokenType type, ArrayList<String> outputList) {
        this.type = type;
        outputList.add("<UnaryOp>");
    }
}
