package frontend.SyntaxUnits.StmtUnits;


import frontend.SyntaxUnits.Exps.LVal;

public class getIntStmt implements StmtUnit{
    private final LVal lVal;

    public getIntStmt(LVal lVal) {
        this.lVal = lVal;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(lVal.toPrint());
        stringBuilder.append("ASSIGN" + " =" +  "\n");
        stringBuilder.append("GETINTTK" + " getint" +  "\n");
        stringBuilder.append("LPARENT" + " (" +  "\n");
        stringBuilder.append("RPARENT" + " )" +  "\n");
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        return stringBuilder.toString();
    }
}
