package frontend.parser.Decl;

import frontend.parser.Block.BlockItem;

public interface Decl {
    int parse(); //return error num

    String toSyntaxTree();
}
