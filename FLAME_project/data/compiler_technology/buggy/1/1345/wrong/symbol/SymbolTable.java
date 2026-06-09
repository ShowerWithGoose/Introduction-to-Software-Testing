package symbol;

import java.util.ArrayList;
import java.util.HashMap;

public class SymbolTable {
    private ArrayList<Symbol> symbols;
    private HashMap<String, Symbol> findsymbol;
    private SymbolTable parent;
    private ArrayList<SymbolTable> child;
    private int cycleDepth;
    private int tablenum;

    public SymbolTable(int i) {
        this.symbols = new ArrayList<>();
        this.findsymbol = new HashMap<>();
        this.parent = null;
        this.child = new ArrayList<>();
        this.cycleDepth = i;
        this.tablenum = 0;
    }

    public ArrayList<Symbol> getSymbols() {
        return symbols;
    }

    public void setSymbols(ArrayList<Symbol> symbols) {
        this.symbols = symbols;
    }

    public HashMap<String, Symbol> getFindsymbol() {
        return findsymbol;
    }

    public void setFindsymbol(HashMap<String, Symbol> findsymbol) {
        this.findsymbol = findsymbol;
    }

    public SymbolTable getParent() {
        return parent;
    }

    public void setParent(SymbolTable parent) {
        this.parent = parent;
    }

    public ArrayList<SymbolTable> getChild() {
        return child;
    }

    public void setChild(ArrayList<SymbolTable> child) {
        this.child = child;
    }

    public int getCycleDepth() {
        return cycleDepth;
    }

    public void setCycleDepth(int cycleDepth) {
        this.cycleDepth = cycleDepth;
    }

    public int getTablenum() {
        return tablenum;
    }

    public void setTablenum(int tablenum) {
        this.tablenum = tablenum;
    }


    public boolean hasParent() {
        return this.parent != null;
    }

    public void addSymbol(Symbol symbol) {
        this.symbols.add(symbol);
        this.findsymbol.put(symbol.getName(), symbol);
    }

    /* 检测出b类错误返回true，否则返回false */
    public boolean checkBTypeError(Symbol symbol) {
        if(this.findsymbol.containsKey(symbol.getName())){
            return true;
        }
        return false;
    }

    /* 检测出c类错误返回true，否则返回false */
    public boolean checkCTypeError(String name) {
        if(this.findsymbol.containsKey(name)){
            return false;
        }
        if (this.hasParent()) {
            return this.getParent().checkCTypeError(name);
        } else {
            return true;
        }
    }

    public Symbol getSymbol(String name) {
        if (this.findsymbol.containsKey(name)) {
            return this.findsymbol.get(name);
        }
        if (this.hasParent()) {
            return this.parent.getSymbol(name);
        }
        return null;
    }

    public Symbol getFunc(){
        return symbols.get(symbols.size()-1);
    }

    public ArrayList<Symbol> isFunc(){
        Symbol symbol = symbols.get(symbols.size()-1);
        if(symbol.getParas() != null &&symbol.getParas().size() != 0){
            return symbol.getParas();
        }
        return null;
    }

    public String printout(int linenum){
        String sb = "";
        for(int i = 0;i<symbols.size();i++){
            sb = sb + linenum + " " + symbols.get(i).getName()+" "+ symbols.get(i).Type()+"\n";
        }
        return sb;
    }
}
