package frontend.expression.multiexp;

import frontend.SyntaxNode;
import frontend.Token;

import java.util.List;

/**
 * 二元表达式顶层抽象类
 * 由MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp继承
 * 对于不同子类，T为其文法定义中的非终结符。具体地，MulExp->UnaryExp
 * 采用泛型对不同类别进行支持
 * 消除了左递归文法
 */
public class MultiExp<T extends SyntaxNode> implements SyntaxNode {
    private final T first; // 首字符，一定存在
    private final List<Token> operators; // 操作符
    private final List<T> operands; // 操作数
    private final String name; // 语法类别名，为语法分析作业服务

    public MultiExp(T first, List<Token> operators, List<T> operands, String name) {
        if (first == null || name == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
        if (operators != null && operands != null && operators.size() != operands.size()) {
            throw new IllegalArgumentException("Operators and operands must have the same size");
        }
        this.first = first;
        this.operators = operators;
        this.operands = operands;
        this.name = name;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        sb.append(name).append("\n");
        if (operators != null && operands != null) {
            for (int i = 0; i < operators.size(); i++) {
                sb.append(operators.get(i).syntaxOutput());
                sb.append(operands.get(i).syntaxOutput());
                sb.append(name).append("\n");
            }
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}