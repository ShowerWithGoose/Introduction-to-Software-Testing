package frontend;

import java.lang.Character;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

public class Semantic {
    private int scope = 1;
    private int scopes_num = 1;
    private ArrayList<Integer> scope_stack = new ArrayList<>();
    private ArrayList<SymbolTable> symbolTables;
    private ArrayList<Symbol> symbols = new ArrayList<>();
    private int isCan = 0;
    private String curBType;
    private String curFuncBType;
    private HashMap<Integer, Character> error;
    private int if_in_for = 0;

    public Semantic() {
        this.symbolTables = new ArrayList<>();
        this.symbolTables.add(new SymbolTable(null));
        scope_stack.add(1);
        this.error = new HashMap<>();
    }

    public ArrayList<Symbol> getSymbols() {
        return symbols;
    }

    public HashMap<Integer, Character> getError() {
        return error;
    }

    public void analyze(Token token) {

        if (token instanceof Block) {
            if (isCan == 0) {
                int fore_scope = scope;
                scope = ++scopes_num;
                scope_stack.add(scope);
                symbolTables.add(new SymbolTable(symbolTables.get(fore_scope - 1)));
            } else {
                isCan = 0;
            }
            for (int i = 0; i < token.getSons().size(); i++) {
                analyze(token.getSons().get(i));
            }
            scope_stack.remove(scope_stack.size() - 1);
            scope = scope_stack.get(scope_stack.size() - 1);

        } else if (token instanceof Stmt && token.getSon(0) instanceof Terminal terminal && Objects.equals(terminal.getToken(), "for")) {
            if_in_for++;
            for (int i = 0; i < token.getSons().size(); i++) {
                analyze(token.getSon(i));
            }
            if_in_for--;
        } else {
            if (token instanceof ConstDecl) {
                curBType = ((Terminal) token.getSon(1).getSon(0)).getToken();
            } else if (token instanceof VarDecl) {
                curBType = ((Terminal) token.getSon(0).getSon(0)).getToken();
            } else if (token instanceof ConstDef) {
                int if_declined = 0;
                String name = ((Terminal) token.getSon(0)).getToken();
                SymbolTable symbolTable1 = symbolTables.get(scope - 1);
                for (String key : symbolTable1.getItems().keySet()) {
                    if (Objects.equals(name, key)) {
                        error.put(((Terminal) token.getSon(0)).getLine(), 'b');
                        if_declined = 1;
                        break;
                    }
                }
                if (if_declined == 0) {
                    int dimension = 0;
                    SymbolTable symbolTable = symbolTables.get(scope - 1);
                    Symbol symbol;
                    if (Objects.equals(((Terminal) token.getSon(1)).getToken(), "[")) {
                        dimension = 1;
                        if (Objects.equals(curBType, "int")) {
                            symbol = new Symbol(name, "ConstIntArray", scope, dimension);
                        } else {
                            symbol = new Symbol(name, "ConstCharArray", scope, dimension);
                        }
                    } else {
                        if (Objects.equals(curBType, "int")) {
                            symbol = new Symbol(name, "ConstInt", scope, dimension);
                        } else {
                            symbol = new Symbol(name, "ConstChar", scope, dimension);
                        }
                    }
                    symbolTable.addItem(name, symbol);
                    symbols.add(symbol);
                }

            } else if (token instanceof VarDef) {
                int if_declined = 0;
                String name = ((Terminal) token.getSon(0)).getToken();
                SymbolTable symbolTable1 = symbolTables.get(scope - 1);
                for (String key : symbolTable1.getItems().keySet()) {
                    if (Objects.equals(name, key)) {
                        error.put(((Terminal) token.getSon(0)).getLine(), 'b');
                        if_declined = 1;
                        break;
                    }
                }
                if (if_declined == 0) {
                    int dimension = 0;
                    SymbolTable symbolTable = symbolTables.get(scope - 1);
                    Symbol symbol;
                    if (token.getSons().size() == 1) {
                        if (Objects.equals(curBType, "int")) {
                            symbol = new Symbol(name, "Int", scope, dimension);
                        } else {
                            symbol = new Symbol(name, "Char", scope, dimension);
                        }
                    } else {
                        if (Objects.equals(((Terminal) token.getSon(1)).getToken(), "[")) {
                            dimension = 1;
                            if (Objects.equals(curBType, "int")) {
                                symbol = new Symbol(name, "IntArray", scope, dimension);
                            } else {
                                symbol = new Symbol(name, "CharArray", scope, dimension);
                            }
                        } else {
                            if (Objects.equals(curBType, "int")) {
                                symbol = new Symbol(name, "Int", scope, dimension);
                            } else {
                                symbol = new Symbol(name, "Char", scope, dimension);
                            }
                        }
                    }
                    symbolTable.addItem(name, symbol);
                    symbols.add(symbol);
                }

            } else if (token instanceof FuncDef) {
                curFuncBType = ((Terminal) token.getSon(0).getSon(0)).getToken();
                int if_declined = 0;
                String name = ((Terminal) token.getSon(1)).getToken();
                SymbolTable symbolTable1 = symbolTables.get(scope - 1);
                for (String key : symbolTable1.getItems().keySet()) {
                    if (Objects.equals(name, key)) {
                        error.put(((Terminal) token.getSon(1)).getLine(), 'b');
                        if_declined = 1;
                        break;
                    }
                }
                if (if_declined == 0) {
                    Symbol_FuncFParams symbol_funcFParams = new Symbol_FuncFParams();
                    if (token.getSon(3) instanceof FuncFParams) {
                        Token funcFParams = token.getSon(3);
                        for (int i = 0; i < funcFParams.getSons().size(); i++) {
                            if (funcFParams.getSon(i) instanceof FuncFParam) {
                                if (Objects.equals(((Terminal) funcFParams.getSon(i).getSon(0).getSon(0)).getToken(), "int")) {
                                    if (funcFParams.getSon(i).getSons().size() == 2) {
                                        symbol_funcFParams.addParamType("Int");
                                    } else {
                                        symbol_funcFParams.addParamType("IntArray");
                                    }
                                } else {
                                    if (funcFParams.getSon(i).getSons().size() == 2) {
                                        symbol_funcFParams.addParamType("Char");
                                    } else {
                                        symbol_funcFParams.addParamType("CharArray");
                                    }
                                }
                            }
                        }
                    }
                    if (Objects.equals(curFuncBType, "void")) {
                        SymbolTable symbolTable = symbolTables.get(scope - 1);
                        Symbol symbol = new Symbol(name, "VoidFunc", scope, 0);
                        symbol.setSymbol_funcFParams(symbol_funcFParams);
                        symbolTable.addItem(name, symbol);
                        symbols.add(symbol);
                    } else if (Objects.equals(curFuncBType, "int")) {
                        SymbolTable symbolTable = symbolTables.get(scope - 1);
                        Symbol symbol = new Symbol(name, "IntFunc", scope, 0);
                        symbol.setSymbol_funcFParams(symbol_funcFParams);
                        symbolTable.addItem(name, symbol);
                        symbols.add(symbol);
                    } else {
                        SymbolTable symbolTable = symbolTables.get(scope - 1);
                        Symbol symbol = new Symbol(name, "CharFunc", scope, 0);
                        symbol.setSymbol_funcFParams(symbol_funcFParams);
                        symbolTable.addItem(name, symbol);
                        symbols.add(symbol);
                    }
                }

                Token block = token.getSon(token.getSons().size() - 1);
                if (Objects.equals(curFuncBType, "char") || Objects.equals(curFuncBType, "int")) {
                    int p = 0;
                    if (block.getSons().size() > 2) {
                        if (block.getSon(block.getSons().size() - 2).getSon(0) instanceof Stmt) {
                            if (block.getSon(block.getSons().size() - 2).getSon(0).getSon(0) instanceof Terminal terminal) {
                                if (Objects.equals(terminal.getToken(), "return")) {
                                    p = 1;
                                }
                            }
                        }
                    }
                    if (p == 0) {
                        error.put(((Terminal) block.getSon(block.getSons().size() - 1)).getLine(), 'g');
                    }
                }

            } else if (token instanceof FuncFParam) {
                if (isCan == 0) {
                    int fore_scope = scope;
                    scope = ++scopes_num;
                    scope_stack.add(scope);
                    symbolTables.add(new SymbolTable(symbolTables.get(fore_scope - 1)));
                    isCan = 1;
                }

                String name = ((Terminal) token.getSon(1)).getToken();

                int if_declined = 0;
                SymbolTable symbolTable1 = symbolTables.get(scope - 1);
                for (String key : symbolTable1.getItems().keySet()) {
                    if (Objects.equals(name, key)) {
                        error.put(((Terminal) token.getSon(1)).getLine(), 'b');
                        if_declined = 1;
                        break;
                    }
                }

                if (if_declined == 0) {
                    if (Objects.equals(((Terminal) token.getSon(0).getSon(0)).getToken(), "int")) {
                        if (token.getSons().size() == 2) {
                            SymbolTable symbolTable = symbolTables.get(scope - 1);
                            Symbol symbol = new Symbol(name, "Int", scope, 0);
                            symbolTable.addItem(name, symbol);
                            symbols.add(symbol);
                        } else {
                            SymbolTable symbolTable = symbolTables.get(scope - 1);
                            Symbol symbol = new Symbol(name, "IntArray", scope, 0);
                            symbolTable.addItem(name, symbol);
                            symbols.add(symbol);
                        }
                    } else {
                        if (token.getSons().size() == 2) {
                            SymbolTable symbolTable = symbolTables.get(scope - 1);
                            Symbol symbol = new Symbol(name, "Char", scope, 0);
                            symbolTable.addItem(name, symbol);
                            symbols.add(symbol);
                        } else {
                            SymbolTable symbolTable = symbolTables.get(scope - 1);
                            Symbol symbol = new Symbol(name, "CharArray", scope, 0);
                            symbolTable.addItem(name, symbol);
                            symbols.add(symbol);
                        }
                    }
                }

            } else if (token instanceof LVal) {
                String name = ((Terminal) token.getSon(0)).getToken();
                SymbolTable symbolTable = symbolTables.get(scope - 1);
                int p = 0;
                while (symbolTable != null) {
                    for (String key : symbolTable.getItems().keySet()) {
                        if (Objects.equals(key, name)) {
                            p = 1;
                            break;
                        }
                    }
                    symbolTable = symbolTable.getFore_table();
                }
                if (p == 0) {
                    error.put(((Terminal) token.getSon(0)).getLine(), 'c');
                }

            } else if (token instanceof UnaryExp) {
                if (token.getSon(0) instanceof Terminal) {
                    String name = ((Terminal) token.getSon(0)).getToken();
                    SymbolTable symbolTable = symbolTables.get(scope - 1);
                    int p = 0;
                    while (symbolTable != null) {
                        for (String key : symbolTable.getItems().keySet()) {
                            if (Objects.equals(key, name)) {
                                p = 1;
                                break;
                            }
                        }
                        symbolTable = symbolTable.getFore_table();
                    }
                    if (p == 0) {
                        error.put(((Terminal) token.getSon(0)).getLine(), 'c');
                    } else {
                        String funcName = ((Terminal) token.getSon(0)).getToken();
                        Symbol_FuncFParams symbol_funcFParams = null;
                        SymbolTable st1 = symbolTables.get(0);
                        for (String key : st1.getItems().keySet()) {
                            if (Objects.equals(funcName, key)) {
                                symbol_funcFParams = st1.getItems().get(key).getSymbol_funcFParams();
                                break;
                            }
                        }
                        int size = symbol_funcFParams.getParamTypes().size();
                        if (token.getSons().size() == 2) {
                            if (size != 0) {
                                error.put(((Terminal) token.getSon(0)).getLine(), 'd');
                            }
                        } else if (token.getSons().size() >= 3) {
                            if (token.getSon(2) instanceof Terminal) {
                                if (size != 0) {
                                    error.put(((Terminal) token.getSon(0)).getLine(), 'd');
                                }
                            } else if (token.getSon(2) instanceof FuncRParams funcRParams) {
                                int size1 = (funcRParams.getSons().size() + 1) / 2;
                                if (size1 != size) {
                                    error.put(((Terminal) token.getSon(0)).getLine(), 'd');
                                } else {
                                    for (int i = 0; i < funcRParams.getSons().size(); i = i + 2) {
                                        if (Objects.equals(symbol_funcFParams.getParamTypes().get(i / 2), "Char")
                                                || Objects.equals(symbol_funcFParams.getParamTypes().get(i / 2), "Int")) {
                                            if (!Objects.equals(which_type((Exp) funcRParams.getSon(i)), "Int")) {
                                                error.put(((Terminal) token.getSon(0)).getLine(), 'e');
                                                break;
                                            }
                                        } else if (Objects.equals(symbol_funcFParams.getParamTypes().get(i / 2), "CharArray")) {
                                            if (!Objects.equals(which_type((Exp) funcRParams.getSon(i)), "CharArray")) {
                                                error.put(((Terminal) token.getSon(0)).getLine(), 'e');
                                                break;
                                            }
                                        } else if (Objects.equals(symbol_funcFParams.getParamTypes().get(i / 2), "IntArray")) {
                                            if (!Objects.equals(which_type((Exp) funcRParams.getSon(i)), "IntArray")) {
                                                error.put(((Terminal) token.getSon(0)).getLine(), 'e');
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            } else if (token instanceof Stmt) {
                if (Objects.equals(curFuncBType, "void")) {
                    if (token.getSon(0) instanceof Terminal terminal) {
                        if (Objects.equals(terminal.getToken(), "return")) {
                            if (token.getSons().size() >= 2) {
                                if (token.getSon(1) instanceof Exp) {
                                    error.put(terminal.getLine(), 'f');
                                }
                            }
                        }
                    }
                }
                if (token.getSon(0) instanceof LVal lVal) {
                    String name = ((Terminal) lVal.getSon(0)).getToken();
                    String type = "";
                    SymbolTable symbolTable = symbolTables.get(scope - 1);
                    int r = 0;
                    while (symbolTable != null) {
                        for (String key : symbolTable.getItems().keySet()) {
                            if (Objects.equals(name, key)) {
                                type = symbolTable.getItems().get(key).getType();
                                r = 1;
                                break;
                            }
                        }
                        if (r == 1) {
                            break;
                        }
                        symbolTable = symbolTable.getFore_table();
                    }
                    if (Objects.equals(type, "ConstChar") || Objects.equals(type, "ConstCharArray")
                            || Objects.equals(type, "ConstInt") || Objects.equals(type, "ConstIntArray")) {
                        error.put(((Terminal) lVal.getSon(0)).getLine(), 'h');
                    }
                }
                if (token.getSon(0) instanceof Terminal terminal) {
                    if (Objects.equals(terminal.getToken(), "printf")) {
                        String s = ((Terminal) token.getSon(2)).getToken();
                        int num = 0;
                        for (int i = 0; i < s.length() - 1; i++) {
                            if ((s.charAt(i) == '%' && s.charAt(i + 1) == 'd') || (s.charAt(i) == '%' && s.charAt(i + 1) == 'c')) {
                                num++;
                            }
                        }
                        int real_num = 0;
                        for (int i = 0; i < token.getSons().size(); i++) {
                            if (token.getSon(i) instanceof Exp) {
                                real_num++;
                            }
                        }
                        if (real_num != num) {
                            error.put(((Terminal) token.getSon(0)).getLine(), 'l');
                        }
                    }
                }
                if (token.getSon(0) instanceof Terminal terminal) {
                    if (Objects.equals(terminal.getToken(), "break") || Objects.equals(terminal.getToken(), "continue")) {
                        if (if_in_for == 0) {
                            error.put(terminal.getLine(), 'm');
                        }
                    }
                }

            } else if (token instanceof ForStmt) {
                if (token.getSon(0) instanceof LVal lVal) {
                    String name = ((Terminal) lVal.getSon(0)).getToken();
                    String type = "";
                    SymbolTable symbolTable = symbolTables.get(scope - 1);
                    int r = 0;
                    while (symbolTable != null) {
                        for (String key : symbolTable.getItems().keySet()) {
                            if (Objects.equals(name, key)) {
                                type = symbolTable.getItems().get(key).getType();
                                r = 1;
                                break;
                            }
                        }
                        if (r == 1) {
                            break;
                        }
                        symbolTable = symbolTable.getFore_table();
                    }
                    if (Objects.equals(type, "ConstChar") || Objects.equals(type, "ConstCharArray")
                            || Objects.equals(type, "ConstInt") || Objects.equals(type, "ConstIntArray")) {
                        error.put(((Terminal) lVal.getSon(0)).getLine(), 'h');
                    }
                }
            } else if (token instanceof MainFuncDef) {
                curFuncBType = "int";
                Token block = token.getSon(token.getSons().size() - 1);
                int p = 0;
                if (block.getSons().size() > 2) {
                    if (block.getSon(block.getSons().size() - 2).getSon(0) instanceof Stmt) {
                        if (block.getSon(block.getSons().size() - 2).getSon(0).getSon(0) instanceof Terminal terminal) {
                            if (Objects.equals(terminal.getToken(), "return")) {
                                p = 1;
                            }
                        }
                    }
                }
                if (p == 0) {
                    error.put(((Terminal) block.getSon(block.getSons().size() - 1)).getLine(), 'g');
                }
            }

            if (!(token instanceof Terminal)) {
                for (int i = 0; i < token.getSons().size(); i++) {
                    analyze(token.getSons().get(i));
                }
            }

        }

    }

    public String which_type(Exp exp) {
        SymbolTable symbolTable = symbolTables.get(scope - 1);
        String type = "Int";
        Token addExp = exp.getSon(0);
        if (addExp.getSons().size() == 1) {
            Token mulExp = addExp.getSon(0);
            if (mulExp.getSons().size() == 1) {
                Token unaryExp = mulExp.getSon(0);
                if (unaryExp.getSons().size() == 1) {
                    Token primaryExp = unaryExp.getSon(0);
                    if (primaryExp.getSon(0) instanceof LVal lVal) {
                        if (lVal.getSons().size() == 1) {
                            if (lVal.getSon(0) instanceof Terminal terminal) {
                                String name = terminal.getToken();
                                int r = 0;
                                while (symbolTable != null) {
                                    for (String key : symbolTable.getItems().keySet()) {
                                        if (Objects.equals(name, key)) {
                                            type = symbolTable.getItems().get(name).getType();
                                            r = 1;
                                            break;
                                        }
                                    }
                                    if (r == 1) {
                                        break;
                                    }
                                    symbolTable = symbolTable.getFore_table();
                                }
                                if (Objects.equals(type, "ConstIntArray") || Objects.equals(type, "IntArray")) {
                                    type = "IntArray";
                                } else if (Objects.equals(type, "ConstCharArray") || Objects.equals(type, "CharArray")) {
                                    type = "CharArray";
                                } else if (Objects.equals(type, "ConstChar") || Objects.equals(type, "Char")) {
                                    type = "Int";
                                } else if (Objects.equals(type, "ConstInt")) {
                                    type = "Int";
                                }
                            }
                        }
                    }
                }
            }
        }
        return type;
    }

}
