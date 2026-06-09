package node;

import java.io.IOException;

import static utils.IO.writeParser;

public class Cond {
    private String nodeName;
    private LOrExp lOrExp;

    public Cond(String nodeName, LOrExp lOrExp) {
        this.nodeName = nodeName;
        this.lOrExp = lOrExp;
    }

    public void print() throws IOException {
        lOrExp.print();
        writeParser(nodeName);
    }
}
