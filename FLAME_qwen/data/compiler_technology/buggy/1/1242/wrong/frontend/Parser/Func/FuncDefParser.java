package frontend.Parser.Func;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.symbol.FuncSymbol;
import frontend.symbol.Symbol;
import frontend.symbol.SymbolTable;
import frontend.symbol.SymbolType;

import java.util.ArrayList;

import static frontend.Parser.Parser.*;

public class FuncDefParser {
    private Category funcType;

    private String ident;

    private int scope;

    private int line;

    private int paramScope;

    private int paramLine;

    private int paramsNumber;

    private ArrayList<SymbolType> symbolTypeList;

    private ArrayList<String> symbolNameList;

    public FuncDefParser() {
        paramsNumber = 0;
    }

    private void AddFuncSymbol() {
        if (funcType == Category.INTTK) {
            SymbolTable.AddSymbol(new FuncSymbol(scope,ident, SymbolType.IntFunc,line,paramsNumber,symbolTypeList));
        } else if (funcType == Category.CHARTK) {
            SymbolTable.AddSymbol(new FuncSymbol(scope,ident,SymbolType.CharFunc,line,paramsNumber,symbolTypeList));
        } else {
            SymbolTable.AddSymbol(new FuncSymbol(scope,ident,SymbolType.VoidFunc,line,paramsNumber,symbolTypeList));
        }
    }

    private void AddParamsSymbol() {
        for (int i = 0;i < paramsNumber;i++) {
            SymbolTable.AddSymbol(new Symbol(paramScope,symbolNameList.get(i),symbolTypeList.get(i),paramLine));
        }
    }

    public boolean Parser() {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.VOIDTK || token.GetCategory() == Category.INTTK || token.GetCategory() == Category.CHARTK) {
            funcType = token.GetCategory();
            token = TokenList.GetToken();
            if (token.GetCategory() == Category.IDENFR) {
                ident = token.GetContent();
                scope = TokenList.Scope();
                line = TokenList.ErrorLine();
                if (TokenList.NextIs(Category.LPARENT)) {
                    StoreSyntax("<FuncType>", TokenList.GetIndex() - 3);
                    int store = TokenList.GetIndex();
                    FuncFParamsParser funcFParamsParser = new FuncFParamsParser();
                    if (funcFParamsParser.Parser()) {
                        store = TokenList.GetIndex();
                        paramsNumber = funcFParamsParser.GetParamsNumber();
                        symbolTypeList = funcFParamsParser.GetSymbolTypeList();
                        symbolNameList = funcFParamsParser.GetSymbolNameList();
                        paramLine = TokenList.ErrorLine();
                    }
                    TokenList.SetIndex(store);
                    if (!TokenList.NextIs(Category.RPARENT)) {
                        TokenList.SetIndex(store);
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
                    }
                    paramScope = TokenList.ScopeByIndex(0);
                    AddFuncSymbol();
                    AddParamsSymbol();
                    BlockParser blockParser = new BlockParser();
                    if (blockParser.Parser()) {
                        if (funcType == Category.INTTK || funcType == Category.CHARTK) {
                            if (!blockParser.HaveReturn() || !blockParser.ReturnExp()) {
                                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'g'));
                            }
                        } else if (funcType == Category.VOIDTK) {
                            if (blockParser.ReturnExp()) {
                                ErrorMap.AddError(new Error(blockParser.returnline(),'f'));
                            }
                        }

                        StoreSyntax("<FuncDef>", TokenList.GetIndex() - 1);
                        //System.out.println("<FuncDef>");
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
