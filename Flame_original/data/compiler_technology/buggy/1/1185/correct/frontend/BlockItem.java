package frontend;

public class BlockItem {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Decl decl = null;
    private Stmt stmt = null;
    private int type;//1:decl 2:stmt

    public BlockItem(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getBlockItem() {
        Token token = itaretor.getNext();
        if (token.getType().equals("CONSTTK") || token.getType().equals("INTTK") || token.getType().equals("CHARTK")) {
            itaretor.getPrevious(1);
            decl = new Decl(file,itaretor);
            decl.getDecl();
            type = 1;
        } else {
            itaretor.getPrevious(1);
            stmt = new Stmt(itaretor,file);
            stmt.getStmt();
            type = 2;
        }
    }

}
