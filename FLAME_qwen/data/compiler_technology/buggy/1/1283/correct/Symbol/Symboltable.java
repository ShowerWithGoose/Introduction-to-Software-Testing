package Symbol;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * <p>Project: Compiler - Symboltable
 * <p>Powered by berry On 2024-10-12
 *
 * @author
 * @version 1.0
 */
public class Symboltable {
    public List<Symbol> symbolMap=new ArrayList<>();
    public int scope;//作用域
    public boolean isFunc;
    public String funcType;
    public Symboltable(List<Symbol> symbolMap,int scope,boolean isFunc,String funcType){
        this.symbolMap=symbolMap;
        this.scope=scope;
        this.isFunc=isFunc;
        this.funcType=funcType;
    }
}
