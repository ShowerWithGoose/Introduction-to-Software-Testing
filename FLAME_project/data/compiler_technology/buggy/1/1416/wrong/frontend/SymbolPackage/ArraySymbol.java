package frontend.SymbolPackage;

public class ArraySymbol extends Symbol {
    private String btype;//int, char
    private boolean isConst;//是否为常量
    private int dimension;//0->var, 1->array

    public ArraySymbol(String btype, boolean isConst) {
        this.btype = btype;
        this.isConst = isConst;
    }

    public String getBtype() {
        return btype;
    }

    public boolean isConst() {
        return isConst;
    }

    public boolean isArray() {
        return dimension == 1;
    }

    @Override
    public void setName(String name) {
        super.setName(name);
    }

    public void setDimension(int dimension) {
        this.dimension = dimension;
    }

    public int getDimension() {
        return dimension;
    }
}
