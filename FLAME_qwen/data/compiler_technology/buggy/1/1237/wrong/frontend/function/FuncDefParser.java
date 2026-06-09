package frontend.function;

import error.ErrorTable;
import error.ErrorType;
import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.function.FuncFParamsParser;
import frontend.function.functype.FuncType;
import frontend.function.functype.FuncTypeParser;
import frontend.statement.Block;
import frontend.statement.BlockParser;
import frontend.terminal.Ident;
import frontend.terminal.IdentParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;
/**
 * 解析器: FuncDef (函数定义)
 * 对应文法: FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
 *
 * 解析函数定义，包括函数类型、标识符、参数列表和函数体。
 */
public class FuncDefParser {
    private final TokenListIterator iterator;

    public FuncDefParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析函数定义。
     * @return 解析后的 FuncDef 对象
     */
    public FuncDef parseFuncDef() {
        // 解析函数类型
        FuncTypeParser funcTypeParser = new FuncTypeParser(this.iterator);
        FuncType funcType = funcTypeParser.parseFuncType();

        // 解析标识符
        IdentParser identParser = new IdentParser(this.iterator);
        Ident ident = identParser.parseIdent();

        // 解析 '('
        Token leftParent = this.iterator.readNextToken();
        if (leftParent.getType() != TokenType.LPARENT) {
            System.err.println("ERROR: Expected '(' after function identifier, but found: " + leftParent);
        }

        Token rightParent = this.iterator.readNextToken();//预读


        if(rightParent.getType().equals(TokenType.LBRACE)){ // fuc({ ->无参数缺失
            //j
            if (!rightParent.getType().equals(TokenType.RPARENT)) {
                this.iterator.unReadToken(2);
                Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                        ErrorType.MISSING_R_PARENT);
                ErrorTable.addError(error);
            }
            rightParent = new Token(TokenType.RPARENT, leftParent.getLineIndex(), ")");
        }

        // 解析可能存在的参数列表
        FuncFParams funcFParams = null;
        if (rightParent.getType() != TokenType.RPARENT) {
            this.iterator.unReadToken(1);
            FuncFParamsParser funcFParamsParser = new FuncFParamsParser(this.iterator);
            funcFParams = funcFParamsParser.parseFuncFParams();
            rightParent = this.iterator.readNextToken();

            //j
            if (!rightParent.getType().equals(TokenType.RPARENT)) {
                this.iterator.unReadToken(2);
                Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                        ErrorType.MISSING_R_PARENT);
                ErrorTable.addError(error);
            }

        }


        // 解析函数体块
        BlockParser blockParser = new BlockParser(this.iterator);
        Block block = blockParser.parseBlock();

        // 构造并返回 FuncDef 对象
        return new FuncDef(funcType, ident, leftParent, funcFParams, rightParent, block);
    }
}
