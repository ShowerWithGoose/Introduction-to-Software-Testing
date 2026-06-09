package Sym;

import Lexer.Token;

import IO.*;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.LinkedHashMap;

public class Symbols {
    private LinkedHashMap<String, Symbol> symbolHashMap;


    IO io;

    public Symbols(IO io) {
        symbolHashMap = new LinkedHashMap<>();
        this.io = io;
    }

    public boolean isDeclared(Token id) {
        if (symbolHashMap.get(id.getToken()) == null) {
            return false;
        }
        return symbolHashMap.containsKey(id.getToken());
    }

    public void addSymbol(Token type, Token id, boolean isConst, boolean isArray, boolean isFunc, Integer scopeId) {
        Symbol symbol = new Symbol(type, id, isConst, isArray, isFunc, scopeId);

        symbolHashMap.put(id.getToken(), symbol);
    }

    public Symbol getSymbol(Token token) {
        return symbolHashMap.get(token.getToken());
    }

    public void printAllSymbols()  {
        for (Symbol symbol : symbolHashMap.values()) {
            BufferedWriter bw = io.getSymbolWriter();
            try {
                bw.write(symbol.toString());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }


}
