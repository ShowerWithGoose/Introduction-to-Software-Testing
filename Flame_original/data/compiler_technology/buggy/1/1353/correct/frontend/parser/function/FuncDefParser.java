package frontend.parser.function;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.function.functype.FuncType;
import frontend.parser.function.functype.FuncTypeParser;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

/**
 * FuncDefParser 函数定义解析器类
 * <FuncDef> -> <FuncType> <Ident> '(' [ <FuncFPrams> ] ')' <Block>
 */
public class FuncDefParser {
    private TokenListIterator iterator;
    /* FuncDef Attributes */
    private FuncType funcType = null;
    private Ident ident = null;
    private Token leftParent = null; // '('
    private FuncFParams funcFParams = null; // MAY exist
    private Token rightParent = null; // ')'
    private Block block = null;
    private FuncDef funcDef = null;

    public FuncDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public FuncDef parseFuncDef() {
        FuncTypeParser funcTypeParser = new FuncTypeParser(this.iterator);
        this.funcType = funcTypeParser.parseFuncType();
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();
        this.leftParent = this.iterator.next();
        this.rightParent = this.iterator.next();
        if (!this.rightParent.getTokenType().equals(TokenType.RPARENT)) {
            if (this.rightParent.getTokenType().equals(TokenType.INTTK) || this.rightParent.getTokenType().equals(TokenType.CHARTK)) {  // 预读FuncFParams
                this.iterator.unRead(1);
                FuncFParamsParser funcFParamsParser = new FuncFParamsParser(this.iterator);
                this.funcFParams = funcFParamsParser.parseFuncFParams();
                this.rightParent = this.iterator.next();
                if (!this.rightParent.getTokenType().equals(TokenType.RPARENT)) {
                    System.out.println("ERROR : EXPECT RPARENT");
                    handleJError();
                }
            } else {
                System.out.println("ERROR : EXPECT RPARENT");
                handleJError();
            }
            BlockParser blockParser = new BlockParser(this.iterator);
            this.block = blockParser.parseBlock();
            this.funcDef = new FuncDef(this.funcType, this.ident, this.leftParent,
                    this.funcFParams, this.rightParent, this.block);
        } else {
            BlockParser blockParser = new BlockParser(this.iterator);
            this.block = blockParser.parseBlock();
            this.funcDef = new FuncDef(this.funcType, this.ident, this.leftParent,
                    this.rightParent, this.block);
        }
        return funcDef;
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
