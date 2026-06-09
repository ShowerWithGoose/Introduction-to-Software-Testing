package frontend.treenode;

import java.io.IOException;
import static frontend.executor.Parser.writeParser;

public class Cond {
    public String nodeName;
    public LOrExp lOrExp;

    public Cond(String nodeName, LOrExp lOrExp) {
        this.nodeName = nodeName;
        this.lOrExp = lOrExp;
    }

    public void print() throws IOException {
        lOrExp.print();
        writeParser(nodeName);
    }
}
