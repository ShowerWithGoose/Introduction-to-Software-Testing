package parse;

import parse.Token;

import java.util.ArrayList;

public class MultiExp<T extends PrintInter> implements PrintInter{
    private T firstword; 
    private ArrayList<Token> operators;
    private ArrayList<T> operands; 
    private String name;

    public T getFirstword() {
        return firstword;
    }

    public void setFirstword(T firstword) {
        this.firstword = firstword;
    }

    public ArrayList<Token> getOperators() {
        return operators;
    }

    public void setOperators(ArrayList<Token> operators) {
        this.operators = operators;
    }

    public ArrayList<T> getOperands() {
        return operands;
    }

    public void setOperands(ArrayList<T> operands) {
        this.operands = operands;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public MultiExp(T firstword, ArrayList<Token> operators, ArrayList<T> operands, String name) {
        this.firstword = firstword;
        this.operators = operators;
        this.operands = operands;
        this.name = name;
    }

    public void setall(T firstword, ArrayList<Token> operators, ArrayList<T> operands, String name) {
        this.firstword = firstword;
        this.operators = operators;
        this.operands = operands;
        this.name = name;
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstword.printout());
        sb.append(this.name + "\n");
        if (operators != null && operands != null && operators.size() == operands.size()) {
            int len = operators.size();
            for (int i = 0; i < len; i++) {
                sb.append(operators.get(i).printout());
                sb.append(operands.get(i).printout());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
