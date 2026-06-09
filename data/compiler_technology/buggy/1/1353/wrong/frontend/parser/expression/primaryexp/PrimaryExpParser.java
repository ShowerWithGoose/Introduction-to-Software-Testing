package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

/**
 * PrimaryExpParser 基本表达式解析器类
 * <PrimaryExp> -> '(' <Exp> ')' | <LVal> | <Number> | <Character>
 */
public class PrimaryExpParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * primaryExpEle <PrimaryExp>分支
     */
    private TokenListIterator iterator;
    private PrimaryExpEle primaryExpEle;

    public PrimaryExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parsePrimaryExp()
     * 解析基本表达式方法
     * 预读1个单词，分别判断是否符合每个分支的第一个单词
     * 若符合其中任何一个，则回退1个单词，调用对应的解析器，并创造子节点
     * @return PrimaryExp实例
     */
    public PrimaryExp parsePrimaryExp() {
        Token token = this.iterator.next();
        if (token.getTokenType().equals(TokenType.LPARENT)) { // '('
            this.iterator.unRead(1);
            PrimaryExpExpParser primaryExpExpParser = new PrimaryExpExpParser(this.iterator);
            this.primaryExpEle = primaryExpExpParser.parsePrimaryExpExp();
        } else if (token.getTokenType().equals(TokenType.IDENFR)) { // IDENFR
            this.iterator.unRead(1);
            LValParser lvalParser = new LValParser(this.iterator);
            this.primaryExpEle = lvalParser.parseLVal();
        } else if (token.getTokenType().equals(TokenType.INTCON)) { // INT
            this.iterator.unRead(1);
            NumberParser numberParser = new NumberParser(this.iterator);
            this.primaryExpEle = numberParser.parseNumber();
        } else if (token.getTokenType().equals(TokenType.CHRCON)) { // CHAR
            this.iterator.unRead(1);
            CharacterParser characterParser = new CharacterParser(this.iterator);
            this.primaryExpEle = characterParser.parseCharacter();
        }
        PrimaryExp primaryExp = new PrimaryExp(this.primaryExpEle);
        return primaryExp;
    }
}
