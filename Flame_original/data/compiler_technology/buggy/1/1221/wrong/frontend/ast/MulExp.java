package frontend.ast;

import frontend.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MulExp implements AstNode {
    private final ArrayList<UnaryExp> unaryExps;
    private final ArrayList<Token> ops;

    public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<Token> ops) {
        this.unaryExps = unaryExps;
        this.ops = ops;
    }

    @Override
    public String getSymbol() {
        return "<MulExp>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        for (int i = 0; i < unaryExps.size(); i++) {
            unaryExps.get(i).printToFile(bw);
            bw.write(getSymbol() + "\n");
            if (i < ops.size()) {
                bw.write(ops.get(i) + "\n");
            }
        }
    }
}
