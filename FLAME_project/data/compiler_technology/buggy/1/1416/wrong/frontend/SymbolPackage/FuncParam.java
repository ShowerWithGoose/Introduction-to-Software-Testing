package frontend.SymbolPackage;

public class FuncParam {
    private String btype;
    private String name;
    private int dimension;//0->var, 1->array

    public FuncParam(String btype, String name, int dimension) {
        this.btype = btype;
        this.name = name;
        this.dimension = dimension;
    }

    public int getDimension() {
        return dimension;
    }

    public String getBtype() {
        return btype;
    }

    public String getName() {
        return name;
    }
}
