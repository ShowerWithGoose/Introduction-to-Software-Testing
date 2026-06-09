package node;

import java.io.IOException;

import static utils.IO.writeParser;

// 表达式 Exp → AddExp
public class Exp {
    private String nodeName;
    private AddExp addExp;

    public Exp(String nodeName, AddExp addExp) {
        this.nodeName = nodeName;
        this.addExp = addExp;
    }

    public void print() throws IOException {
        addExp.print();
        writeParser(nodeName);
    }
}
