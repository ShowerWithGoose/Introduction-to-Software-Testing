package frontend;

public class Error implements Comparable<Error>{
    private final String name;
    private final int line;

    public Error(String name, int line) {
        this.line = line;
        this.name = name;
    }

    @Override
    public String toString() {
        return line + " " + name;
    }

    public String getname() {
        return name;
    }

    @Override
    public int compareTo(Error o) {
        return Integer.compare(line, o.line);
    }
}
