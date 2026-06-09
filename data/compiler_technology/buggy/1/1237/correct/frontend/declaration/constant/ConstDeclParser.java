package frontend.declaration.constant;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.declaration.BType;
import frontend.declaration.BTypeParser;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

import java.util.ArrayList;

/**
 * 解析器: ConstDecl (常量声明)
 * 对应文法: ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
 *
 * 解析常量声明语法结构。
 *
 * 常量声明表示一组由 'const' 关键字开头的常量定义，它可能包含多个常量定义，
 * 每个常量定义通过逗号 (',') 分隔，最后以分号 (';') 结尾。
 */
public class ConstDeclParser {
    private TokenListIterator iterator;
    /* ConstDecl Attributes */
    private Token constTk = null; // 'const'
    private BType btype = null;
    private ConstDef first = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstDef> constDefs = new ArrayList<>();
    private Token semicn = null; // ';'

    public ConstDeclParser(TokenListIterator iterator) {
        this.iterator =  iterator;
    }

    public ConstDecl parseConstDecl() {
        this.commas = new ArrayList<>();
        this.constDefs = new ArrayList<>();
        Token token = this.iterator.readNextToken(); // SHOULD be CONST
        if (token.getType().equals(TokenType.CONSTTK)) {
            constTk = token;
        } else {
            System.out.println("ERROR : EXPECT CONSTTK");
        }
        BTypeParser btypeParser = new BTypeParser(this.iterator);
        btype = btypeParser.parseBtype();
        ConstDefParser constDefParser = new ConstDefParser(this.iterator);
        first = constDefParser.parseConstDef();
        token = this.iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            this.commas.add(token);
            ConstDefParser constDefParser2 = new ConstDefParser(this.iterator);
            this.constDefs.add(constDefParser2.parseConstDef());
            token = this.iterator.readNextToken();
        }
        /* 处理i类错误：缺失; */
        this.semicn = token;
        if (!this.semicn.getType().equals(TokenType.SEMICN)) {
            // 回退两个 Token，获取分号前的非终结符行号
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(),
                    ErrorType.MISSING_SEMICN);
            ErrorTable.addError(error);
        }

        ConstDecl constDecl = new ConstDecl(this.constTk, this.btype, this.first, this.commas, this.constDefs, this.semicn);
        return constDecl;
    }
}
