package frontend.parser.specificUnit;

import frontend.ErrorHandler.Error;
import frontend.ErrorHandler.ErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.Word;
import frontend.parser.ParseUnit;
import frontend.symbols.FuncSymbol;
import frontend.symbols.Symbol;
import frontend.symbols.SymbolTable;

import java.util.ArrayList;

public class UnaryExp extends ParseUnit {
    private PrimaryExp primaryExp;
    private Token ident;
    private FuncRParams funcRParams;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;
    private SymbolTable symbolTable;

    public UnaryExp(String name, ArrayList<ParseUnit> subUnits,
                    PrimaryExp primaryExp, Token ident, FuncRParams funcRParams,
                    UnaryOp unaryOp, UnaryExp unaryExp, SymbolTable symbolTable) {
        super(name, subUnits);
        this.primaryExp = primaryExp;
        this.ident = ident;
        this.funcRParams = funcRParams;
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
        this.symbolTable = symbolTable;
    }

    public Param getParam() {
        if (primaryExp != null) {
            return primaryExp.getParam();
        } else if (ident != null) {
            Symbol symbol = symbolTable.getSymbol(ident.getContext());
            Word returnType = ((FuncSymbol) symbol).getReturnType();
            return new Param(returnType, false);
        } else {
            return unaryExp.getParam();
        }
    }

    public void checkC(SymbolTable symbolTable) {
        if (ident != null) {
            if (symbolTable.getSymbol(ident.getContext()) == null) {
                ErrorHandler.getInstance().addError(new Error('c', ident.getLineNum()));
            }
        }
    }

    public void checkDE(SymbolTable symbolTable) {
        if (ident != null) {
            Symbol symbol = symbolTable.getSymbol(ident.getContext());
            if (symbol instanceof FuncSymbol) {
                ((FuncSymbol) symbol).checkParams(funcRParams, ident);
            }
        }
    }

}
