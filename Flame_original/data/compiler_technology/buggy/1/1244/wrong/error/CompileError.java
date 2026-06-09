package error;

import java.util.ArrayList;

public class CompileError implements Comparable<CompileError>{
    private final CompileErrorType type;
    private final int lineno;

    private static final ArrayList<CompileError> compileErrors = new ArrayList<>();

    public CompileError(CompileErrorType type, int lineno) {
        this.type = type;
        this.lineno = lineno;
    }

    @Override
    public String toString() {
        return lineno + " " + type.toString();
    }

    public static ArrayList<CompileError> getCompileErrors() {
        return compileErrors;
    }

    @Override
    public int compareTo(CompileError o) {
        return this.lineno - o.lineno;
    }
}
