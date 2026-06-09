package parser_part.function;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.block.Block;
import parser_part.block.BlockItem;
import parser_part.block.BlockParser;
import symbol_part.SymbolList;

public class MainFuncDefParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public MainFuncDefParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public MainFuncDef parseMainFuncDef() {
        Token intToken = tokenList.getNextToken();
        Token mainToken = tokenList.getNextToken();
        Token leftParent = tokenList.getNextToken();
        Token rightParent = tokenList.getNextToken();
        if (rightParent.getType() != Token.TokenType.RPARENT && Debug.status) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                    Error.ErrorType.LACK_RIGHT_PARENT));
        }
        BlockParser blockParser = new BlockParser(tokenList,symbolList);
        Block block = blockParser.parseBlock();
        if (blockParser.checkReturn() != 1 && Debug.status) {
            ErrorList.addError(new Error(block.getRightBraceLineIndex(),
                    Error.ErrorType.LACK_RETURN));
        }
        return new MainFuncDef(intToken, mainToken, leftParent, rightParent, block);
    }
}
