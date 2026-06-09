package struct;

import token.Token;

import java.util.List;

/* RelExp â†’ AddExp { ('<' | '>' | '<=' | '>=') AddExp } */
public class RelExp {
    private final List<AddExp> addExp;
    private final List<Token> operater;

    public RelExp(List<AddExp> addExp, List<Token> operater) {
        this.addExp = addExp;
        this.operater = operater;
    }

    public List<AddExp> getAddExp() {
        return addExp;
    }

    public List<Token> getOperater() {
        return operater;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.get(0).toString());
        for (int i = 1; i < addExp.size(); i++) {
            sb.append("<RelExp>\n");
            sb.append(operater.get(i - 1).toString());
            sb.append(addExp.get(i).toString());
        }
        sb.append("<RelExp>\n");
        return sb.toString();
    }
}
