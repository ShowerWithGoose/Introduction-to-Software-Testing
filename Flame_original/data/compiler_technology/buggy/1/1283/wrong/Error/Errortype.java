package Error;

/**
 * <p>Project: Compiler - Errortype
 * <p>Powered by berry On 2024-10-11
 *
 * @author
 * @version 1.0
 */
public class Errortype implements Comparable<Errortype>{
    public int lineno;
    public char type;
    public Errortype(int lineno,char type){
        this.lineno=lineno;
        this.type=type;
    }
    @Override
    public int compareTo(Errortype o) {
        if (lineno == o.lineno) {
            return 0;
        } else if (lineno < o.lineno) {
            return -1;
        }
        return 1;
    }

    @Override
    public String toString() {
        return lineno + " " + type + "\n";
    }
}
