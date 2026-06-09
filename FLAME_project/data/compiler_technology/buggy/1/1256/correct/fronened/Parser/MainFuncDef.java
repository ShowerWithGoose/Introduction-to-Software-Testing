package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class MainFuncDef {
    private Token Int;
    private Token Main;
    private Token lParent;
    private Token rParent;
    private Block block;

    public MainFuncDef(Token anInt, Token main, Token lParent, Token rParent, Block block) {
        Int = anInt;
        Main = main;
        this.lParent = lParent;
        this.rParent = rParent;
        this.block = block;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(Int.print());
        sb.append(Main.print());
        sb.append(lParent.print());
        if (rParent != null) {
            sb.append(rParent.print());
        }
        sb.append(block.print());
        sb.append("<MainFuncDef>\n");
        return sb.toString();
    }

    public static MainFuncDef parse(TokenIterator iterator) {
        Token Int = iterator.next();
        Token Main = iterator.next();
        Token lParent = iterator.next();
        Token token = iterator.next();
        Token rParent = null;
        if (token.getType().equals(Token.Type.RPARENT)) {
            rParent = token;
        } else {
            iterator.back();
            Error error = new Error(iterator.now_line(), 'j');
            ErrorList.addError(error);
        }
        Block block = Block.parse(iterator);
        return new MainFuncDef(Int, Main, lParent, rParent, block);
    }
}
