package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

import java.util.ArrayList;

public class MultiExp<T extends SyntaxNode> implements SyntaxNode{
    public T first;
    public ArrayList<Token> operators;
    public ArrayList<T> operands;
    public String name;
    public MultiExp(T first, ArrayList<Token> operators, ArrayList<T> operands, String name) {
        this.first = first;
        this.operators = operators;
        this.operands = operands;
        this.name = name;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        sb.append(this.name + "\n");
        if (operators != null && operands != null && operators.size() == operands.size()) {
            int len = operators.size();
            for (int i = 0; i < len; i++) {
                sb.append(operators.get(i).syntaxOutput());
                sb.append(operands.get(i).syntaxOutput());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
    public int my_line_num() {
        if(!this.operands.isEmpty()) {
            return this.operands.get(this.operands.size()-1).my_line_num();
        }else{
            return this.first.my_line_num();
        }
    }
}
