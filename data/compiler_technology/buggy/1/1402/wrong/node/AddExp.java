package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/* 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    左递归文法，改写成 AddExp → MulExp { ('+' | '−') MulExp }
    花括号重复n次，就有n个AddExp */
public class AddExp {
    private String nodeName;
    private List<MulExp> mulExpList = new ArrayList<>();
    private List<Token> tokenList = new ArrayList<>();

    public AddExp(String nodeName, List<MulExp> mulExpList, List<Token> tokenList) {
        this.nodeName = nodeName;
        this.mulExpList = mulExpList;
        this.tokenList = tokenList;
    }

    public void print() throws IOException {
        mulExpList.get(0).print();
        writeParser(nodeName);
        if (!tokenList.isEmpty()) {
            for (int i = 1; i < mulExpList.size(); i++) {
                writeParser(tokenList.get(i - 1).toString());
                mulExpList.get(i).print();
                writeParser(nodeName);
            }
        }
    }
}
