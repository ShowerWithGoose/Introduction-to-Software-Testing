package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.DeclParser;
import frontend.parser.statement.StmtParser;

public class BlockItemParser {
    private TokenIterator iterator;
    private BlockItemUnit blockItemUnit;

    public BlockItemParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public BlockItem parseBlockItem() {
        //BlockItem → Decl | Stmt
        //Decl → ConstDecl | VarDecl
        //ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        //VarDecl → BType VarDef { ',' VarDef } ';'
        //BType → 'int' | 'char'
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.CONSTTK || t1.getType() == TokenType.INTTK
        || t1.getType() == TokenType.CHARTK) {
            //decl
            iterator.ungetToken(1);
            DeclParser parser = new DeclParser(iterator);
            blockItemUnit = parser.parseDecl();
        } else {
            //stmt
            iterator.ungetToken(1);
            StmtParser parser = new StmtParser(iterator);
            blockItemUnit = parser.parseStmt();
        }
        return new BlockItem(blockItemUnit);
    }
}
