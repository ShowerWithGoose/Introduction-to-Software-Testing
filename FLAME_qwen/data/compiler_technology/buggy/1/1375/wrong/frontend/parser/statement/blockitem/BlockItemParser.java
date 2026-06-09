package frontend.parser.statement.blockitem;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.DeclParser;
import frontend.parser.statement.stmt.StmtParser;

import java.util.ArrayList;

public class BlockItemParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* BlockItemEle */
    public BlockItemEle blockItemEle = null;
    public BlockItemParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public BlockItem parseBlockItem(){
        Token token = this.iterator.readNextToken();
        if (token.type.equals(TokenType.CONSTTK) ||
                token.type.equals(TokenType.INTTK) ||
                token.type.equals(TokenType.CHARTK)) {
            this.iterator.unReadToken(1);
            DeclParser declParser = new DeclParser(this.iterator,this.error_tokens);
            this.blockItemEle = declParser.parseDecl();
        } else {
            this.iterator.unReadToken(1);
            StmtParser stmtParser = new StmtParser(this.iterator,this.error_tokens);
            this.blockItemEle = stmtParser.parseStmt();
        }
        BlockItem blockItem = new BlockItem(this.blockItemEle);
        return blockItem;
    }
}
