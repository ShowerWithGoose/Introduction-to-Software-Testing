package frontend.parser.function;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

/**
 * FuncFParamParser 函数形参解析器类
 * <FuncFParam> -> <BType> <Ident> [ '[' ']' ]
 */
public class FuncFParamParser {
    private TokenListIterator iterator;
    /* FuncFParam Attributes */
    private BType btype = null;
    private Ident ident = null;
    private Token leftBracket = null;
    private Token rightBracket = null;
    private FuncFParam funcFParam = null;

    public FuncFParamParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public FuncFParam parseFuncFParam() {
        BTypeParser btypeParser = new BTypeParser(this.iterator);
        this.btype = btypeParser.parseBtype();
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();
        this.leftBracket = this.iterator.next();
        if (this.leftBracket.getTokenType().equals(TokenType.LBRACK)) {
            this.rightBracket = this.iterator.next();
            if (!this.rightBracket.getTokenType().equals(TokenType.RBRACK)) {
                System.out.println("ERROR : EXPECT RBRACK");
                handleKError();
            }
            this.funcFParam = new FuncFParam(this.btype, this.ident, this.leftBracket, this.rightBracket);
        } else {
            this.iterator.unRead(1);
            this.funcFParam = new FuncFParam(this.btype, this.ident);
        }
        return this.funcFParam;
    }

    /**
     * k error
     * missing ']'
     */
    private void handleKError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RBRACK, iterator.next().getLine()));
        this.rightBracket = null;
    }
}
