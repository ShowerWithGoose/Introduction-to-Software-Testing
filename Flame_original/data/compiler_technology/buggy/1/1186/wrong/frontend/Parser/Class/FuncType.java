package frontend.Parser.Class;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class FuncType {
    Token.tokenType funcType;

    public FuncType(Token.tokenType funcType, ArrayList<String> outputList) {
        this.funcType = funcType;
        outputList.add("<FuncType>");
    }
    public Token.tokenType getFuncType(){
        return funcType;
    }

}
