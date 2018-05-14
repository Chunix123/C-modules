#include <stdio.h>
#include "b64.h"




int main()
{
    char *src = "Base 64 encode test!";
    char *en_str = b64_encode(src, sizeof(src));
    
    printf("%s\n", en_str);
    
    return 0;
}