package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/* 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
左递归，改写成RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
花括号重复n次，就是有n-1个RelExp */
public class RelExp {
    private String nodeName;
    private List<AddExp> addExpList = new ArrayList<>();
    private List<Token> tokenList = new ArrayList<>();

    public RelExp(String nodeName, List<AddExp> addExpList, List<Token> tokenList) {
        this.nodeName = nodeName;
        this.addExpList = addExpList;
        this.tokenList = tokenList;
    }

    public void print() throws IOException {
        addExpList.get(0).print();
        writeParser(nodeName);
        if (!tokenList.isEmpty()) {
            for (int i = 1; i < addExpList.size(); i++) {
                writeParser(tokenList.get(i - 1).toString());
                addExpList.get(i).print();
                writeParser(nodeName);
            }
        }
    }

}
