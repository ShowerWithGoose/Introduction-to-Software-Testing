package nodes;

public interface SyntaxNode extends Node {
    public String syntaxPrinter();

    public boolean parse();
}
