package frontend.declaration.variable.vardef;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.declaration.variable.initval.InitVal;
import frontend.declaration.variable.initval.InitValParser;
import frontend.expression.ConstExp;
import frontend.expression.ConstExpParser;
import frontend.terminal.Ident;
import frontend.terminal.IdentParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

/**
 * 解析器: VarDef (变量定义)
 * 对应文法: VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
 *
 * 解析变量定义语法结构。
 *
 * 变量定义表示一个标识符 Ident 和可选的一维数组定义 [ '[' ConstExp ']' ]，
 * 并且还可以通过赋值符号 '=' 为变量初始化一个值 (InitVal)。
 */
public class VarDefParser {
    private final TokenListIterator iterator;
    private Ident ident = null; // 标识符
    private Token leftBrace = null; // 左括号 '['
    private ConstExp constExp = null; // 常量表达式 ConstExp
    private Token rightBrace = null; // 右括号 ']'
    private Token eq = null; // '='
    private InitVal initVal = null; // 初始化值 InitVal
    private VarDefEle varDefEle = null; // VarDef 的元素

    public VarDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public VarDef parseVarDef() {
        // 解析 Ident
        IdentParser identParser = new IdentParser(this.iterator);
        this.ident = identParser.parseIdent();

        // 解析可选的 '[' ConstExp ']'
        Token token = this.iterator.readNextToken();
        if (token.getType().equals(TokenType.LBRACK)) { // '['
            this.leftBrace = token;

            // 解析 ConstExp
            ConstExpParser expParser = new ConstExpParser(this.iterator);
            this.constExp = expParser.parseConstExp();

            // 解析 ']'
            token = this.iterator.readNextToken();
            if (!token.getType().equals(TokenType.RBRACK)) {
                // 处理 k 类错误：缺少右中括号 ']'
                this.iterator.unReadToken(2); // 回退两个 Token，获取前一个非终结符的行号
                Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_BRACKET);
                ErrorTable.addError(error);
            }
            this.rightBrace = token;

            // 继续解析可能的 '=' InitVal
            token = this.iterator.readNextToken();
        }

        // 解析可选的初始化值 '=' InitVal
        if (token.getType().equals(TokenType.ASSIGN)) { // '='
            this.eq = token;
            InitValParser initValParser = new InitValParser(this.iterator);
            this.initVal = initValParser.parseInitVal();
            this.varDefEle = new VarDefInit(this.ident, this.leftBrace, this.constExp, this.rightBrace, this.eq, this.initVal);
        } else {
            // 未初始化，退回最后一个非匹配的 token
            this.iterator.unReadToken(1);
            this.varDefEle = new VarDefNull(this.ident, this.leftBrace, this.constExp, this.rightBrace);
        }

        // 返回解析后的 VarDef 对象
        return new VarDef(this.varDefEle);
    }
}
