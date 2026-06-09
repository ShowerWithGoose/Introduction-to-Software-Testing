package frontend.SyntaxUnits.StmtUnits;


public class ContinueStmt implements StmtUnit{
    public ContinueStmt() {

    }

    @Override
    public String toPrint() {
        return "CONTINUETK" + " continue" +  "\n" + "SEMICN" + " ;" +  "\n";
    }
}
