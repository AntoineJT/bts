#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    somelabel:
        scanf("%d",&i);
        if (!i)
            goto eof;
    goto somelabel;
    eof:
    return 0;
}
