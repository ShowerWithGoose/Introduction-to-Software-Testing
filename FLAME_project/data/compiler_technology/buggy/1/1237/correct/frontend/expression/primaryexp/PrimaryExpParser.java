package frontend.expression.primaryexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.terminal.CharConstParser;

/**
 * 解析器: PrimaryExp (基本表达式)
 * 对应文法: PrimaryExp → '(' Exp ')' | LVal | Number | Character
 *
 * 解析基本表达式 (PrimaryExp)，处理四种情况：
 * 1. '(' Exp ')'
 * 2. 左值表达式 (LVal)
 * 3. 数字常量 (Number)
 * 4. 字符常量 (Character)
 */
public class PrimaryExpParser {
    private final TokenListIterator iterator;
    private PrimaryExpEle primaryExpEle;

    public PrimaryExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public PrimaryExp parsePrimaryExp() {
        Token token = iterator.readNextToken();

        // 情况1: '(' Exp ')'
        if (token.getType().equals(TokenType.LPARENT)) {
            iterator.unReadToken(1);
            PrimaryExpExpParser primaryExpExpParser = new PrimaryExpExpParser(iterator);
            primaryExpEle = primaryExpExpParser.parsePrimaryExpExp();

            // 情况2: 左值表达式 LVal
        } else if (token.getType().equals(TokenType.IDENFR)) {
            iterator.unReadToken(1);
            LValParser lvalParser = new LValParser(iterator);
            primaryExpEle = lvalParser.parseLVal();

            // 情况3: 数字常量 Number
        } else if (token.getType().equals(TokenType.INTCON)) {
            iterator.unReadToken(1);
            NumberParser numberParser = new NumberParser(iterator);
            primaryExpEle = numberParser.parseNumber();

            // 情况4: 字符常量 Character
        } else if (token.getType().equals(TokenType.CHRCON)) {
            iterator.unReadToken(1);
            CharacterParser characterParser = new CharacterParser(iterator);
            primaryExpEle = characterParser.parseCharacter();  // 调用 CharacterParser
        }

        // 返回解析后的 PrimaryExp 对象
        return new PrimaryExp(primaryExpEle);
    }
}
