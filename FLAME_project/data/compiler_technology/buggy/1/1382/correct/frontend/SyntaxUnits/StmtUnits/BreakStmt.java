package frontend.SyntaxUnits.StmtUnits;


public class BreakStmt implements StmtUnit{
    public BreakStmt() {

    }

    @Override
    public String toPrint() {
        return "BREAKTK" + " break" +  "\n" + "SEMICN" + " ;" +  "\n";
    }
}
