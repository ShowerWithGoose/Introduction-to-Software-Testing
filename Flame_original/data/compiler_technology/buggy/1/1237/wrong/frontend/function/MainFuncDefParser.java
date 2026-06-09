package frontend.function;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.statement.Block;
import frontend.statement.BlockParser;
import frontend.TokenType;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: MainFuncDefParser (主函数定义)
 * 对应文法: MainFuncDef → 'int' 'main' '(' ')' Block
 *
 * 解析 main 函数定义，包含返回类型、函数名、参数和函数体。
 */
public class MainFuncDefParser {
    private final TokenListIterator iterator;

    public MainFuncDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析主函数定义，返回包含解析后的 MainFuncDef 对象。
     *
     * @return 解析后的 MainFuncDef 对象
     */
    public MainFuncDef parseMainFuncDef() {
        // 解析 'int'
        Token intTk = this.iterator.readNextToken();
        if (!intTk.getType().equals(TokenType.INTTK)) {
            throw new IllegalArgumentException("Expected 'int' keyword in main function definition, but found: " + intTk);
        }

        // 解析 'main'
        Token mainTk = this.iterator.readNextToken();
        if (!mainTk.getType().equals(TokenType.MAINTK)) {
            throw new IllegalArgumentException("Expected 'main' keyword in main function definition, but found: " + mainTk);
        }

        // 解析 '('
        Token leftParent = this.iterator.readNextToken();
        if (!leftParent.getType().equals(TokenType.LPARENT)) {
            throw new IllegalArgumentException("Expected '(' after 'main', but found: " + leftParent);
        }

        // 解析 ')'
        Token rightParent = this.iterator.readNextToken();
        if (!rightParent.getType().equals(TokenType.RPARENT)) {
            // 处理 j 类错误：缺少右小括号 ')'
            this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_PARENT);
            ErrorTable.addError(error);
        }

        // 解析 Block
        BlockParser blockParser = new BlockParser(this.iterator);
        Block block = blockParser.parseBlock();

        // 创建并返回 MainFuncDef 对象
        return new MainFuncDef(intTk, mainTk, leftParent, rightParent, block);
    }
}
