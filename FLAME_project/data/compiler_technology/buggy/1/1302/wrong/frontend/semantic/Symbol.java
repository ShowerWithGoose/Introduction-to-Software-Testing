package frontend.semantic;

public class Symbol {
    protected final int tableId; 	// 当前单词所在的符号表编号。
    protected final String name; 	// 当前单词所对应的字符串。
    protected final BType btype; 	// 0 -> int, 1 -> char
    protected final boolean isConst;		// 0 -> const, 1 -> var

    public Symbol(int tableId, String name, BType btype, boolean isConst) {
        this.tableId = tableId;
        this.name = name;
        this.btype = btype;
        this.isConst = isConst;
    }

    public int getTableId() {
        return tableId;
    }

    public String getName() {
        return name;
    }

    public BType getBType() {
        return btype;
    }

    public boolean isConst() {
        return isConst;
    }

    public Type getType() {
        return null;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(tableId).append(" ").append(name).append(" ");
        if (isConst) {
            sb.append("Const");
        }
        if (btype == BType.CHAR) {
            sb.append("Char");
        } else if (btype == BType.INT) {
            sb.append("Int");
        }
        if (this instanceof FuncSymbol) {
            if (btype == BType.VOID) {
                sb.append("Void");
            }
            sb.append("Func");
        } else if (this instanceof ArraySymbol) {
            sb.append("Array");
        }
        return sb.toString();
    }
}
