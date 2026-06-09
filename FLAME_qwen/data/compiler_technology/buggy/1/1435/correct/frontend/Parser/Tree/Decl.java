package frontend.Parser.Tree;

import java.util.function.Consumer;

/**
 * @author
 * @Description:
 * @date 2024/10/12 13:04
 */
public abstract class Decl extends SyntaxSymbol{
    public void func(Consumer<TerminalSymbol> terminalSymbolConsumer, Consumer<NonTerminalSymbol> nonTerminalSymbolConsumer){


    }

    public String getType(){
        return "Decl";
    }
}
