package struct;

import token.Token;

import java.util.List;

/* EqExp â†’ RelExp { ('==' | '!=') RelExp } */
public class EqExp {
    private final List<RelExp> relExp;
    private final List<Token> operater;

    public EqExp(List<RelExp> relExp, List<Token> operater) {
        this.relExp = relExp;
        this.operater = operater;
    }

    public List<RelExp> getRelExp() {
        return relExp;
    }

    public List<Token> getOperater() {
        return operater;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(relExp.get(0).toString());
        for (int i = 1; i < relExp.size(); i++) {
            sb.append("<EqExp>\n");
            sb.append(operater.get(i - 1).toString());
            sb.append(relExp.get(i).toString());
        }
        sb.append("<EqExp>\n");
        return sb.toString();
    }
}
