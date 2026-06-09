package frontend.ast;

import java.io.BufferedWriter;
import java.io.IOException;

public interface AstNode {
    String getSymbol();

    void printToFile(BufferedWriter bw) throws IOException;
}
