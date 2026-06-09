package frontend.Parser.Tree;

import java.util.function.Consumer;

public abstract class SyntaxSymbol {
    public abstract void func(Consumer<TerminalSymbol> terminalSymbolConsumer, Consumer<NonTerminalSymbol> nonTerminalSymbolConsumer);
    public abstract String getType();
}
