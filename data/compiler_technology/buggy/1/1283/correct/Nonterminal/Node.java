package Nonterminal;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - Node
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public interface Node {
    void output(BufferedWriter writer) throws IOException;
}
