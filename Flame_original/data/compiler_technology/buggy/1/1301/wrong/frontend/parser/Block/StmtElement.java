package frontend.parser.Block;

public interface StmtElement {
    int parse(); //return error num

    String toSyntaxTree();
}
