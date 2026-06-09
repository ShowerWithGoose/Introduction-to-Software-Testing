package frontend.parser.declaration.varDeclaration;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析变量声明的解析器类。
 */
public class VarDeclParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public VarDeclParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析变量声明。
     *
     * @return 解析得到的 VarDecl 对象
     */
    public VarDecl parseVarDecl() {
        // 初始化变量
        Token baseTypeToken;
        LinkedList<VarDef> varDefList = new LinkedList<>();
        LinkedList<Token> commaTokenList = new LinkedList<>();
        Token semicolonToken = null;

        VarDefParser varDefParser = new VarDefParser(tokenIterator);

        // 读取基本类型 Token
        Token currentToken = tokenIterator.readNextToken();
        if (currentToken.getType() == TokenType.INTTK || currentToken.getType() == TokenType.CHARTK) {
            baseTypeToken = currentToken;
        } else {
            throw new Error("Expected INTTK or CHARTK in VarDecl");
        }

        // 解析变量定义
        while (tokenIterator.hasNext()) {
            // 解析 VarDef
            VarDef varDef = varDefParser.parseVarDef();
            varDefList.add(varDef);

            // 读取下一个 Token，判断是逗号还是分号
            Token nextToken = tokenIterator.readNextToken();
            if (nextToken.getType() == TokenType.COMMA) {
                commaTokenList.add(nextToken);
            } else if (nextToken.getType() == TokenType.SEMICN) {
                semicolonToken = nextToken;
                break;
            } else {
                // 回退一个 Token并处理缺少分号的情况
                tokenIterator.unReadTokens(1);
                semicolonToken = new Token(TokenType.SEMICN, ";", currentToken.getLine());
                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, currentToken.getLine());
                break;
            }
        }

        // 创建并返回 VarDecl 对象
        return new VarDecl(baseTypeToken, varDefList, commaTokenList, semicolonToken);
    }
}
