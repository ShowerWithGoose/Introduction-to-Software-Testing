package frontend.parser.function;

import frontend.SyntaxError.*;
import frontend.lexer.*;
import frontend.parser.block.*;
import frontend.parser.funcparas.*;

/**
 * 解析函数定义的解析器类。
 */
public class FuncDefParser {
    // Token 列表的迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator  TokenList 的迭代器
     */
    public FuncDefParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析函数定义。
     *
     * @return 解析得到的 FuncDef 对象
     */
    public FuncDef parseFuncDef() {
        // 读取函数返回类型
        Token returnType = tokenIterator.readNextToken();
        // 读取函数名
        Token functionName = tokenIterator.readNextToken();
        // 读取左括号 "("
        Token leftParen = tokenIterator.readNextToken();
        // 函数参数列表（可能为空）
        FuncFParams parameters = null;
        // 右括号 ")"
        Token rightParen;

        // 预读取下一个 Token，判断是否有参数列表
        Token nextToken = tokenIterator.readNextToken();
        FuncFParamsParser paramsParser = new FuncFParamsParser(tokenIterator);
        BlockParser blockParser = new BlockParser(tokenIterator);

        // 判断下一个 Token 类型
        if (nextToken.getType() == TokenType.INTTK || nextToken.getType() == TokenType.CHARTK) {
            // 回退一个 Token，因为参数解析需要从参数类型开始
            tokenIterator.unReadTokens(1);
            // 解析参数列表
            parameters = paramsParser.parseFuncFParams();
        } else {
            // 回退一个 Token，可能是右括号
            tokenIterator.unReadTokens(1);
        }

        // 读取右括号 ")"
        Token possibleRightParen = tokenIterator.readNextToken();
        if (possibleRightParen.getType() != TokenType.RPARENT) {
            // 如果不是右括号，处理缺失的右括号错误
            rightParen = handleMissingRightParen(leftParen);
        } else {
            rightParen = possibleRightParen;
        }

        // 解析函数体
        Block functionBody = blockParser.parseBlock();
        // 返回解析得到的 FuncDef 对象
        return new FuncDef(returnType, functionName, leftParen, parameters, rightParen, functionBody);
    }

    /**
     * 处理缺失右括号的情况，记录错误并生成补全的右括号 Token。
     *
     * @param leftParen  左括号 Token，用于获取错误行号
     * @return 补全的右括号 Token
     */
    private Token handleMissingRightParen(Token leftParen) {
        // 回退一个 Token，因为刚刚读取的 Token 不是右括号
        tokenIterator.unReadTokens(1);
        // 记录语法错误
        SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, leftParen.getLine());
        // 返回一个补全的右括号 Token
        return new Token(TokenType.RPARENT, ")", leftParen.getLine());
    }
}
