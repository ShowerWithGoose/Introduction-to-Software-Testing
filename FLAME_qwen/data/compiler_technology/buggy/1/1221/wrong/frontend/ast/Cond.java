package frontend.ast;

import java.io.BufferedWriter;
import java.io.IOException;

public class Cond implements AstNode {
    private final LOrExp lorExp;

    public Cond(LOrExp lorExp) {
        this.lorExp = lorExp;
    }

    @Override
    public String getSymbol() {
        return "<Cond>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        lorExp.printToFile(bw);
        bw.write(getSymbol() + "\n");
    }
}
