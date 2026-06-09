package syntax;

import lexer.LexType;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class BlockItem {
    public static final LexType[] FIRST = Stream.concat(
            Arrays.stream(Decl.FIRST), Arrays.stream(Stmt.FIRST)
    ).toArray(LexType[]::new);

    private final Decl decl;
    private final Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = Objects.requireNonNull(decl);
        this.stmt = null;
//        Constant.good.append("<BlockItem>\n");
    }

    public BlockItem(Stmt stmt) {
        this.decl = null;
        this.stmt = Objects.requireNonNull(stmt);
//        Constant.good.append("<BlockItem>\n");
    }
}
