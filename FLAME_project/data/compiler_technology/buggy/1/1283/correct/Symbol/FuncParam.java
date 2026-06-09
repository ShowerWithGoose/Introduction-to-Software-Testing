package Symbol;

/**
 * <p>Project: Compiler - FuncParam
 * <p>Powered by berry On 2024-10-12
 *
 * @author
 * @version 1.0
 */
public class FuncParam {
    public String name;
    public boolean isArray;
    public String type;
    public FuncParam(String name,boolean isArray,String type){
        this.name=name;
        this.isArray=isArray;
        this.type=type;
    }
}
