package frontend.Parser;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.symbol.RparamsType;
import frontend.symbol.SymbolTable;
import frontend.symbol.SymbolType;

import static frontend.Parser.Parser.Exp;
import static frontend.Parser.Parser.StoreSyntax;

public class LValParser {
    private String ident;

    private RparamsType rparamsType;

    private boolean cError;

    private boolean kError;

    public LValParser() {
        rparamsType = RparamsType.VARIABLE;
        cError = true;
        kError = false;
    }

    public String GetIdent() {
        return ident;
    }

    public RparamsType GetRparamsType() {
        return rparamsType;
    }

    public boolean CError() {
        return cError;
    }

    public boolean KError() {
        return kError;
    }

    public void DefineRparamsType(SymbolType symbolType) {
        if (symbolType == SymbolType.Int || symbolType == SymbolType.Char || symbolType == SymbolType.ConstInt || symbolType == SymbolType.ConstChar) {
            rparamsType = RparamsType.VARIABLE;
        } else if (symbolType == SymbolType.IntArray || symbolType == SymbolType.ConstIntArray) {
            rparamsType = RparamsType.INTARRAY;
        } else if (symbolType == SymbolType.CharArray || symbolType == SymbolType.ConstCharArray) {
            rparamsType = RparamsType.CHARARRAY;
        } else {
            rparamsType = RparamsType.VARIABLE;
        }
    }

    public boolean Parser(boolean write) {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.IDENFR) {
            ident = token.GetContent();
            int store = TokenList.GetIndex();
            int scope = TokenList.Scope();
            while (scope!= 0) {
                if (SymbolTable.HaveDefine(scope,ident)) {
                    cError = false;
                    break;
                }
                scope = TokenList.ScopeFather(scope);
            }
            if (!cError) {
                DefineRparamsType(SymbolTable.Type(scope,ident));
            }
            if (TokenList.NextIs(Category.LBRACK) && Exp()) { //
                store = TokenList.GetIndex();
                if (!TokenList.NextIs(Category.RBRACK)) {
                    TokenList.SetIndex(store);
                    kError = true;
                }
                if (write) {
                    if (cError) {
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
                    }
                    if (kError) {
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                    }
                    StoreSyntax("<LVal>", TokenList.GetIndex() - 1);
                    //System.out.println("<LVal>");
                }
                return true;
            }
            TokenList.SetIndex(store);
            if (write) {
                if (cError) {
                    System.out.println("this");
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
                }
                StoreSyntax("<LVal>", TokenList.GetIndex() - 1);
                //System.out.println("<LVal>");
            }
            return true;
        }
        return false;
    }
}
