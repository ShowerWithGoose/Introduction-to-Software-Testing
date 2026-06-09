package frontend.parser.function;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.block.Block;
import frontend.parser.block.BlockParser;

/**
 * 解析主函数定义的解析器类。
 */
public class MainFuncDefParser {
    // Token 列表的迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator  TokenList 的迭代器
     */
    public MainFuncDefParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析主函数定义。
     *
     * @return 解析得到的 MainFuncDef 对象，如果解析失败返回 null
     */
    public MainFuncDef parseMainFuncDef() {
        // 读取 "int" 关键字
        Token intKeyword = tokenIterator.readNextToken();
        // 读取 "main" 关键字
        Token mainKeyword = tokenIterator.readNextToken();
        // 读取左括号 "("
        Token leftParen = tokenIterator.readNextToken();

        // 检查前面三个 Token 是否符合主函数的定义
        if (intKeyword.getType() == TokenType.INTTK &&
                mainKeyword.getType() == TokenType.MAINTK &&
                leftParen.getType() == TokenType.LPARENT) {

            // 读取右括号 ")"
            Token nextToken = tokenIterator.readNextToken();
            Token rightParen;
            if (nextToken.getType() == TokenType.RPARENT) {
                rightParen = nextToken;
            } else {
                // 处理缺失右括号的情况
                rightParen = handleMissingRightParen(leftParen);
            }

            // 解析主函数的函数体
            BlockParser blockParser = new BlockParser(tokenIterator);
            Block mainFunctionBody = blockParser.parseBlock();

            // 返回解析得到的 MainFuncDef 对象
            return new MainFuncDef(intKeyword, mainKeyword, leftParen, rightParen, mainFunctionBody);
        } else {
            // 如果不符合主函数定义，回退读取的 Tokens
            tokenIterator.unReadTokens(3);
            return null;
        }
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
