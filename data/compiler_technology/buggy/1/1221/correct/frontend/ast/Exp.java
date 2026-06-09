package frontend.ast;

import java.io.BufferedWriter;
import java.io.IOException;

public class Exp implements AstNode {
    private final AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String getSymbol() {
        return "<Exp>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        addExp.printToFile(bw);
        bw.write(getSymbol() + "\n");
    }
}
