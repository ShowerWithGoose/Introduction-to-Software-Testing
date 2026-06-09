package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class LOrExpTreeForDouble extends LOrExpTree {
    public LOrExpTree lOrExp;
    public LAndExpTree lAndExp;

    @Override
    public void walk(PrintStream printStream) {
        lOrExp.walk(printStream);
        printStream.println("OR ||");


        lAndExp.walk(printStream);

        printStream.println("<LOrExp>");
    }
}
