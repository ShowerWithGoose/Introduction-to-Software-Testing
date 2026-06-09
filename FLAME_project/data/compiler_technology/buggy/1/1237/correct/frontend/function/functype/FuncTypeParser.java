package frontend.function.functype;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

/**
 * 解析器: FuncType (函数类型)
 * 对应文法: FuncType → 'void' | 'int' | 'char'
 *
 * 解析函数类型，可以是 void, int 或 char。
 */
public class FuncTypeParser {
    private final TokenListIterator iterator;

    public FuncTypeParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析函数类型。
     * @return 解析后的 FuncType 对象
     */
    public FuncType parseFuncType() {
        // 读取下一个 token
        Token token = this.iterator.readNextToken();

        // 根据 token 类型判断函数类型并进行解析
        FuncTypeEle funcTypeEle;
        switch (token.getType()) {
            case VOIDTK: // 'void'
                funcTypeEle = new FuncTypeVoid(token);
                break;
            case INTTK: // 'int'
                funcTypeEle = new FuncTypeInt(token);
                break;
            case CHARTK: // 'char'
                funcTypeEle = new FuncTypeChar(token);
                break;
            default:
               throw new IllegalArgumentException("Expected 'void', 'int', or 'char', but found: " + token);
        }

        // 构造并返回 FuncType 对象
        return new FuncType(funcTypeEle);
    }
}
