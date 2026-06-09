package frontend.parser.function;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;

/**
 * MainFuncDefParser 主函数定义解析器类
 * <MainFuncDef> -> 'int' 'main' '(' ')' <Block>
 */
public class MainFuncDefParser {
    private TokenListIterator iterator;
    /* MainFuncDef Attributes */
    private Token intTk; // 'int'
    private Token mainTk; // 'main'
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Block block;

    public MainFuncDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public MainFuncDef parseMainFuncDef() {
        this.intTk = this.iterator.next();
        this.mainTk = this.iterator.next();
        this.leftParent = this.iterator.next();
        this.rightParent = this.iterator.next();
        if (!rightParent.getTokenType().equals(TokenType.RPARENT)) {
            System.out.println("ERROR : EXPECT RPARENT");
            handleJError();
        }
        BlockParser blockParser = new BlockParser(this.iterator);
        this.block = blockParser.parseBlock();
        MainFuncDef mainFuncDef = new MainFuncDef(this.intTk, this.mainTk,
                this.leftParent, this.rightParent, this.block);
        return mainFuncDef;
    }

    /**
     * j error
     * missing ')'
     */
    private void handleJError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RPARENT, iterator.next().getLine()));
        this.rightParent = null;
    }
}
