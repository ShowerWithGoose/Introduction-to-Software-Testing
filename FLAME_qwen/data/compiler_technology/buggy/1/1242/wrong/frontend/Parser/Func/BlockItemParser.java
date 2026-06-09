package frontend.Parser.Func;

import frontend.Category.TokenList;

import static frontend.Parser.Parser.Decl;

public class BlockItemParser {
    private boolean isReturn;

    private boolean returnExp;

    private int returnLine;

    public BlockItemParser() {
        isReturn = false;
        returnExp = false;
        returnLine = 0;
    }

    public boolean IsReturn() {
        return isReturn;
    }

    public boolean ReturnExp() {
        return returnExp;
    }

    public int ReturnLine() {
        return returnLine;
    }

    public boolean Parser() {
        int store = TokenList.GetIndex();
        if (Decl()) {
            //StoreSyntax("<BlockItem>",TokenList.GetIndex() - 1);
            //System.out.println("<BlockItem>");
            return true;
        } else {
            TokenList.SetIndex(store);
            StmtParser stmtParser = new StmtParser();
            if (stmtParser.Parser()) {
                isReturn = stmtParser.IsReturn();
                returnExp = stmtParser.ReturnExp();
                returnLine = stmtParser.ReturnLine();
                //StoreSyntax("<BlockItem>",TokenList.GetIndex() - 1);
                //System.out.println("<BlockItem>");
                return true;
            }
        }
        return false;
    }
}
