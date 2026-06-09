package fronened.Parser;

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
        sb.append(rParent.print());
        sb.append(block.print());
        sb.append("<MainFuncDef>\n");
        return sb.toString();
    }

    public static MainFuncDef parse(TokenIterator iterator) {
        Token Int = iterator.next();
        Token Main = iterator.next();
        Token lParent = iterator.next();
        Token rParent = iterator.next();
        Block block = Block.parse(iterator);
        return new MainFuncDef(Int, Main, lParent, rParent, block);
    }
}
