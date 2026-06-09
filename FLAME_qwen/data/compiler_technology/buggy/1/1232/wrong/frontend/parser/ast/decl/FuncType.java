package frontend.parser.ast.decl;

import frontend.lexer.Token;

public class FuncType {
    private String type = "<FuncType>";
    private Token funcType;

    public FuncType(Token funcType) {
        this.funcType = funcType;
    }

    public String getOutput() {
        return funcType.getOutput() + type + "\n";
    }

    public String getOutputMain() {
        return funcType.getOutput();
    }

}
