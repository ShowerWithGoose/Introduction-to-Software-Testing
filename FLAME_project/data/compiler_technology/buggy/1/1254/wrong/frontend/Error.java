package frontend;

public class Error implements Comparable{
    public enum ErrorType{
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m;

        public String toString() {
            return this.name();
        }
    }

    ErrorType errorType;
    int lineno;

    public Error(ErrorType errorType, int lineno) {
        this.errorType = errorType;
        this.lineno = lineno;
    }

    public String toString() {
        return lineno + " " + errorType.toString() + "\n";
    }

    @Override
    public int compareTo(Object o) {
        Error e = (Error) o;
        if (this.lineno > e.lineno) {
            return 1;
        } else {
            return -1;
        }
    }
}
