package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.FuncFParamsParser;
import frontend.parser.function.functype.FuncType;
import frontend.parser.function.functype.FuncTypeParser;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class FuncDefParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* FuncDef Attributes */
    public FuncType funcType = null;
    public Ident ident = null;
    public Token leftParent = null; // '('
    public FuncFParams funcFParams = null; // MAY exist
    public Token rightParent = null; // ')'
    public Block block = null;
    public FuncDef funcDef = null;

    public FuncDefParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public FuncDef parseFuncDef() {
        FuncTypeParser funcTypeParser = new FuncTypeParser(this.iterator,this.error_tokens);
        this.funcType = funcTypeParser.parseFuncType();
        IdentParser identParser = new IdentParser(this.iterator,this.error_tokens);
        this.ident = identParser.parseIdent();
        this.leftParent = this.iterator.readNextToken();
        Token token  = this.iterator.readNextToken();
        if (!token.type.equals(TokenType.RPARENT)) {
            this.iterator.unReadToken(1);
            if(token.type.equals(TokenType.CHARTK) || token.type.equals(TokenType.INTTK)) {
                FuncFParamsParser funcFParamsParser = new FuncFParamsParser(this.iterator,this.error_tokens);
                this.funcFParams = funcFParamsParser.parseFuncFParams();
                token = this.iterator.readNextToken();
                this.iterator.unReadToken(1);
                if(token.type.equals(TokenType.RPARENT)) {
                    this.rightParent=this.iterator.readNextToken();
                }else if(token.type.equals(TokenType.LBRACE)){
                    this.rightParent = new Token(TokenType.RPARENT,this.funcFParams.my_line_num(),")");
                    this.error_tokens.add(new Token(TokenType.RPARENT,this.funcFParams.my_line_num(),"j"));
                }

            }else if(token.type.equals(TokenType.LBRACE)){
                this.rightParent = new Token(TokenType.RPARENT,this.leftParent.linenum,")");
                this.error_tokens.add(new Token(TokenType.RPARENT,this.leftParent.linenum,"j"));
            }
            BlockParser blockParser = new BlockParser(this.iterator,this.error_tokens);
            this.block = blockParser.parseBlock();
            this.funcDef = new FuncDef(this.funcType, this.ident, this.leftParent,
                    this.funcFParams, this.rightParent, this.block);
        } else {
            this.rightParent=token;
            BlockParser blockParser = new BlockParser(this.iterator,this.error_tokens);
            this.block = blockParser.parseBlock();
            this.funcDef = new FuncDef(this.funcType, this.ident, this.leftParent,
                    this.rightParent, this.block);
        }
        return funcDef;
    }
}
