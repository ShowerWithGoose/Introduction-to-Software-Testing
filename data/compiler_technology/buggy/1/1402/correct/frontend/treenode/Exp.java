package frontend.treenode;

import java.io.IOException;
import static frontend.executor.Parser.writeParser;

// 表达式 Exp → AddExp
public class Exp {
    public String nodeName;
    public AddExp addExp;

    public Exp(String nodeName, AddExp addExp) {
        this.nodeName = nodeName;
        this.addExp = addExp;
    }

    public void print() throws IOException {
        addExp.print();
        writeParser(nodeName);
    }
}
