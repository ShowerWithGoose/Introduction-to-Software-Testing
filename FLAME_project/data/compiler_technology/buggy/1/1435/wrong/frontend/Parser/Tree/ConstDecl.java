package frontend.Parser.Tree;

import java.util.function.Consumer;

/**
 * @author
 * @Description:
 * @date 2024/10/13 16:57
 */
public class ConstDecl extends SyntaxSymbol{
    private BType bType;
    private ConstDef constDef;
    @Override
    public void func(Consumer<TerminalSymbol> terminalSymbolConsumer, Consumer<NonTerminalSymbol> nonTerminalSymbolConsumer) {

    }

    @Override
    public String getType() {
        return "ConstDecl";
    }
}
