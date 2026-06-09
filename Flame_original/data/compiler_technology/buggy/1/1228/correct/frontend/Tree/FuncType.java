package frontend.Tree;

import frontend.Lexer.LexType;

public class FuncType {
    private LexType funcType;

    public FuncType(LexType funcType){
        this.funcType=funcType;
    }

    public LexType getFuncType() {
        return funcType;
    }
}
