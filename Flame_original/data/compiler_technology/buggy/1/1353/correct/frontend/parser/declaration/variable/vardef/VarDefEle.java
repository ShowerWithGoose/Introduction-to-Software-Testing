package frontend.parser.declaration.variable.vardef;

import frontend.parser.SyntaxNode;

/**
 * <VarDef>子节点接口
 * <Ident> [ '[' <ConstExp> ']' ]
 * |
 * <Ident> [ '[' <ConstExp> ']' ] '=' <InitVal>
 */
public interface VarDefEle extends SyntaxNode {
}
