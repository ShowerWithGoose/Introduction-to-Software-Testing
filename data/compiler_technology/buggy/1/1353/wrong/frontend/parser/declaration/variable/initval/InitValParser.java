package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.StringConstParser;

import java.util.ArrayList;

/**
 * InitValParser 变量初值解析器类
 * <InitVal> -> <Exp> | '{' [ <Exp> { ',' <Exp> } ] '}' | StringConst
 */
public class InitValParser {
    private TokenListIterator iterator;
    /* InitVal Attributes */
    private Token leftBrace = null; // '{'
    private Exp first = null;
    private ArrayList<Token> commas = new ArrayList<>(); // ','
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rightBrace; // '}'
    private InitValEle initValEle = null;

    public InitValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public InitVal parseInitVal() {
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.leftBrace = this.iterator.next();
        if (this.leftBrace.getTokenType().equals(TokenType.RBRACE)) {    // '{'
            Token token = this.iterator.next();
            if (!token.getTokenType().equals(TokenType.RBRACE)) {
                this.iterator.unRead(1);
                ExpParser expParser = new ExpParser(this.iterator);
                this.first = expParser.parseExp();
                token = this.iterator.next();
                while (token.getTokenType().equals(TokenType.COMMA)) {
                    this.commas.add(token);
                    this.exps.add(expParser.parseExp());
                    token = this.iterator.next();
                }
            }
            this.rightBrace = token;
            initValEle = new InitValMultiExp(this.leftBrace, this.first, this.commas,
                    this.exps, this.rightBrace);
        } else if (this.leftBrace.getTokenType().equals(TokenType.STRCON)) {    // String Const
            this.iterator.unRead(1);
            StringConstParser stringConstParser = new StringConstParser(this.iterator);
            this.initValEle = stringConstParser.parseStringConst();
        } else {    // <Exp>
            this.iterator.unRead(1);
            ExpParser expParser = new ExpParser(this.iterator);
            this.initValEle = expParser.parseExp();
        }
            InitVal initVal = new InitVal(this.initValEle);
        return initVal;
    }
}
