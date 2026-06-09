package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

import java.util.ArrayList;

/**
 * MultiExp 二元表达式顶层抽象类
 * （！注意区分 MulExp！）
 * 由MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp继承
 * 对于不同子类，T为其文法定义中的非终结符。具体地，MulExp->UnaryExp
 * 采用泛型对不同类别进行支持
 * 消除了左递归文法
 */
public class MultiExp<T extends SyntaxNode> implements SyntaxNode {
    /**
     * 属性：
     * first 首非终结符
     * operators 操作符列表
     * operands 非终结符列表
     * name 该语法类名
     */
    private T first;
    private ArrayList<Token> operators;
    private ArrayList<T> operands;
    private String name;

    public MultiExp(T first, ArrayList<Token> operators, ArrayList<T> operands, String name) {
        this.first = first;
        this.operators = operators;
        this.operands = operands;
        this.name = name;
    }

    /**
     * syntaxOutput()
     * 语法树输出方法，用于正确输出语法树的结果
     * 按列表顺序输出 <非终结符>，操作符，<非终结符>，……
     * @return
     */
    @Override
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
}
