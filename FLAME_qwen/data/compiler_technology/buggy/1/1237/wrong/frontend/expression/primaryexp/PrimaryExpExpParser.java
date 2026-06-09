package frontend.expression.primaryexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: PrimaryExpExp (括号包裹的表达式)
 * 对应文法: PrimaryExp → '(' Exp ')'
 *
 * 解析基本表达式中的括号包裹表达式，解析过程为：
 * 1. 读取 '('
 * 2. 解析 Exp (表达式)
 * 3. 读取 ')'
 */
public class PrimaryExpExpParser {
    private final TokenListIterator iterator;
    private Token leftParent;  // '('
    private Exp exp;           // 表达式 Exp
    private Token rightParent; // ')'

    public PrimaryExpExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public PrimaryExpExp parsePrimaryExpExp() {
        // 读取 '('
        this.leftParent = this.iterator.readNextToken();

        // 解析 Exp
        ExpParser expParser = new ExpParser(this.iterator);
        this.exp = expParser.parseExp();

        // 读取 ')'
        this.rightParent = this.iterator.readNextToken();
        if (!this.rightParent.getType().equals(TokenType.RPARENT)) {
            // 处理 j 类错误：缺少右括号 ')'
            this.iterator.unReadToken(2); // 回退两格，获取非终结符的行号
            Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                    ErrorType.MISSING_R_PARENT);  // j 类错误
            ErrorTable.addError(error);
        }

        // 返回解析后的 PrimaryExpExp 对象
        return new PrimaryExpExp(this.leftParent, this.exp, this.rightParent);
    }
}
