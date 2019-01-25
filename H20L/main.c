#include <stdio.h>
#include <stdlib.h>

#define BOTTLE_L 1.5
#define PACKS_NUM 6
#define PACK_BTL_FREE 1
#define PAL_PACKS 50
#define PAL_PACKS_FREE 5

#define PACKS (PACKS_NUM-PACK_BTL_FREE)
#define PALETTES ((PAL_PACKS-PAL_PACKS_FREE)*PACKS_NUM)

int main(void)
{
    printf("Ce programme calcule le prix au litre d une bouteille d eau, le prix d un pack et le prix d une palette de packs\nPrix d une bouteille de %.1fL ? ",BOTTLE_L);
    float price;
    scanf("%f",&price);
    printf("Prix au L = %.2f\nPrix pack = %.2f\nPrix palette = %.2f",price/BOTTLE_L,PACKS*price,PALETTES*price);
    return EXIT_SUCCESS;
}
