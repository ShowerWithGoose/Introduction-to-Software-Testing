package symbol;

import java.util.ArrayList;
import java.util.List;


public class FuncSym extends Symbol {
    private List<Symbol> args = new ArrayList<>();

    public FuncSym(String name, SymbolType type, int scope) {
        super(name, type, scope);
    }

    public List<Symbol> getArgs() {
        return args;
    }

    public void addArg(Symbol arg) {
        args.add(arg);
    }
}
