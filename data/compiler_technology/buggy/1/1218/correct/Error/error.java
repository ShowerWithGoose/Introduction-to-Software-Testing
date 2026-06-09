package Error;

public class error {
    char type;
    int lineno;
    public error(char type, int lineno){
        this.type = type;
        this.lineno = lineno;
    }
    public error(){}

    @Override
    public String toString(){
        StringBuffer sbf = new StringBuffer();
        sbf.append(this.lineno);
        sbf.append(' ');
        sbf.append(this.type);
        sbf.append('\n');
        return sbf.toString();
    }

    public int getLineno(){
        return this.lineno;
    }
}
