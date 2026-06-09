package frontend.parser.declaration.variable.vardef;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.variable.initval.InitVal;
import frontend.parser.declaration.variable.initval.InitValParser;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

/**
 * VarDefParser 变量定义解析器类
 * <VarDef> -> <Ident> [ '[' <ConstExp> ']' ] | <Ident> [ '[' <ConstExp> ']' ] '=' <InitVal>
 */
public class VarDefParser {
    private TokenListIterator iterator;
    /* VarDef Attributes */
    private Ident ident = null;
    private Token leftBracket = null;
    private ConstExp constExp = null;
    private Token rightBracket = null;
    /* Init Val */
    private Token eq = null;
    private InitVal initVal = null;
    /* VarDefEle */
    private VarDefEle varDefEle = null;

    public VarDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public VarDef parseVarDef() {
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();
        Token token = this.iterator.next();
        if (token.getTokenType().equals(TokenType.LBRACK)) {    // '['
            this.leftBracket = token;
            ConstExpParser expParser = new ConstExpParser(this.iterator);
            this.constExp = expParser.parseConstExp();
            token = this.iterator.next();
            if (token.getTokenType().equals(TokenType.RBRACK)) {
                this.rightBracket = token;
            }else {
                System.out.println("ERROR : EXPECT RBRACK");
                handleKError();
            }
            token = this.iterator.next();
        }
        if (token.getTokenType().equals(TokenType.ASSIGN)) { // '='
            this.eq = token;
            InitValParser initValParser = new InitValParser(this.iterator);
            this.initVal = initValParser.parseInitVal();
            this.varDefEle = new VarDefInit(this.ident, this.leftBracket,
                    this.constExp, this.rightBracket, this.eq, this.initVal);
        } else {
            // token now is ';', need to backspace
            this.iterator.unRead(1);
            this.varDefEle = new VarDefNull(this.ident, this.leftBracket,
                    this.constExp, this.rightBracket);
        }
        VarDef varDef = new VarDef(this.varDefEle);
        return varDef;
    }

    /**
     * k error
     * missing ']'
     */
    private void handleKError() {
        iterator.unRead(2); // 后退两个以确定上一个非终结符的位置
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RBRACK, iterator.next().getLine()));
        this.rightBracket = null;
    }
}
