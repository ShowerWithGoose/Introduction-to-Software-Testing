package frontend.Parser.Func;

import frontend.Category.Category;
import frontend.Category.TokenList;
import frontend.Parser.Exp.ExpParser;
import frontend.symbol.RparamsType;

import java.util.ArrayList;

import static frontend.Parser.Parser.Exp;
import static frontend.Parser.Parser.StoreSyntax;

public class FuncRparamsParser {
    private int paramsNumber;

    private ArrayList<RparamsType> paramsType;

    public FuncRparamsParser() {
        paramsNumber = 0;
        paramsType = new ArrayList<>();
    }

    public int ParamsNumber() {
        return paramsNumber;
    }

    public ArrayList<RparamsType> GetParamsTypeList() {
        return paramsType;
    }

    public boolean Parser() {
        ExpParser expParser = new ExpParser();
        if (expParser.Parser()) {
            int store = TokenList.GetIndex();
            paramsNumber++;
            paramsType.add(expParser.GetRparamsType());
            while (TokenList.NextIs(Category.COMMA) && expParser.Parser()) {
                store = TokenList.GetIndex();
                paramsNumber++;
                paramsType.add(expParser.GetRparamsType());
            }
            TokenList.SetIndex(store);
            StoreSyntax("<FuncRParams>",TokenList.GetIndex() - 1);
            //System.out.println("<FuncRParams>");
            return true;
        }
        return false;
    }
}
