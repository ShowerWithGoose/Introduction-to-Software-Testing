package frontend.Symbol;

import frontend.Error.ErrorType;
import frontend.Visitor.Visitor;

public class SymbolManager
{
    private static final SymbolManager instance = new SymbolManager();
    private final SymbolTable root;
    private SymbolTable curTable;
    private int tableId = 0;
    private static int symbolId = 0;



    private SymbolManager(){
        tableId++;
        root = new SymbolTable(tableId, null);
        curTable = root;
    }
    public static SymbolManager GetInstance(){
        return instance;
    }


    public void CreateSymbolTable(){
        tableId++;
        SymbolTable symbolTable = new SymbolTable(tableId, curTable);
        curTable.AddChild(symbolTable);
        curTable = symbolTable;
    }

    public void BackSymbolTable(){
        curTable = curTable.GetParent();
    }

    public void AddSymbol(Symbol symbol){
        if(curTable.hasSymbol(symbol.getToken().getContent())){
            Visitor.GetInstance().Error(ErrorType.VarAlreadyDefined, symbol.getToken());
            return;
        }
        curTable.AddSymbol(symbol.getToken().getContent(),symbol);
        symbol.setId(++symbolId);
        symbol.setTableID(curTable.getId());
    }

    public void AddSymbols(Symbol[] symbols){
        for(Symbol symbol : symbols){
            AddSymbol(symbol);
        }
    }

    public Symbol TrySearchSymbol(String name){
        SymbolTable symbolTable = curTable;
        while(symbolTable != null){
            if(symbolTable.hasSymbol(name)){
                return symbolTable.GetSymbol(name);
            }
            symbolTable = symbolTable.GetParent();
        }
        return null;
    }


    public void PrintSymbol() {
        DFS(root);
    }

    private void DFS(SymbolTable node){
        node.PrintSymbols();
        for (SymbolTable child : node.getChildren()) {
            DFS(child);
        }

    }
}
