#include <stdio.h>
#include <stdlib.h>
#include <memory.h>



int main()
{   
    unsigned int seed;
    FILE *enflag = fopen("flag.enc", "rb");

    fseek(enflag,0,SEEK_END);
    long size = ftell(enflag);
    fseek(enflag,0,SEEK_SET);
    unsigned char *flag = malloc(size);
    fread(flag,1,size,enflag);
    fclose(enflag);
    memcpy(&seed,flag,4);
    printf("%d\n", seed);
    srand(seed);

    for (int i = 4; i < (long)size; i++)
    {
        int en1 = rand();
        int en2 = rand();
        en2 = en2 & 7;
        flag[i] = flag[i] >> en2 | flag[i] << 8 - en2;
        flag[i] = en1 ^ flag[i];
        
        printf("%c", flag[i]);
    }

}
