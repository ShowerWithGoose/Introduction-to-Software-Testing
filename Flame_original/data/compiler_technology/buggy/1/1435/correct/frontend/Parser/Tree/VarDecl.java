package frontend.Parser.Tree;

import java.util.function.Consumer;

/**
 * @author
 * @Description:
 * @date 2024/10/13 17:06
 */
public class VarDecl extends SyntaxSymbol{
    public void func(Consumer<TerminalSymbol> terminalSymbolConsumer, Consumer<NonTerminalSymbol> nonTerminalSymbolConsumer) {

    }

    @Override
    public String getType() {
        return "VarDecl";
    }
}
