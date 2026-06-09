package frontend.parser.declaration.variable;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.BTypeParser;
import frontend.parser.declaration.variable.vardef.VarDef;
import frontend.parser.declaration.variable.vardef.VarDefParser;

import java.util.ArrayList;

/**
 * VarDeclParser 变量声明解析器类
 * <VarDecl> -> <BType> <VarDef> { ',' <VarDef> } ';'
 */
public class VarDeclParser {
    private TokenListIterator iterator;
    /* VarDecl Attributes */
    private BType btype = null;
    private VarDef first = null;
    private ArrayList<Token> commas = new ArrayList<>(); // ','
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private Token semicn; // ';'

    public VarDeclParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public VarDecl parseVarDecl() {
        this.commas = new ArrayList<>();
        this.varDefs = new ArrayList<>();
        BTypeParser btypeparser = new BTypeParser(this.iterator);
        this.btype = btypeparser.parseBtype();
        VarDefParser varDefParser = new VarDefParser(this.iterator);
        this.first = varDefParser.parseVarDef();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.COMMA)) { // ','
            this.commas.add(token);
            this.varDefs.add(varDefParser.parseVarDef());
            token = this.iterator.next();
        }
        /* should be ';' */
        if (token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn = token;
        }else {
            System.out.println("ERROR : EXPECT SEMICN");
            handleIError();
        }
        VarDecl varDecl = new VarDecl(this.btype, this.first,
                this.commas, this.varDefs, this.semicn);
        return varDecl;
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
