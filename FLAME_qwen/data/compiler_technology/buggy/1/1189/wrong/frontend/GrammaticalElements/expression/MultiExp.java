package frontend.GrammaticalElements.expression;

import frontend.Token;

import java.util.ArrayList;

// 由MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp继承
public class MultiExp<T> {
    private String name;
    private T first;
    private ArrayList<Token> operator;
    private ArrayList<T> operands;

    public MultiExp(String name, T first, ArrayList<Token> operator, ArrayList<T> operands) {
        this.name = name;
        this.first = first;
        this.operator = operator;
        this.operands = operands;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.toString());
        sb.append(this.name).append("\n");
        if (operator != null) {
            for (int i = 0; i < operator.size(); i++) {
                sb.append(operator.get(i).toString());
                sb.append(operands.get(i).toString());
                sb.append(this.name).append('\n');
            }
        }
        return sb.toString();
    }
}
