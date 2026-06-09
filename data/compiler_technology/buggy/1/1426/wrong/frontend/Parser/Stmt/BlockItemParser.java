package frontend.Parser.Stmt;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Decl.DeclParser;

public class BlockItemParser {
    private TokenListReader reader;
    private BlockItemInf blockItemInf = null;


    public BlockItemParser(TokenListReader reader) {
        this.reader = reader;
    }

    public BlockItem parseBlockItem() {
        Token token = this.reader.getnextToken();
        if (token.getType().equals(TokenType.CONSTTK) || token.getType().equals(TokenType.INTTK) || token.getType().equals(TokenType.CHARTK)) {
            this.reader.backward(1);
            DeclParser declParser = new DeclParser(this.reader);
            this.blockItemInf = declParser.parseDecl();
        } else {
            this.reader.backward(1);
            StmtParser stmtParser = new StmtParser(this.reader);
            this.blockItemInf = stmtParser.parseStmt();
        }
        BlockItem blockItem = new BlockItem(this.blockItemInf);
        return blockItem;
    }


}
