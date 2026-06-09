package frontend.Parser.Decl;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;

import static frontend.Parser.Parser.*;

public class VarDefParser {
    private String ident;

    private boolean isArray;

    public VarDefParser() {
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
            int store = TokenList.GetIndex();
            ident = token.GetContent(); ///
            /*防止读入一个错误的定义*/ // 有可能是函数
            if (TokenList.NextIs(Category.LPARENT)) {
                TokenList.SetIndex(store);
                return false;
            }
            TokenList.SetIndex(store);
            isArray = false;
            ////
            if (TokenList.NextIs(Category.LBRACK) && ConstExp()) {
                store = TokenList.GetIndex();
                isArray = true; ///
                if (TokenList.NextIs(Category.RBRACK)) {
                    store = TokenList.GetIndex();
                } else {
                    TokenList.SetIndex(store);
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'k'));
                }
                if (TokenList.NextIs(Category.ASSIGN) && InitVal()) {
                    StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
                    //System.out.println("<VarDef>");
                    return true;
                } else {
                    TokenList.SetIndex(store);
                    StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
                    //System.out.println("<VarDef>");
                    return true;
                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.ASSIGN) && InitVal()) {
                StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
                //System.out.println("<VarDef>");
                return true;
            }
            TokenList.SetIndex(store);
            StoreSyntax("<VarDef>",TokenList.GetIndex() - 1);
            //System.out.println("<VarDef>");
            return true;
        }
        return false;
    }
}
