package frontend.Parser.Exp;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.symbol.RparamsType;

import static frontend.Parser.Parser.StoreSyntax;

public class AddExpParser {
    private RparamsType rparamsType;

    public AddExpParser() {
        rparamsType = RparamsType.VARIABLE;
    }

    public RparamsType GetRparamsType() {
        return rparamsType;
    }

    public boolean Parser() {
        MulExpParser mulExpParser = new MulExpParser();
        if (mulExpParser.Parser()) {
            int store = TokenList.GetIndex();
            rparamsType = mulExpParser.GetRparamsType();
            Token token = TokenList.GetToken();
            while (token.GetCategory() == Category.PLUS ||
                    token.GetCategory() == Category.MINU) {
                if (mulExpParser.Parser()) {
                    rparamsType = RparamsType.VARIABLE;
                    StoreSyntax("<AddExp>",store - 1);
                    store = TokenList.GetIndex();
                    token = TokenList.GetToken();
                }
            }
            TokenList.SetIndex(store);
            StoreSyntax("<AddExp>",TokenList.GetIndex() - 1);
            //System.out.println("<AddExp>");
            return true;
        }
        return false;
    }
}
