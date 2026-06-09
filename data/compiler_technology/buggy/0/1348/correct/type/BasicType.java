package type;

public class BasicType {
    public String getName() {
        if(this instanceof CharType) {
            return "char";
        } else if(this instanceof IntType) {
            return "int";
        } else if(this instanceof PointerType) {
            return "pointer";
        } else if(this instanceof VoidType) {
            return "void";
        } else {
            throw new RuntimeException("未知类型");
        }
    }
}
