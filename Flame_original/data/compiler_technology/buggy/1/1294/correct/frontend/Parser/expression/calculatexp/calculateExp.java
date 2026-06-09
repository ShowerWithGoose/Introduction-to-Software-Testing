package frontend.Parser.expression.calculatexp;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;

import java.util.ArrayList;

//对于左递归文法的抽象类
//T为不同的文法定义中的非终结符
public class calculateExp<T extends GrammarNode> implements GrammarNode {
    private String grammarName;
    private T theOne; //左递归文法中至少含有的那一个非终结符
    private ArrayList<Token> operators; //操作符
    private ArrayList<T> operands; //操作数
    private String sonName;

    public calculateExp(T one, ArrayList<Token> operators, ArrayList<T> operands, String grammarName, String sonName) {
        this.grammarName = grammarName;
        this.theOne = one;
        this.operators = operators;
        this.operands = operands;
        this.sonName = sonName;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(theOne.grammarOutput());
        if (!operators.isEmpty()) {
            sb.append(this.grammarName).append("\n");
        }
        if (operators != null && operands != null && operators.size() == operands.size()) {
            for (int i = 0; i < operators.size(); i++) {
                sb.append(operators.get(i).grammarOutput());
                sb.append(operands.get(i).grammarOutput());
                if (i < operators.size() - 1) {
                    sb.append(this.grammarName).append("\n");
                }
            }
        }
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
