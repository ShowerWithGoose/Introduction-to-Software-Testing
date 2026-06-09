package llvm_part;

public class IrType {
    public enum DataType {
        I1("i1"),
        I8("i8"),
        I32("i32"),
        VOID("void"),
        LABEL("label");
        private final String type;

        DataType(String type) {
            this.type = type;
        }

        @Override
        public String toString() {
            return type;
        }
    }

    private DataType dataType;

    public IrType(DataType dataType) {
        this.dataType = dataType;
    }

    @Override
    public String toString() {
        return dataType.toString();
    }
}
