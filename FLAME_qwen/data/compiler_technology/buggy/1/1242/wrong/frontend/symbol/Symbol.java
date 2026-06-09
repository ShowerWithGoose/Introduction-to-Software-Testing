package frontend.symbol;

public class Symbol {
    private final int scope;
    private final String name;
    private final SymbolType type;

    private  int line;

    public Symbol(int scope,String name,SymbolType type,int line){
        this.scope = scope;
        this.name = name;
        this.type = type;
        this.line = line;
    }

    public final int GetScope() {
        return scope;
    }

    public final String GetName() {
        return name;
    }

    public final SymbolType GetType() {
        return type;
    }

    public void SetLine(int line) {
        this.line = line;
    }

    public  int GetLine() {
        return line;
    }

    @Override
    public String toString() {
        return scope + " " + name + " " + type.name();
    }

    public static class Main {
        public static void main(String args[]) {
            Symbol symbol = new Symbol(1,"a",SymbolType.Char,1);
            System.out.println(symbol);
        }
    }
}
