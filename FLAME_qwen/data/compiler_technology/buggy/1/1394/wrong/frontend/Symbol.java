package frontend;

public class Symbol {
    private int id;
    private int tableId;
    private Token token;
    private String type;
    private String BType;
    private boolean isConst;

    public String getConstOrVar(){
        if(isConst)
            return "const";
        else
            return "var";
    }
}
