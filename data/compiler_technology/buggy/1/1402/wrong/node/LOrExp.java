package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/* 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
   左递归，改写成 LOrExp → LAndExp { '||' LAndExp }
   花括号重复n次，就是n个LAndExp */
public class LOrExp {
    private String nodeName;
    private List<Token> orTokenList = new ArrayList<>();
    private List<LAndExp> lAndExpList = new ArrayList<>();

    public LOrExp(String nodeName, List<Token> orTokenList, List<LAndExp> lAndExpList) {
        this.nodeName = nodeName;
        this.orTokenList = orTokenList;
        this.lAndExpList = lAndExpList;
    }

    public void print() throws IOException {
        lAndExpList.get(0).print();
        writeParser(nodeName);
        if (!orTokenList.isEmpty()) {
            for (int i = 1; i < lAndExpList.size(); i++) {
                writeParser(orTokenList.get(i - 1).toString());
                lAndExpList.get(i).print();
                writeParser(nodeName);
            }
        }
    }
}
