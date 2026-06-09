package error;

public class CompilerError {
    private int lineno;
    private CompilerErrorType compilerErrorType;

    public CompilerError(int lineno, CompilerErrorType compilerErrorType) {
        this.lineno = lineno;
        this.compilerErrorType = compilerErrorType;
    }

    @Override
    public String toString() {
        return lineno + " " + compilerErrorType;
    }
}
