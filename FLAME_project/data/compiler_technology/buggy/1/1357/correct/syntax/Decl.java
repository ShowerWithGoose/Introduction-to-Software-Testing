package syntax;

import lexer.LexType;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class Decl {
    public static final LexType[] FIRST = Stream.concat(Arrays.stream(ConstDecl.FIRST), Arrays.stream(VarDecl.FIRST)).toArray(LexType[]::new);

    private final ConstDecl constDecl;
    private final VarDecl varDecl;

    public Decl(ConstDecl constDecl) {
        this.constDecl = Objects.requireNonNull(constDecl);
        this.varDecl = null;
//        Constant.good.append("<Decl>\n");
    }

    public Decl(VarDecl varDecl) {
        this.constDecl = null;
        this.varDecl = Objects.requireNonNull(varDecl);
//        Constant.good.append("<Decl>\n");
    }
}
