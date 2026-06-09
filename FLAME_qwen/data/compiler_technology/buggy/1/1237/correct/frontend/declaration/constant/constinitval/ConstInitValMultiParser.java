package frontend.declaration.constant.constinitval;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.ConstExpParser;
import frontend.expression.ConstExp;

import java.util.ArrayList;

/**
 * 解析器: ConstInitValMulti (数组形式的常量初值)
 * 对应文法: ConstInitVal → '{' [ ConstExp { ',' ConstExp } ] '}'
 *
 * 解析过程：
 * 1. 解析数组形式的常量初值，数组由花括号包围 ('{' 和 '}')。
 * 2. 可能存在多个用逗号分隔的常量初值。
 */
public class ConstInitValMultiParser {
    private final TokenListIterator iterator;
    private Token leftBrace = null; // '{'
    private ConstExp first; // 第一个常量表达式初值，可能不存在
    private final ArrayList<Token> commas = new ArrayList<>(); // 逗号，可能存在
    private final ArrayList<ConstExp> constExps = new ArrayList<>(); // 其余的常量表达式初值，可能存在
    private Token rightBrace = null; // '}'

    public ConstInitValMultiParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstInitValMulti parseConstInitValMulti() {
        // 解析 '{'
        this.leftBrace = this.iterator.readNextToken();
        if (!this.leftBrace.getType().equals(TokenType.LBRACE)) {
            System.out.println("ERROR: EXPECTED '{'");
        }

        // 判断是否有内容
        Token token = this.iterator.readNextToken();
        if (!token.getType().equals(TokenType.RBRACE)) { // 如果不是 '}', 则存在初值
            this.iterator.unReadToken(1);

            // 解析第一个常量表达式初值
            ConstExpParser constExpParser = new ConstExpParser(this.iterator);
            this.first = constExpParser.parseConstExp();

            // 解析后续的常量表达式初值
            token = this.iterator.readNextToken();
            while (token.getType().equals(TokenType.COMMA)) { // ',' 分隔符
                this.commas.add(token);
                this.constExps.add(constExpParser.parseConstExp());
                token = this.iterator.readNextToken();
            }

            // 将最后读取的 token 退回
            this.iterator.unReadToken(1);
        } else {
            // 如果直接是 '}', 表示为空数组
            this.iterator.unReadToken(1);
        }

        // 解析 '}'
        this.rightBrace = this.iterator.readNextToken();
        if (!this.rightBrace.getType().equals(TokenType.RBRACE)) {
            System.out.println("ERROR: EXPECTED '}'");
        }

        // 返回解析后的 ConstInitValMulti 对象
        return new ConstInitValMulti(this.leftBrace, this.first, this.commas, this.constExps, this.rightBrace);
    }
}
