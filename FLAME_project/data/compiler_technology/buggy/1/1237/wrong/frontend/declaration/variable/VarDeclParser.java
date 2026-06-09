package frontend.declaration.variable;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.declaration.BType;
import frontend.declaration.BTypeParser;
import frontend.declaration.variable.vardef.VarDef;
import frontend.declaration.variable.vardef.VarDefParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

import java.util.ArrayList;

/**
 * 解析器: VarDecl (变量声明)
 * 对应文法: VarDecl → BType VarDef { ',' VarDef } ';'
 *
 * 解析变量声明语法结构。
 *
 * 变量声明表示由基本类型 (BType) 和一个或多个变量定义 (VarDef) 组成的语句。
 * 变量定义可以通过逗号 (',') 分隔，并以分号 (';') 结束。
 */
public class VarDeclParser {
    private final TokenListIterator iterator;
    private BType btype = null; // 基本类型
    private VarDef first = null; // 第一个变量定义
    private final ArrayList<Token> commas = new ArrayList<>(); // 逗号
    private final ArrayList<VarDef> varDefs = new ArrayList<>(); // 其余的变量定义
    private Token semicn; // ';' 结尾

    public VarDeclParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public VarDecl parseVarDecl() {
        // 解析 BType
        BTypeParser btypeparser = new BTypeParser(this.iterator);
        this.btype = btypeparser.parseBtype();

        // 解析第一个 VarDef
        VarDefParser varDefParser = new VarDefParser(this.iterator);
        this.first = varDefParser.parseVarDef();

        // 解析后续的 VarDef (如果存在)
        Token token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) { // ','
            this.commas.add(token);
            VarDefParser varDefParser2 = new VarDefParser(this.iterator);
            this.varDefs.add(varDefParser2.parseVarDef());
            token = this.iterator.readNextToken();
        }

        // 处理缺失分号的错误 (i 类错误)
        this.semicn = token;
        if (!this.semicn.getType().equals(TokenType.SEMICN)) {
            // 回退两个 Token 获取前一个非终结符的行号
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);
            ErrorTable.addError(error);
        }

        // 返回解析后的 VarDecl 对象
        return new VarDecl(this.btype, this.first, this.commas, this.varDefs, this.semicn);
    }
}
