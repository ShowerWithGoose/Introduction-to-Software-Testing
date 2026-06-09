package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

/* 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    左递归。改写成 LAndExp → EqExp { '&&' EqExp }
    花括号重复n次就有n个LAndExp */
public class LAndExp {
    private String nodeName;
    private List<Token> andTokenList = new ArrayList<>();
    private List<EqExp> eqExpList = new ArrayList<>();

    public LAndExp(String nodeName, List<Token> andTokenList, List<EqExp> eqExpList) {
        this.nodeName = nodeName;
        this.andTokenList = andTokenList;
        this.eqExpList = eqExpList;
    }

    public void print() throws IOException {
        eqExpList.get(0).print();
        writeParser(nodeName);
        if (!andTokenList.isEmpty()) {
            for (int i = 1; i < eqExpList.size(); i++) {
                writeParser(andTokenList.get(i - 1).toString());
                eqExpList.get(i).print();
                writeParser(nodeName);
            }
        }
    }
}
