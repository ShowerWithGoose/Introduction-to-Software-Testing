package frontend.trees;

import frontend.LexType;

import java.io.PrintStream;
import java.util.function.Consumer;

public class CharacterTree extends Tree {
    public String charConst;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("CHRCON "+charConst);
        printStream.println("<Character>");
    }

    @Override
    public String getType() {
        return "Character";
    }
}
