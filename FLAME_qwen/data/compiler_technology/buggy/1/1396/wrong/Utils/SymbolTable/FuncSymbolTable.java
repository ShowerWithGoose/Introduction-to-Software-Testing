package Utils.SymbolTable;

import java.util.*;

import Utils.Pair;
import Utils.Token;

public class FuncSymbolTable extends SymbolTable {
    public SymbolType returnType;
    public ArrayList<Pair<Token, SymbolType>> params = new ArrayList<>();

    public FuncSymbolTable(SymbolTable parent, SymbolType returnType) {
        super(parent);
        this.returnType = returnType;
    }

    public void addParam(Token token, SymbolType type) throws SymbolAlreadyExistsException {
        String name = (String)token.getValue();
        if (symbolNames.contains(name)) throw new SymbolAlreadyExistsException(name);
        addSymbol(token, type);
        params.add(new Pair<>(token, type));
    }
}