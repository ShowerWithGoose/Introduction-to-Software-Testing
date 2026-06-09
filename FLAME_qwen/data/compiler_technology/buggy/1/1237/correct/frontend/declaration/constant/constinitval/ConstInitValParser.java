package frontend.declaration.constant.constinitval;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.ConstExpParser;
import frontend.terminal.StringConstParser;

/**
 * 解析器: ConstInitVal (常量初值)
 * 对应文法: ConstInitVal → ConstExp | '{' [ ConstInitVal { ',' ConstInitVal } ] '}' | StringConst
 *
 * 解析过程：
 * 1. 如果初值为 '{' 开头，解析数组形式的初值。
 * 2. 否则解析为单一的常量表达式 (ConstExp)。
 */
public class ConstInitValParser {
    private final TokenListIterator iterator;
    private ConstInitValEle constInitValEle;

    public ConstInitValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstInitVal parseConstInitVal() {
        // 读取下一个 token
        Token token = this.iterator.readNextToken();

        // 判断是数组形式初值、字符串常量还是常量表达式初值
        if (token.getType().equals(TokenType.LBRACE)) { // '{' 表示数组初值
            this.iterator.unReadToken(1);
            ConstInitValMultiParser constInitValMultiParser = new ConstInitValMultiParser(this.iterator);
            this.constInitValEle = constInitValMultiParser.parseConstInitValMulti();
        } else if (token.getType().equals(TokenType.STRCON)) { // 处理字符串常量
            this.iterator.unReadToken(1);
            StringConstParser stringConstParser = new StringConstParser(this.iterator);
            this.constInitValEle = stringConstParser.parseStringConst();
        } else { // 常量表达式初值
            this.iterator.unReadToken(1);
            ConstExpParser constExpParser = new ConstExpParser(this.iterator);
            this.constInitValEle = constExpParser.parseConstExp();
        }

        // 返回解析后的 ConstInitVal 对象
        return new ConstInitVal(this.constInitValEle);
    }
}
