package frontend.function;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.declaration.BType;
import frontend.declaration.BTypeParser;
import frontend.terminal.Ident;
import frontend.terminal.IdentParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: FuncFParam (函数形参)
 * 对应文法: FuncFParam → BType Ident ['[' ']']
 *
 * 解析函数形参，支持普通变量和一维数组变量。
 */
public class FuncFParamParser {
    private final TokenListIterator iterator;

    public FuncFParamParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析函数形参，支持普通变量和一维数组变量。
     *
     * @return 解析后的 FuncFParam 对象
     */
    public FuncFParam parseFuncFParam() {
        // 解析 BType
        BTypeParser btypeParser = new BTypeParser(this.iterator);
        BType btype = btypeParser.parseBtype();

        // 解析 Ident
        IdentParser identParser = new IdentParser(this.iterator);
        Ident ident = identParser.parseIdent();

        // 检查是否有 '['，表示一维数组
        Token nextToken = this.iterator.readNextToken();
        if (nextToken.getType().equals(TokenType.LBRACK)) {
            Token leftBracket = nextToken;

            // 解析 ']'
            Token rightBracket = this.iterator.readNextToken();
            if (!rightBracket.getType().equals(TokenType.RBRACK)) {
                // 处理 k 类错误：缺少右中括号 ']'
                this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
                Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_BRACKET);
                ErrorTable.addError(error);
            }

            // 创建一维数组的 FuncFParam 对象
            return new FuncFParam(btype, ident, leftBracket, rightBracket);
        } else {
            // 如果没有 '['，则回退 Token，表示普通变量
            this.iterator.unReadToken(1);

            // 创建普通变量的 FuncFParam 对象
            return new FuncFParam(btype, ident);
        }
    }
}
