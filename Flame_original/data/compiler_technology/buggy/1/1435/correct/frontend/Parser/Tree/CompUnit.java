package frontend.Parser.Tree;

import java.util.ArrayList;
import java.util.function.Consumer;

public class CompUnit extends SyntaxSymbol{
    private final ArrayList<Decl> declList = new ArrayList<Decl>();
    private final ArrayList<FuncDef> funcDefList = new ArrayList<FuncDef>();
    private final MainFuncDef mainFuncDef= new MainFuncDef();
    public void func(Consumer<TerminalSymbol> terminalSymbolConsumer, Consumer<NonTerminalSymbol> nonTerminalSymbolConsumer){
        for(Decl decl : declList){
            decl.func(terminalSymbolConsumer, nonTerminalSymbolConsumer);
        }

        for(FuncDef funcDef : funcDefList){
            funcDef.func(terminalSymbolConsumer, nonTerminalSymbolConsumer);
        }

        mainFuncDef.func(terminalSymbolConsumer, nonTerminalSymbolConsumer);

        nonTerminalSymbolConsumer.accept(new NonTerminalSymbol(this));

    }

    public String getType(){
        return "CompUnit";
    }
}
