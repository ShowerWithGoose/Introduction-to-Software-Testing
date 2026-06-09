package struct;

import token.Token;

import java.util.List;

/* AddExp â†’ MulExp { ('+' | '-') MulExp } */
public class AddExp {
    private final List<MulExp> mulExp;
    private final List<Token> operater;

    public AddExp(List<MulExp> mulExp, List<Token> operater) {
        this.mulExp = mulExp;
        this.operater = operater;
    }

    public List<MulExp> getMulExp() {
        return mulExp;
    }

    public List<Token> getOperater() {
        return operater;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(mulExp.get(0).toString());
        for (int i = 1; i < mulExp.size(); i++) {
            sb.append("<AddExp>\n");
            sb.append(operater.get(i - 1).toString());
            sb.append(mulExp.get(i).toString());
        }
        sb.append("<AddExp>\n");
        return sb.toString();
    }
}
