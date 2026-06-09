package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.Decl;
import frontend.parser.declaration.DeclParser;

/**
 * 解析代码块项的解析器类，可以是声明或语句。
 */
public class BlockItemParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public BlockItemParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析代码块项。
     *
     * @return 解析得到的 BlockItem 对象
     */
    public BlockItem parseBlockItem() {
        // 初始化变量
        Decl declaration = null;
        Stmt statement = null;

        // 初始化子解析器
        DeclParser declParser = new DeclParser(tokenStream);
        StmtParser stmtParser = new StmtParser(tokenStream);

        // 读取下一个 Token
        Token currentToken = tokenStream.readNextToken();
        TokenType tokenType = currentToken.getType();

        // 根据 Token 类型判断是声明还是语句
        if (tokenType == TokenType.INTTK || tokenType == TokenType.CHARTK || tokenType == TokenType.CONSTTK) {
            // 回退一个 Token，解析声明
            tokenStream.unReadTokens(1);
            declaration = declParser.parseDecl();
        } else if (tokenType == TokenType.RBRACE) {
            // 右大括号，回退一个 Token，结束解析
            tokenStream.unReadTokens(1);
            // 不返回任何 BlockItem
        } else {
            // 回退一个 Token，解析语句
            tokenStream.unReadTokens(1);
            statement = stmtParser.parseStmt();
        }

        // 仅在存在声明或语句时才返回 BlockItem
        if (declaration != null || statement != null) {
            return new BlockItem(declaration, statement);
        }
        return null; // 否则返回 null，不添加任何 BlockItem
    }

}
