package frontend.ast;

import java.io.BufferedWriter;
import java.io.IOException;

public class ConstExp implements AstNode {
    private final AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String getSymbol() {
        return "<ConstExp>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        addExp.printToFile(bw);
        bw.write(getSymbol() + "\n");
    }
}
