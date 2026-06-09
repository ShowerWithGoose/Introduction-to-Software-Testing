package frontend.SyntaxUnits.Exps;

import frontend.SyntaxUnits.Exp;
import frontend.SyntaxUnits.SyntaxUnit;
import frontend.Token;

import java.util.ArrayList;

public class Exps<T extends SyntaxUnit> implements SyntaxUnit {
    private T toBegin;
    private ArrayList<Token> operators;
    private ArrayList<T> operands;
    private String expType;

    public Exps(T toBegin, ArrayList<Token> operators, ArrayList<T> operands, String expType) {
        this.toBegin = toBegin;
        this.operators = operators;
        this.operands = operands;
        this.expType = expType;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(toBegin.toPrint());
        stringBuilder.append(expType + "\n");
        if ((! operands.isEmpty()) && (! operators.isEmpty())) {
            for (int i = 0; i < operands.size(); i++) {
                stringBuilder.append(operators.get(i).toPrint());
                stringBuilder.append(operands.get(i).toPrint());
                stringBuilder.append(expType + "\n");
            }
        }
        return stringBuilder.toString();
    }
}
