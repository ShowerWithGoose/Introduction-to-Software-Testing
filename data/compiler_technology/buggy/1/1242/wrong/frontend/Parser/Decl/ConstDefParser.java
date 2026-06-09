package frontend.Parser.Decl;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;

import static frontend.Parser.Parser.*;

public class ConstDefParser {
    private String ident;

    private boolean isArray;

    public ConstDefParser() {
        isArray = false;
    }

    public String GetIdent() {
        return ident;
    }

    public boolean IsArray() {
        return isArray;
    }

    public boolean Parser() {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.IDENFR) {
            ident = token.GetContent(); ///
            int store = TokenList.GetIndex();
            isArray = false;
            if (TokenList.NextIs(Category.LBRACK) && ConstExp()) {
                isArray = true; ///
                store = TokenList.GetIndex();
                if (TokenList.NextIs(Category.RBRACK)) {
                    store = TokenList.GetIndex();
                } else {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.ASSIGN) && ConstInitVal()) {
                StoreSyntax("<ConstDef>",TokenList.GetIndex() - 1);
                //System.out.println("<ConstDef>");
                return true;
            }
        }
        return false;
    }
}
