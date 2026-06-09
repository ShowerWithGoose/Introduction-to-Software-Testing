package parser_part.expression.unaryExpression;

import parser_part.Node;
import parser_part.expression.Computable;

/**
 * PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
 **/

public interface UnaryExpComponent extends Computable {
    int getArray();
}
