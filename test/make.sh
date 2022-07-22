CC="gcc"
CFLAGS="-Wall"
CLIBS="-lpthread -g3"
OUT="teste2"
OBJS="PeriodicFn.c teste.c"

$CC $CFLAGS $CLIBS -o $OUT $OBJS
