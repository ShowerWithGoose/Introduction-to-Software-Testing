package frontend.Parser.Decl;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.symbol.Symbol;
import frontend.symbol.SymbolTable;
import frontend.symbol.SymbolType;

import static frontend.Parser.Parser.StoreSyntax;

public class VarDeclParser {

    private Category bType;

    public VarDeclParser() {

    }
    private void AddSymbol(boolean isArray,String ident,int line) {
        if (bType == Category.INTTK) {
            if (isArray) {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.IntArray,line));
            } else {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.Int,line));
            }
        } else {
            if (isArray) {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.CharArray,line));
            } else {
                SymbolTable.AddSymbol(new Symbol(TokenList.Scope(), ident, SymbolType.Char,line));
            }
        }
    }
    public boolean Parser() {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.CHARTK || token.GetCategory() == Category.INTTK) {
            bType = token.GetCategory();
            VarDefParser varDefParser = new VarDefParser();
            if (varDefParser.Parser()) {
                int store = TokenList.GetIndex();
                AddSymbol(varDefParser.IsArray(), varDefParser.GetIdent(),TokenList.ErrorLine());
                while (TokenList.NextIs(Category.COMMA) && varDefParser.Parser()) {
                    store = TokenList.GetIndex();
                    AddSymbol(varDefParser.IsArray(), varDefParser.GetIdent(),TokenList.ErrorLine());
                }
                TokenList.SetIndex(store);
                if (!TokenList.NextIs(Category.SEMICN)) {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(), 'i'));
                }
                StoreSyntax("<VarDecl>",TokenList.GetIndex() - 1);
                //System.out.println("<ConstDecl>");
                return true;
            }
        }
        return false;
    }
}
