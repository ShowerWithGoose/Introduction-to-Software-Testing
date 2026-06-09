package node;

import java.io.IOException;

import static utils.IO.writeParser;

public class ConstExp {
    private String nodeName;
    private AddExp addExp;

    public ConstExp(String nodeName, AddExp addExp) {
        this.nodeName = nodeName;
        this.addExp = addExp;
    }

    public void print() throws IOException {
        addExp.print();
        writeParser(nodeName);
    }
}
