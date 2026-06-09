package frontend.Parser.Decl;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.symbol.Symbol;
import frontend.symbol.SymbolTable;
import frontend.symbol.SymbolType;

import static frontend.Parser.Parser.*;

public class ConstDeclParser {
    private Category bType;

    public ConstDeclParser() {

    }

    private void AddSymbol(boolean isArray,String ident,int line) {
        if (bType == Category.INTTK) {
            if (isArray) {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.ConstIntArray,line));
            } else {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.ConstInt,line));
            }
        } else {
            if (isArray) {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.ConstCharArray,line));
            } else {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.ConstChar,line));
            }
        }
    }
    public boolean Parser() {
        if (TokenList.NextIs(Category.CONSTTK)) {
            Token token = TokenList.GetToken();
            if (token.GetCategory() == Category.CHARTK || token.GetCategory() == Category.INTTK) {
                bType = token.GetCategory();
                ConstDefParser constDefParser = new ConstDefParser();
                if (constDefParser.Parser()) {
                    int store = TokenList.GetIndex();
                    AddSymbol(constDefParser.IsArray(), constDefParser.GetIdent(),TokenList.ErrorLine());
                    while (TokenList.NextIs(Category.COMMA) && constDefParser.Parser()) {
                        store = TokenList.GetIndex();
                        AddSymbol(constDefParser.IsArray(), constDefParser.GetIdent(),TokenList.ErrorLine());
                    }
                    TokenList.SetIndex(store);
                    if (!TokenList.NextIs(Category.SEMICN)) {
                        TokenList.SetIndex(store);
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(), 'i'));
                    }
                    StoreSyntax("<ConstDecl>",TokenList.GetIndex() - 1);
                    //System.out.println("<ConstDecl>");
                    return true;
                }
            }
        }
        return false;
    }
}
