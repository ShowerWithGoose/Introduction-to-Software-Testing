package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

import java.util.ArrayList;

public class AddExp implements ASTNode {
    private MulExp firstMulExp;
    private ArrayList<Token> operators; // '+' or '-'
    private ArrayList<MulExp> mulExps;  // Remaining MulExp

    public AddExp(MulExp firstMulExp, ArrayList<Token> operators, ArrayList<MulExp> mulExps) {
        this.firstMulExp = firstMulExp;
        this.operators = operators;
        this.mulExps = mulExps;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstMulExp.printString());
        sb.append("<" + "AddExp" + ">\n");
        for (int i = 0; i < operators.size(); i++) {
            sb.append(operators.get(i));
            sb.append(mulExps.get(i).printString());
            sb.append("<" + "AddExp" + ">\n");
        }
        return sb.toString();
    }
}
