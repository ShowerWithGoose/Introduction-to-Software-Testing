package frontend.Parser.Exp;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.symbol.RparamsType;

import static frontend.Parser.Parser.StoreSyntax;

public class MulExpParser {
    private RparamsType rparamsType;

    public MulExpParser() {
        rparamsType = RparamsType.VARIABLE;
    }

    public RparamsType GetRparamsType() {
        return rparamsType;
    }

    public boolean Parser() {
        UnaryExpParser unaryExpParser = new UnaryExpParser();
        if (unaryExpParser.Parser()) {
            int store = TokenList.GetIndex();
            rparamsType = unaryExpParser.GetRparamsType();
            Token token = TokenList.GetToken();
            while (token.GetCategory() == Category.MULT ||
                    token.GetCategory() == Category.DIV ||
                    token.GetCategory() == Category.MOD) {
                if (unaryExpParser.Parser()) {
                    rparamsType = RparamsType.VARIABLE;
                    StoreSyntax("<MulExp>",store - 1);
                    store = TokenList.GetIndex();
                    token = TokenList.GetToken();
                }
            }
            TokenList.SetIndex(store);
            StoreSyntax("<MulExp>",TokenList.GetIndex() - 1);
            //System.out.println("<MulExp>");
            return true;
        }
        return false;
    }
}
