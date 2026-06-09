package frontend.Parser.Exp;

import frontend.Category.Category;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.Parser.LValParser;
import frontend.symbol.RparamsType;

import static frontend.Parser.Parser.LVal;
import static frontend.Parser.Parser.StoreSyntax;
import static frontend.Parser.Parser.*;

public class PrimaryExpParser {
    private RparamsType rparamsType;

    public PrimaryExpParser() {
        rparamsType = RparamsType.VARIABLE;
    }

    public RparamsType GetRparamsType() {
        return rparamsType;
    }

    public boolean Parser() {
        int store = TokenList.GetIndex();
        if (TokenList.NextIs(Category.LPARENT) && Exp()) {
            store = TokenList.GetIndex();
            if (!TokenList.NextIs(Category.RPARENT)) {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
            }
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        LValParser lValParser = new LValParser();
        if (lValParser.Parser(true)) { // 安全用法
            rparamsType = lValParser.GetRparamsType();
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (Number()) {
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (Character()) {
            StoreSyntax("<PrimaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<PrimaryExp>");
            return true;
        }
        return false;
    }
}
