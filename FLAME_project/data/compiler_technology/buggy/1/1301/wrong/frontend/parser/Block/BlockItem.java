package frontend.parser.Block;

public interface BlockItem {
    int parse(); //return error num

    String toSyntaxTree();
}
