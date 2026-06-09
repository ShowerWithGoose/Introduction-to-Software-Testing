package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.statement.Block;
import frontend.parser.statement.BlockParser;

import java.util.ArrayList;

public class MainFuncDefParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* MainFuncDef Attributes */
    public Token intTk; // 'int'
    public Token mainTk; // 'main'
    public Token leftParent; // '('
    public Token rightParent; // ')'
    public Block block;

    public MainFuncDefParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public MainFuncDef parseMainFuncDef() {
        this.intTk = this.iterator.readNextToken();
        this.mainTk = this.iterator.readNextToken();
        this.leftParent = this.iterator.readNextToken();

        Token token = this.iterator.readNextToken();
        this.iterator.unReadToken(1);
        if(token.type.equals(TokenType.RPARENT)){
           this.rightParent = this.iterator.readNextToken();
        }else{
            this.rightParent=new Token(TokenType.RPARENT,this.leftParent.linenum,")");
            this.error_tokens.add(new Token(TokenType.RPARENT,this.leftParent.linenum,"j"));
        }
        BlockParser blockParser = new BlockParser(this.iterator,this.error_tokens);
        this.block = blockParser.parseBlock();
        MainFuncDef mainFuncDef = new MainFuncDef(this.intTk, this.mainTk,
                this.leftParent, this.rightParent, this.block);
        return mainFuncDef;
    }
}
