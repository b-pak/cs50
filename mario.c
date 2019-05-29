#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
    if (height == 1){
        printf("#  #\n");
    }
    else if (height == 2){
        printf(" #  #\n");
        printf("##  ##\n");
    }
    else if (height == 3){
        printf("  #  #\n");
        printf(" ##  ##\n");
        printf("###  ###\n");
    }
    else if (height == 4){
        printf("   #  #\n");
        printf("  ##  ##\n");
        printf(" ###  ###\n");
        printf("####  ####\n");
    }
    else if (height == 5){
        printf("    #  #\n");
        printf("   ##  ##\n");
        printf("  ###  ###\n");
        printf(" ####  ####\n");
        printf("#####  #####\n");
    }
    else if (height == 6){
        printf("     #  #\n");
        printf("    ##  ##\n");
        printf("   ###  ###\n");
        printf("  ####  ####\n");
        printf(" #####  #####\n");
        printf("######  ######\n");
    }
    else if (height == 7){
        printf("      #  #\n");
        printf("     ##  ##\n");
        printf("    ###  ###\n");
        printf("   ####  ####\n");
        printf("  #####  #####\n");
        printf(" ######  ######\n");
        printf("#######  #######\n");
    }
    else if (height == 8){
        printf("       #  #\n");
        printf("      ##  ##\n");
        printf("     ###  ###\n");
        printf("    ####  ####\n");
        printf("   #####  #####\n");
        printf("  ######  ######\n");
        printf(" #######  #######\n");
        printf("########  ########\n");
    }
}
