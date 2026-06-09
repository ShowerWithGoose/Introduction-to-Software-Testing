package frontend.expression.primaryexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import frontend.terminal.Ident;
import frontend.terminal.IdentParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

import java.util.ArrayList;

/**
 * 解析器: LVal (左值表达式)
 * 对应文法: LVal → Ident ['[' Exp ']']
 *
 * 解析过程：
 * 1. 解析 Ident（标识符）。
 * 2. 可选解析若干个数组索引 (Exp)，每个索引以 `[` 开头，`]` 结束。
 */
public class LValParser {
    private final TokenListIterator iterator;
    private Ident ident;
    private final ArrayList<Token> leftBrackets = new ArrayList<>();
    private final ArrayList<Exp> exps = new ArrayList<>();
    private final ArrayList<Token> rightBrackets = new ArrayList<>();

    public LValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public LVal parseLVal() {
        // 解析 Ident
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();

        // 解析可选的 '[' Exp ']'
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.LBRACK)) { // '['
            this.leftBrackets.add(token);

            // 解析 Exp
            ExpParser expParser = new ExpParser(this.iterator);
            this.exps.add(expParser.parseExp());

            // 解析 ']'
            token = this.iterator.readNextToken();
            if (!token.getType().equals(TokenType.RBRACK)) {
                // 处理 k 类错误：缺少 ']'
                this.iterator.unReadToken(2); // 回退两格以获取之前非终结符的行号
                Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                        ErrorType.MISSING_R_BRACKET);  // k 类错误
                ErrorTable.addError(error);
            }
            this.rightBrackets.add(token);

            // 继续查看是否有更多的 '['
            token = this.iterator.readNextToken();
        }

        // 退回最后一个非匹配的 token
        this.iterator.unReadToken(1);

        // 构建并返回 LVal 对象
        return new LVal(this.ident, this.leftBrackets, this.exps, this.rightBrackets);
    }
}
