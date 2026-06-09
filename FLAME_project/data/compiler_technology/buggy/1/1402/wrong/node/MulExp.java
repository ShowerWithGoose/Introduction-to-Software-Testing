package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/* 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
 左递归文法，改写成 MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp }
 花括号重复n次，就有n个MulExp */
public class MulExp {
    private String nodeName;
    private List<UnaryExp> unaryExpList = new ArrayList<>();
    private List<Token> tokenList = new ArrayList<>(); //存放乘号、除号、模

    public MulExp(String nodeName, List<UnaryExp> unaryExpList, List<Token> tokenList) {
        this.nodeName = nodeName;
        this.unaryExpList = unaryExpList;
        this.tokenList = tokenList;
    }

    public void print() throws IOException {
        unaryExpList.get(0).print();
        writeParser(nodeName);
        if (!tokenList.isEmpty()) {
            for (int i = 1; i < unaryExpList.size(); i++) {
                writeParser(tokenList.get(i-1).toString());
                unaryExpList.get(i).print();
                writeParser(nodeName);
            }
        }

    }
}
