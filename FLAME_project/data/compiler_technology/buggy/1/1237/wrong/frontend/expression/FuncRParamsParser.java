package frontend.expression;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

import java.util.ArrayList;

/**
 * 解析器: FuncRParams (函数实参表)
 * 对应文法: FuncRParams → Exp { ',' Exp }
 *
 * 解析过程：
 * 1. 解析第一个表达式 Exp
 * 2. 如果存在逗号 ',', 则继续解析后续的 Exp
 */
public class FuncRParamsParser {
    private final TokenListIterator iterator;
    private Exp firstExp;  // 第一个表达式
    private final ArrayList<Token> commas = new ArrayList<>(); // ',' 分隔符
    private final ArrayList<Exp> otherExps = new ArrayList<>(); // 后续表达式

    public FuncRParamsParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public FuncRParams parseFuncRParams() {
        ExpParser expParser = new ExpParser(this.iterator);
        // 解析第一个表达式
        firstExp = expParser.parseExp();

        // 解析剩余表达式（以逗号分隔）
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) { // ',' 分隔符
            commas.add(token);
            otherExps.add(expParser.parseExp());
            token = this.iterator.readNextToken();
        }

        // 回退最后一个非逗号的 token
        this.iterator.unReadToken(1);

        // 构建 FuncRParams 对象并返回
        return new FuncRParams(this.firstExp, this.commas, this.otherExps);
    }
}
