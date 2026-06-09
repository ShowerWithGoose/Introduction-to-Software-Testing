package frontend.parser.specificUnit;

import frontend.ErrorHandler.Error;
import frontend.ErrorHandler.ErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.Word;
import frontend.parser.ParseUnit;
import frontend.symbols.Symbol;
import frontend.symbols.SymbolTable;
import frontend.symbols.VarSymbol;

import java.util.ArrayList;

public class LVal extends ParseUnit {
    private SymbolTable symbolTable;
    private Token ident;
    private Exp exp;

    public LVal(String name, ArrayList<ParseUnit> subUnits,
                Token ident, Exp exp, SymbolTable symbolTable) {
        super(name, subUnits);
        this.ident = ident;
        this.exp = exp;
        this.symbolTable = symbolTable;
    }

    public Token getIdent() {
        return ident;
    }

    public void checkC(SymbolTable symbolTable) {
        if (symbolTable.getSymbol(ident.getContext()) == null) {
            ErrorHandler.getInstance().addError(new Error('c', ident.getLineNum()));
        }
    }

    public Param getParam() {
        Symbol symbol = symbolTable.getSymbol(ident.getContext());
        Word returnType = ((VarSymbol) symbol).getType().getWord();
        boolean isExpNull = (exp == null);
        Boolean isArray = ((VarSymbol) symbol).isArray() && isExpNull;

        return new Param(returnType, isArray);
    }
}
