#include "numseq.h"

int (*seq_func[seq_num])(int) = {f1,f2,f3};

int f1(int a)
{
    return 1;
}

int f2(int a)
{
    return 2;
}

int f3(int a)
{
    return 3;
}
