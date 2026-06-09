package frontend.parser.expression.unaryExp;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

public class UnaryExp implements SyntaxUnit {
    private String name = "<UnaryExp>";
    private UnaryExpUnit unaryExpUnit;

    public UnaryExp(UnaryExpUnit unaryExpUnit) {
        this.unaryExpUnit = unaryExpUnit;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExpUnit.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
