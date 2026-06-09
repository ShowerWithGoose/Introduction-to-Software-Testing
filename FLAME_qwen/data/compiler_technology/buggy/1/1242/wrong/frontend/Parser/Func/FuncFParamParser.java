package frontend.Parser.Func;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;

import static frontend.Parser.Parser.StoreSyntax;

public class FuncFParamParser {
    private Category bType;

    private String ident;

    private boolean isArray;

    public FuncFParamParser() {
        isArray = false;
    }

    public Category GetBType() {
        return bType;
    }

    public String GetIdent() {
        return ident;
    }

    public boolean IsArray() {
        return isArray;
    }

    public boolean Parser() {
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.INTTK || token.GetCategory() == Category.CHARTK) {
            bType = token.GetCategory();
            token = TokenList.GetToken();
            if (token.GetCategory() == Category.IDENFR) {
                int store = TokenList.GetIndex();
                ident = token.GetContent();
                if (TokenList.NextIs(Category.LBRACK)) {
                    store = TokenList.GetIndex();
                    isArray = true;
                    if (!TokenList.NextIs(Category.RBRACK)) {
                        TokenList.SetIndex(store);
                        ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                    }
                    StoreSyntax("<FuncFParam>", TokenList.GetIndex() - 1);
                    //System.out.println("<FuncFParam>");
                    return true;
                }
                isArray = false;
                TokenList.SetIndex(store);
                StoreSyntax("<FuncFParam>",TokenList.GetIndex() - 1);
                //System.out.println("<FuncFParam>");
                return true;
            }
        }
        return false;
    }
}
