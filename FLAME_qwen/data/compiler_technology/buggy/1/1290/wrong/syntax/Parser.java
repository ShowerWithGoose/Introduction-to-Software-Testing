package syntax;

import ast.AbstractSyntaxTree;

public interface Parser {

    public AbstractSyntaxTree parse() throws Exception;
}
