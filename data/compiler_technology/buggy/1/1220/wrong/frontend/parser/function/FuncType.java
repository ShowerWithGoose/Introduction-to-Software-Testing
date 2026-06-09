package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

public class FuncType implements SyntaxUnit {
    private final String name = "<FuncType>";
    private Token funcType;
    public FuncType(Token funcType) {
        this.funcType = funcType;
    }

    @Override
    public String syntaxPrint() {
        //FuncType â†’ 'void' | 'int' | 'char'
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
