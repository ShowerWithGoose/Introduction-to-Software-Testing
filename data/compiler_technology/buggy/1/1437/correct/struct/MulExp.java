package struct;

import token.Token;

import java.util.List;

/* MulExp â†’ UnaryExp { ('*' | '/' | '%') UnaryExp } */
public class MulExp {
    private final List<UnaryExp> unaryExp;
    private final List<Token> operater;

    public MulExp(List<UnaryExp> unaryExp, List<Token> operater) {
        this.unaryExp = unaryExp;
        this.operater = operater;
    }

    public List<UnaryExp> getUnaryExp() {
        return unaryExp;
    }

    public List<Token> getOperater() {
        return operater;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExp.get(0).toString());
        for (int i = 1; i < unaryExp.size(); i++) {
            sb.append("<MulExp>\n");
            sb.append(operater.get(i - 1).toString());
            sb.append(unaryExp.get(i).toString());
        }
        sb.append("<MulExp>\n");
        return sb.toString();
    }
}
