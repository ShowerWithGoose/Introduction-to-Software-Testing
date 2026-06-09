package frontend.treenode;

import java.io.IOException;
import static frontend.executor.Parser.writeParser;

public class ConstExp {
    public String nodeName;
    public AddExp addExp;

    public ConstExp(String nodeName, AddExp addExp) {
        this.nodeName = nodeName;
        this.addExp = addExp;
    }

    public void print() throws IOException {
        addExp.print();
        writeParser(nodeName);
    }
}
