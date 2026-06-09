package frontend.parser.declaration.constant.constInitVal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

import java.util.ArrayList;

/**
 * <ConstInitVal>一维数组初值子节点解析器类
 * '{' [ <ConstInitVal> { ',' <ConstInitVal> } ] '}'
 */
public class ConstInitValMultiParser {
    private TokenListIterator iterator;
    /* ConstInitMulti Attributes */
    private Token leftBrace = null; // '{'
    private ConstExp first; // MAY exist
    private ArrayList<Token> commas = new ArrayList<>(); // MAY exist
    private ArrayList<ConstExp> constExps = new ArrayList<>(); // MAY exist
    private Token rightBrace = null; // '}'

    public ConstInitValMultiParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstInitValMulti parseConstInitValMulti() {
        this.commas = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.leftBrace = this.iterator.next();
        if (!this.leftBrace.getTokenType().equals(TokenType.LBRACE)) {
            System.out.println("EXPECT LBRACE HERE");
        }
        Token token = this.iterator.next();
        if (!token.getTokenType().equals(TokenType.RBRACE)) {
            this.iterator.unRead(1);
            ConstExpParser constExpParser = new ConstExpParser(this.iterator);
            this.first = constExpParser.parseConstExp();
            token = this.iterator.next();
            while (token.getTokenType().equals(TokenType.COMMA)) { // ','
                this.commas.add(token);
                this.constExps.add(constExpParser.parseConstExp());
                token = this.iterator.next();
            }
            this.iterator.unRead(1);
        } else {
            this.iterator.unRead(1);
        }
        this.rightBrace = this.iterator.next();
        ConstInitValMulti constInitValMulti = new ConstInitValMulti(this.leftBrace,
                this.first, this.commas, this.constExps, this.rightBrace);
        return constInitValMulti;
    }
}
