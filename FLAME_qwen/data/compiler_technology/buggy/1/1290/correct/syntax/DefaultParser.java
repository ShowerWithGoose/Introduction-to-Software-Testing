package syntax;

import ast.AbstractSyntaxTree;
import error.Logger;
import lexical.Lexer;

public class DefaultParser implements Parser {

    private final AbstractSyntaxTree tree;

    public DefaultParser(Lexer lexer, Logger logger) {
        tree = new AbstractSyntaxTree(lexer, logger);
    }

    /**
     * @return
     * @throws Exception
     */
    @Override
    public AbstractSyntaxTree parse() throws Exception {
        tree.parse();
        return tree;
    }
}
