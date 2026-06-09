package frontend.declaration.constant;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.terminal.Ident;
import frontend.terminal.IdentParser;
import frontend.declaration.constant.constinitval.ConstInitVal;
import frontend.declaration.constant.constinitval.ConstInitValParser;
import frontend.expression.ConstExp;
import frontend.expression.ConstExpParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

import java.util.ArrayList;

/**
 * 解析器: ConstDef (常量定义)
 * 对应文法: ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
 *
 * 解析过程：
 * 1. 解析 Ident（标识符）。
 * 2. 可选解析一个数组索引 (ConstExp)，以 `[` 开头，`]` 结束。
 * 3. 解析赋值符号 '='。
 * 4. 解析 ConstInitVal（常量初值）。
 */
public class ConstDefParser {
    private final TokenListIterator iterator;
    private Ident ident;
    private Token leftBracket; // '['
    private ConstExp constExp; // 数组索引
    private Token rightBracket; // ']'
    private Token eq; // '='
    private ConstInitVal constInitVal;

    public ConstDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstDef parseConstDef() {
        // 解析 Ident
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();

        // 获取下一个 Token，检查是否为 '['
        Token token = iterator.readNextToken();
        if (token.getType().equals(TokenType.LBRACK)) { // 如果是 '['，则解析数组下标
            this.leftBracket = token;

            // 解析 ConstExp（数组下标）
            ConstExpParser constExpParser = new ConstExpParser(this.iterator);
            this.constExp = constExpParser.parseConstExp();

            // 检查是否有 ']'
            token = this.iterator.readNextToken();
            if (!token.getType().equals(TokenType.RBRACK)) {
                // 处理缺少右中括号 ']' 的错误
                Error error = new Error(token.getLineIndex(), ErrorType.MISSING_R_BRACKET);
                ErrorTable.addError(error);
            } else {
                this.rightBracket = token;
            }

            // 获取下一个 Token，应该是 '='
            token = this.iterator.readNextToken();
        }

        // 确保下一个 Token 是 '='
        if (!token.getType().equals(TokenType.ASSIGN)) {
            throw new RuntimeException("Expected '=', but got: " + token.getContent());
        }
        this.eq = token; // 记录 '='

        // 解析 ConstInitVal
        ConstInitValParser constInitValParser = new ConstInitValParser(this.iterator);
        this.constInitVal = constInitValParser.parseConstInitVal();

        // 构建并返回 ConstDef 对象
        return new ConstDef(this.ident, this.leftBracket, this.constExp, this.rightBracket, this.eq, this.constInitVal);
    }
}
