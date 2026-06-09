package frontend.Parser.Exp;

import frontend.Category.TokenList;
import frontend.symbol.RparamsType;

import static frontend.Parser.Parser.StoreSyntax;

public class ExpParser {
    private RparamsType rparamsType;

    public ExpParser() {
        rparamsType = RparamsType.VARIABLE;
    }

    public RparamsType GetRparamsType() {
        return rparamsType;
    }

    public boolean Parser() {
        AddExpParser addExpParser = new AddExpParser();
        if (addExpParser.Parser()) {
            rparamsType = addExpParser.GetRparamsType();
            StoreSyntax("<Exp>", TokenList.GetIndex() - 1);
            //System.out.println("<Exp>");
            return true;
        }
        return false;
    }
}
