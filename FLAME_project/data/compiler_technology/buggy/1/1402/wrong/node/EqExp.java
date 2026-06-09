package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/* 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
左递归，改写成 EqExp → RelExp { ('==' | '!=') RelExp }
花括号重复n次，就是n-1个EqExp */
public class EqExp {
    private String nodeName;
    private List<Token> tokenList = new ArrayList<>();
    private List<RelExp> relExpList = new ArrayList<>();

    public EqExp(String nodeName, List<Token> tokenList, List<RelExp> relExpList) {
        this.nodeName = nodeName;
        this.tokenList = tokenList;
        this.relExpList = relExpList;
    }

    public void print() throws IOException {
        relExpList.get(0).print();
        writeParser(nodeName);
        if (!tokenList.isEmpty()) {
            for (int i = 1; i < relExpList.size(); i++) {
                writeParser(tokenList.get(i - 1).toString());
                relExpList.get(i).print();
                writeParser(nodeName);
            }
        }

    }
}
