package frontend.Parser.Exp;

import frontend.Token;
import frontend.Parser.Output;

import java.util.ArrayList;

public class BinaryExp<T extends Output> implements Output{
    private String name;
    private T first;//第一个exp
    private ArrayList<Token> op;
    private ArrayList<T> others;//其他表达式

    public BinaryExp(String name, T first, ArrayList<Token> op, ArrayList<T> others) {
        this.name = name;
        this.first = first;
        this.op = op;
        this.others = others;
    }


    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.first.Parser_Output());
        sb.append(this.name + "\n");
        if(op != null && others != null && op.size() == others.size()) {
            for (int i = 0; i < op.size(); i++) {
                sb.append(op.get(i).toString());
                sb.append(others.get(i).Parser_Output());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
