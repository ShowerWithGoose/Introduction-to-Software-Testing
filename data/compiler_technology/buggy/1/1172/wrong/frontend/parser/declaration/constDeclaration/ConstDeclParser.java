package frontend.parser.declaration.constDeclaration;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.constDeclaration.ConstDecl;
import frontend.parser.declaration.constDeclaration.ConstDef;
import frontend.parser.declaration.constDeclaration.ConstDefParser;

import java.util.LinkedList;

/**
 * 解析常量声明的解析器类。
 */
public class ConstDeclParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public ConstDeclParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析常量声明。
     *
     * @return 解析得到的 ConstDecl 对象
     */
    public ConstDecl parseConstDecl() {
        // 声明各部分的变量
        Token constKeyword = null;
        Token baseTypeToken = null;
        LinkedList<ConstDef> constDefList = new LinkedList<>();
        LinkedList<Token> commaTokenList = new LinkedList<>();
        Token semicolonToken = null;

        ConstDefParser constDefParser = new ConstDefParser(tokenIterator);

        // 解析 const 关键字
        Token currentToken = tokenIterator.readNextToken();
        if (currentToken.getType() != TokenType.CONSTTK) {
            throw new Error("Expected CONSTTK in ConstDecl");
        } else {
            constKeyword = currentToken;
        }

        // 解析基本类型
        currentToken = tokenIterator.readNextToken();
        if (currentToken.getType() == TokenType.INTTK || currentToken.getType() == TokenType.CHARTK) {
            baseTypeToken = currentToken;
        } else {
            throw new Error("Expected INTTK or CHARTK in ConstDecl");
        }

        // 循环解析常量定义
        while (tokenIterator.hasNext()) {
            // 预读取下一个 Token，判断是否为标识符
            currentToken = tokenIterator.readNextToken();
            if (currentToken.getType() == TokenType.IDENFR) {
                // 回退一个 Token，因为 ConstDefParser 需要从标识符开始
                tokenIterator.unReadTokens(1);
                // 解析常量定义
                ConstDef constDef = constDefParser.parseConstDef();
                constDefList.add(constDef);
            } else {
                throw new Error("Expected IDENFR in ConstDecl for ConstDef");
            }

            // 预读取下一个 Token，判断是逗号还是分号
            currentToken = tokenIterator.readNextToken();
            if (currentToken.getType() == TokenType.COMMA) {
                // 添加逗号 Token
                commaTokenList.add(currentToken);
            } else if (currentToken.getType() == TokenType.SEMICN) {
                // 遇到分号，声明结束
                semicolonToken = currentToken;
                break;
            } else {
                // 非法的 Token，回退一个 Token，并记录缺少分号的错误
                tokenIterator.unReadTokens(1);
                semicolonToken = new Token(TokenType.SEMICN, ";", currentToken.getLine());
                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, currentToken.getLine());
                break;
            }
        }

        // 创建并返回 ConstDecl 对象
        return new ConstDecl(constKeyword, baseTypeToken, constDefList, commaTokenList, semicolonToken);
    }
}
