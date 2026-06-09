package frontend.Parser.SyntaxNode.UnaryExp;

import frontend.Parser.SyntaxNode.SyntaxNode;
/*
 UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
 */
public class UnaryExp implements SyntaxNode {
    protected final String name = "<UnaryExp>";
}
