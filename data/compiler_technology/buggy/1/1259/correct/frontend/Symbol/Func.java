package frontend.Symbol;

public class Func implements SymbolExtend
{
    public int paramSize;
    public MyType[] paramTypes;
    public MyType returnType;
    public Func(MyType returnType, MyType[] paramTypes){
        this.returnType = returnType;
        this.paramTypes = paramTypes;
        this.paramSize = paramTypes.length;
    }
}
