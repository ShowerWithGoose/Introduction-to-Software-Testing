package frontend.Parser.Func;

import frontend.Category.Category;
import frontend.Category.TokenList;

import static frontend.Parser.Parser.StoreSyntax;

public class BlockParser {
    private int scope;

    private boolean haveReturn;

    private boolean returnExp;

    private int returnLine;

    public BlockParser() {
        haveReturn = false;
        returnExp = false;
        returnLine = 0;
    }

    public int GetScope() {
        return scope;
    }

    public boolean HaveReturn() {
        return haveReturn;
    }

    public boolean ReturnExp() {
        return returnExp;
    }

    public int returnline() {
        return returnLine;
    }

    public boolean Parser() {
        if (TokenList.NextIs(Category.LBRACE)) {
            int store = TokenList.GetIndex();
            scope = TokenList.Scope();
            BlockItemParser blockItemParser = new BlockItemParser();
            while (blockItemParser.Parser()) {
                store = TokenList.GetIndex();
                if (blockItemParser.IsReturn()) {
                    haveReturn = true;
                    returnLine = blockItemParser.ReturnLine();
                    if (blockItemParser.ReturnExp()) {
                        returnExp = true;
                    }
                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.RBRACE)) {
                StoreSyntax("<Block>",TokenList.GetIndex() - 1);
                //System.out.println(TokenList.GetIndex() - 1 + " " + "<Block>");
                return true;
            }
        }
        return false;
    }
}
