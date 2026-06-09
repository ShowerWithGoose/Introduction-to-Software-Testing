package error;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:41
 */
public class error {
    public enum wrongType{
        a,b,c,d,e,f,g,h,i,j,k,l,m,none
    }
    wrongType wType;
    int lineno;
    public error(wrongType type,int lineno){
        this.lineno=lineno;
        this.wType=type;
    }

    public int getLineno() {
        return lineno;
    }

    @Override
    public String toString() {
        return this.lineno+" "+this.wType;
    }

}
