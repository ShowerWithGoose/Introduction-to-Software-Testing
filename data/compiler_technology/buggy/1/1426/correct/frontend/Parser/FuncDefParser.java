package frontend.Parser;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Func.FuncFParams;
import frontend.Parser.Func.FuncFParamsParser;
import frontend.Parser.Func.FuncType;
import frontend.Parser.Func.FuncTypeParser;
import frontend.Parser.Stmt.Block;
import frontend.Parser.Stmt.BlockParser;
import frontend.Parser.solid.Ident;
import frontend.Parser.solid.IdentParser;

// FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
public class FuncDefParser {
    private TokenListReader reader;
    private FuncType funcType ;
    private Ident ident;
    private Token lparent;
    private FuncFParams funcFParams = null;
    private Token rparent;
    private Block block;

    public FuncDefParser(TokenListReader reader) {
        this.reader = reader;
    }
    public FuncDef parseFuncDef() {
        FuncTypeParser funcTypeParser = new FuncTypeParser(this.reader);
        this.funcType = funcTypeParser.parseFuncType();
        IdentParser identParser = new IdentParser(this.reader);
        this.ident = identParser.parseIdent();
        this.lparent = this.reader.getnextToken();
        this.rparent = this.reader.getnextToken();
        if (!this.rparent.getType().equals(TokenType.RPARENT)) {
            // 两种情况：有参数，或者缺少右小括号错误
            if(this.rparent.getType().equals(TokenType.LBRACE)) {
                // error!
                ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
                this.reader.backward(1);
                BlockParser blockParser = new BlockParser(this.reader);
                this.block = blockParser.parseBlock();
                return new FuncDef(this.funcType, this.ident, this.lparent,
                        this.rparent, this.block);
            }
            else{
                if(this.rparent.getType().equals(TokenType.INTTK)||this.rparent.getType().equals(TokenType.CHARTK)) {
                    this.reader.backward(1);
                    FuncFParamsParser funcFParamsParser = new FuncFParamsParser(this.reader);
                    this.funcFParams = funcFParamsParser.parseFuncFParams();
                    this.rparent = this.reader.getnextToken();
                    if(!this.rparent.getType().equals(TokenType.RPARENT)) {
                        // error!
                        ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
                        this.reader.backward(1);
                    }
                    BlockParser blockParser = new BlockParser(this.reader);
                    this.block = blockParser.parseBlock();
                    return new FuncDef(this.funcType, this.ident, this.lparent,
                            this.funcFParams, this.rparent, this.block);
                }
                else{
                    ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
                    this.reader.backward(1);
                    BlockParser blockParser = new BlockParser(this.reader);
                    this.block = blockParser.parseBlock();
                    return new FuncDef(this.funcType, this.ident, this.lparent,
                             this.rparent, this.block);
                }
            }
        } else {
            BlockParser blockParser = new BlockParser(this.reader);
            this.block = blockParser.parseBlock();
            return new FuncDef(this.funcType, this.ident, this.lparent,
                    this.rparent, this.block);
        }
    }

}
