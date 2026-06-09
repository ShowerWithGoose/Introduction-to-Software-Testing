package frontend.Parser;

import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.Stmt.Block;
import frontend.Parser.Stmt.BlockParser;
import frontend.TokenType;

public class MainFuncDefParser {
    private TokenListReader reader;
    private Token intTk; // 'int'
    private Token mainTk; // 'main'
    private Token lparent;
    private Token rparent;
    private Block block;

    public MainFuncDefParser(TokenListReader reader) {
        this.reader = reader;
    }

    public MainFuncDef parseMainFuncDef() {
        this.intTk = this.reader.getnextToken();
        this.mainTk = this.reader.getnextToken();
        this.lparent = this.reader.getnextToken();
        this.rparent = this.reader.getnextToken();
        // error!
        if(!this.rparent.getType().equals(TokenType.RPARENT))
        {
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"j");
            this.reader.backward(1);
        }
        BlockParser blockParser = new BlockParser(this.reader);
        this.block = blockParser.parseBlock();
        MainFuncDef mainFuncDef = new MainFuncDef(this.intTk, this.mainTk, this.lparent, this.rparent, this.block);
        return mainFuncDef;
    }


}
