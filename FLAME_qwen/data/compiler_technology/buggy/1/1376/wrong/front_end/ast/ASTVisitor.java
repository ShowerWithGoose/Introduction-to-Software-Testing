package front_end.ast;

import front_end.lexer.TokenType;

public class ASTVisitor {
    public static String astToString(ASTNode node) {
        if (node.getType() instanceof TokenType) {
            return node.getType().toString()+" "+node.getValue()+"\n";
        }
        StringBuilder sb = new StringBuilder();
        for (Object child : node.getChildren()) {
            if (child instanceof ASTNode) {
                sb.append(astToString((ASTNode) child));
            }
            else {
                sb.append(child.toString()).append(" ").append(getWordName((TokenType) child)).append("\n");
            }
        }
        if (node.getType() == NodeType.BlockItem || node.getType() == NodeType.Decl || node.getType() == NodeType.BType) {
            return sb.toString();
        }
        sb.append("<").append(node.getType().toString()).append(">").append("\n");
        return sb.toString();
    }

    public static String getWordName(TokenType nodeType) {
        if (nodeType == null) {
            return "";
        }
        return switch (nodeType) {
            // 标识符和关键字
            case IDENFR -> "Ident";
            case ELSETK -> "else";
            case VOIDTK -> "void";
            case SEMICN -> ";";
            case INTCON -> "IntConst";
            case NOT -> "!";
            case MULT -> "*";
            case COMMA -> ",";
            case STRCON -> "StringConst";
            case AND -> "&&";
            case DIV -> "/";
            case LPARENT -> "(";
            case CHRCON -> "CharConst";
            case OR -> "||";
            case MOD -> "%";
            case RPARENT -> ")";
            case MAINTK -> "main";
            case FORTK -> "for";
            case LSS -> "<";
            case LBRACK -> "[";
            case CONSTTK -> "const";
            case GETINTTK -> "getint";
            case LEQ -> "<=";
            case RBRACK -> "]";
            case INTTK -> "int";
            case GETCHARTK -> "getchar";
            case GRE -> ">";
            case LBRACE -> "{";
            case CHARTK -> "char";
            case PRINTFTK -> "printf";
            case GEQ -> ">=";
            case RBRACE -> "}";
            case BREAKTK -> "break";
            case RETURNTK -> "return";
            case EQL -> "==";
            case CONTINUETK -> "continue";
            case PLUS -> "+";
            case NEQ -> "!=";
            case IFTK -> "if";
            case MINU -> "-";
            case ASSIGN -> "=";
            default -> "";
        };
    }
}
