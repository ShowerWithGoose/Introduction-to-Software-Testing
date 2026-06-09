package frontend.expression.unaryexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.FuncRParams;
import frontend.expression.FuncRParamsParser;
import frontend.terminal.Ident;
import frontend.terminal.IdentParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: UnaryExpFunc (函数调用表达式)
 * 对应文法: UnaryExp → Ident '(' [FuncRParams] ')'
 *
 * 解析过程：
 * 1. 解析 Ident (函数名)
 * 2. 读取 '('
 * 3. 如果存在 FuncRParams (函数实参表)，则解析
 * 4. 读取 ')'
 */
public class UnaryExpFuncParser {
    private final TokenListIterator iterator;
    private Ident ident;          // 函数名
    private FuncRParams funcRParams; // 函数实参表
    private Token leftParent;     // '('
    private Token rightParent;    // ')'

    public UnaryExpFuncParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public UnaryExpFunc parseUnaryFuncExp() {
        // 解析 Ident (函数名)
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();

        // 读取 '('
        this.leftParent = this.iterator.readNextToken();

        // 尝试解析 FuncRParams (实参表)
        this.rightParent = this.iterator.readNextToken();

        //j f(;
        if (this.rightParent.getType().equals(TokenType.SEMICN)) {
            if (!this.rightParent.getType().equals(TokenType.RPARENT)) {
                this.rightParent = new Token(TokenType.RPARENT, this.leftParent.getLineIndex(), ")");
                this.iterator.unReadToken(2);
                Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                        ErrorType.MISSING_R_PARENT);
                ErrorTable.addError(error);
            }
        }

        if (!this.rightParent.getType().equals(TokenType.RPARENT)) {
            // 如果不是 ')', 说明有参数
            this.iterator.unReadToken(1); // 回退，解析参数
            FuncRParamsParser funcRParamsParser = new FuncRParamsParser(this.iterator);
            this.funcRParams = funcRParamsParser.parseFuncRParams();
            this.rightParent = this.iterator.readNextToken(); // 读取 ')'


            // 处理 j 类错误：缺少右括号 ')'
            if (!this.rightParent.getType().equals(TokenType.RPARENT)) {
                this.iterator.unReadToken(2); // 回退两格，获取非终结符的行号
                Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                        ErrorType.MISSING_R_PARENT);  // j 类错误
                ErrorTable.addError(error);
            }
        }



        // 构造 UnaryExpFunc 对象
        return funcRParams != null
                ? new UnaryExpFunc(this.ident, this.funcRParams, this.leftParent, this.rightParent)
                : new UnaryExpFunc(this.ident, this.leftParent, this.rightParent);
    }
}
