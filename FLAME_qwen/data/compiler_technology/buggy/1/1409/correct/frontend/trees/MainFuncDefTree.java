package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class MainFuncDefTree extends Tree {
    public BlockTree mainBlock;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("INTTK int");
        printStream.println("MAINTK main");
        printStream.println("LPARENT (");
        printStream.println("RPARENT )");
        mainBlock.walk(printStream);
        printStream.println("<MainFuncDef>");
//        terminalConsumer.accept(new TerminalSymbol(LexType.INTTK));
//        terminalConsumer.accept(new TerminalSymbol(LexType.MAINTK));
//        terminalConsumer.accept(new TerminalSymbol(LexType.LPARENT));
//        terminalConsumer.accept(new TerminalSymbol(LexType.RPARENT));
//
//        mainBlock.walk(terminalConsumer, nonTerminalConsumer);
//
//        nonTerminalConsumer.accept(new NonTerminalSymbol(this));

    }

    @Override
    public String getType() {
        return "MainFuncDef";
    }
}
