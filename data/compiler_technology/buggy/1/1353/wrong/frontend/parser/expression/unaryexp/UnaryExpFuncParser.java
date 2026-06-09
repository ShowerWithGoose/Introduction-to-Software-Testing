package frontend.parser.expression.unaryexp;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.FuncRParams;
import frontend.parser.expression.FuncRParamsParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

/**
 * UnaryExpFuncParser <UnaryExp>Func子节点解析器类
 * <Ident> '(' [<FuncRParams> ')'
 */
public class UnaryExpFuncParser {
    /**
     * 属性：
     * iterator 单词表迭代器，从之前的地方继续读取
     * ident <Ident>
     * leftParent '('
     * funcRParams <FuncRParams>，可选
     * rightParent ')'
     * unaryExpFunc 要返回的<UnaryExpFunc>实例
     */
    private TokenListIterator iterator;
    private Ident ident = null;
    private FuncRParams funcRParams = null;
    private Token leftParent;
    private Token rightParent;
    private UnaryExpFunc unaryExpFunc = null;

    public UnaryExpFuncParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * parseUnaryExpFunc()
     * 解析<UnaryExp>Func子节点方法
     * 依次调用<Ident>解析器，读入'(',')'
     * 若第三个单词不是')'，则判断是不是<FuncRParams>
     * @return UnaryExpFunc实例
     */
    public UnaryExpFunc parseUnaryExpFunc() {
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();
        this.leftParent = this.iterator.next();
        this.rightParent = this.iterator.next();
        if (!this.rightParent.getTokenType().equals(TokenType.RPARENT)) {
            TokenType type = this.rightParent.getTokenType();
            if (type.equals(TokenType.LPARENT) || type.equals(TokenType.IDENFR) || type.equals(TokenType.INTCON) || type.equals(TokenType.CHRCON) || type.equals(TokenType.PLUS) || type.equals(TokenType.MINU) || type.equals(TokenType.NOT)) {    // 预读，是FuncRParams
                this.iterator.unRead(1);
                FuncRParamsParser funcRParamsParser = new FuncRParamsParser(this.iterator);
                this.funcRParams = funcRParamsParser.parseFuncRParams();
                this.rightParent = this.iterator.next();
                if (!this.rightParent.getTokenType().equals(TokenType.RPARENT)) {
                    System.out.println("ERROR : EXPECT RPARENT");
                    handleJError();
                }
            } else {
                System.out.println("ERROR : EXPECT RPARENT");
                handleJError();
            }
            unaryExpFunc = new UnaryExpFunc(this.ident, this.funcRParams,
                    this.leftParent, this.rightParent);
        } else {
            unaryExpFunc = new UnaryExpFunc(this.ident, this.leftParent, this.rightParent);
        }
        return unaryExpFunc;
    }

    /**
     * j error
     * missing ')'
     */
    private void handleJError() {
        iterator.unRead(2); // 后退两个以确定上一个非终结符的位置
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RPARENT, iterator.next().getLine()));
        this.rightParent = null;
    }
}
