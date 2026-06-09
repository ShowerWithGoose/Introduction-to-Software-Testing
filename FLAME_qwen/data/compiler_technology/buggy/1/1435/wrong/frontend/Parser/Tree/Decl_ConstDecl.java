package frontend.Parser.Tree;

import java.util.function.Consumer;

/**
 * @author
 * @Description:
 * @date 2024/10/13 17:02
 */
public class Decl_ConstDecl extends Decl{
    public ConstDecl constDecl;

    @Override
    public void func(Consumer<TerminalSymbol> terminalSymbolConsumer, Consumer<NonTerminalSymbol> nonTerminalSymbolConsumer) {
        constDecl.func(terminalSymbolConsumer, nonTerminalSymbolConsumer);

        nonTerminalSymbolConsumer.accept(new NonTerminalSymbol(this));////////??????
    }
}
