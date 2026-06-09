package frontend.parser.declaration.constant;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;

import java.util.ArrayList;

/**
 * ConstDeclParser 常量声明解析器类
 * <ConstDecl> -> 'const' <BType> <ConstDef> { ',' <ConstDef> } ';'
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
        Token token = this.iterator.next(); // SHOULD be CONST
        /* MAY need handle error */
        if (token.getTokenType().equals(TokenType.CONSTTK)) {
            constTk = token;
        } else {
            System.out.println("ERROR : EXPECT CONSTTK");
        }
        BTypeParser btypeParser = new BTypeParser(this.iterator);
        btype = btypeParser.parseBtype();
        ConstDefParser constDefParser = new ConstDefParser(this.iterator);
        first = constDefParser.parseConstDef();
        token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.COMMA)) {
            /* is ',' */
            this.commas.add(token);
            constDefParser = new ConstDefParser(this.iterator);
            this.constDefs.add(constDefParser.parseConstDef());
            token = this.iterator.next();
        }
        /* token SHOULD be ';' */
        if (token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn = token;
        } else {
            System.out.println("ERROR : EXPECT SEMICN");
            handleIError();
        }
        ConstDecl constDecl = new ConstDecl(this.constTk, this.btype,
                this.first, this.commas, this.constDefs, this.semicn);
        return constDecl;
    }

    /**
     * i error
     * missing ';'
     */
    private void handleIError() {
        iterator.unRead(2); // 后退两个以确定上一个非终结符的位置
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_SEMICN, iterator.next().getLine()));
        this.semicn = null;
    }
}
