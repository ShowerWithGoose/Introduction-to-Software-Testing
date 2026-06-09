package Parser;
import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Stmt.Stmt;
import Parser.Stmt.StmtParser;

/**
 * @Description:
 * @date 2024/10/13
 */
public class BlockItemParser {
    private TokenListIterator iterator;
    private int flag=0;
    private Decl decl;
    private Stmt stmt;

    public BlockItemParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public BlockItem blockItemParse()
    {
        Token first=iterator.readNextToken();
        iterator.unReadToken(1);
        if(first.getValue().equals("int")||first.getValue().equals("char")||first.getValue().equals("const"))
        {
            this.flag=1;
            DeclParser declParser = new DeclParser(this.iterator);
            this.decl = declParser.declParse();
        }else {
            this.flag=2;
            StmtParser stmtParser=new StmtParser(iterator);
            this.stmt=stmtParser.parseStmt();
        }
        return new BlockItem(flag,decl,stmt);
    }
}
