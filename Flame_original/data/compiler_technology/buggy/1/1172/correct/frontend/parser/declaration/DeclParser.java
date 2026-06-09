package frontend.parser.declaration;

import frontend.lexer.*;
import frontend.parser.declaration.*;
import frontend.parser.declaration.constDeclaration.*;
import frontend.parser.declaration.varDeclaration.*;

/**
 * 解析声明的解析器类。
 */
public class DeclParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public DeclParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析声明。
     *
     * @return 解析得到的 Decl 对象
     */
    public Decl parseDecl() {
        // 初始化子解析器
        VarDeclParser variableDeclParser = new VarDeclParser(tokenIterator);
        ConstDeclParser constantDeclParser = new ConstDeclParser(tokenIterator);

        // 预读取下一个 Token
        Token peekToken = tokenIterator.readNextToken();
        // 回退一个 Token，因为后续解析器需要从当前 Token 开始
        tokenIterator.unReadTokens(1);

        // 根据 Token 类型选择解析器
        switch (peekToken.getType()) {
            case CONSTTK:
                // 常量声明
                ConstDecl constDecl = constantDeclParser.parseConstDecl();
                return new Decl(constDecl);
            case INTTK:
            case CHARTK:
                // 变量声明
                VarDecl varDecl = variableDeclParser.parseVarDecl();
                return new Decl(varDecl);
            default:
                // 遇到意外的 Token，抛出异常
                throw new Error("Unexpected token type: " + peekToken.getType());
        }
    }
}
