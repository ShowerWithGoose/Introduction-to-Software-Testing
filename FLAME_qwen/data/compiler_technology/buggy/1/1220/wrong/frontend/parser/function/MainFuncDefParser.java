package frontend.parser.function;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.block.Block;
import frontend.parser.block.BlockParser;

public class MainFuncDefParser {
    // MainFuncDef → 'int' 'main' '(' ')' Block
    private TokenIterator iterator;
    private Token intTk;
    private Token mainTk;
    private Token leftParent;
    private Token rightParent;
    private Block block;

    public MainFuncDefParser(TokenIterator iterator)  {
        this.iterator = iterator;
    }

    public MainFuncDef parseMainFuncDef() {
        //MainFuncDef → 'int' 'main' '(' ')' Block
        intTk = iterator.getNextToken();
        mainTk = iterator.getNextToken();
        leftParent = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() != TokenType.RPARENT) {
            rightParent = null;
            iterator.ungetToken(2);
            Token t2 = iterator.getNextToken();
            Error error = new Error(t2.getLineNum(), "j");
            ErrorList.addErrorList(error);
        } else {
            rightParent = t1;
        }
        BlockParser blockParser = new BlockParser(iterator);
        block = blockParser.parseBlock();

        return new MainFuncDef(intTk, mainTk, leftParent, rightParent, block);
    }
}
