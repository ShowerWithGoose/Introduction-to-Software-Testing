package Symbol;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Project: Compiler - Symbol
 * <p>Powered by berry On 2024-10-12
 *
 * @author
 * @version 1.0
 */
public class Symbol {
    public enum Type {
        ConstChar,
        ConstInt,
        ConstCharArray,
        ConstIntArray,
        Char,
        Int,
        CharArray,
        IntArray,
        VoidFunc,
        CharFunc,
        IntFunc
    }
    public Type type;
    public String name;
    public String stringType;//int,char,void
    public List<FuncParam> funcParamList;
    public Symbol(Type type,String name,String stringType,List<FuncParam> funcParamList){
        this.type=type;
        this.name=name;
        this.stringType=stringType;
        this.funcParamList=funcParamList;
    }
}
