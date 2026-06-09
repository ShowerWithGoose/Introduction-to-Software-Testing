package symbol;

import java.util.HashMap;
import java.util.Map;

public class FuncSym extends Symbol {
    private Map<String, Symbol> args = new HashMap<>();

    public FuncSym(String name, SymbolType type, int scope) {
        super(name, type, scope);
    }

    public Map<String, Symbol> getArgs() {
        return args;
    }

    public boolean isExist(String name) {
        return args.containsKey(name);
    }

    public void addArg(Symbol arg) {
        args.put(arg.getName(), arg);
    }
}
