#include <imago2.h>
#include <stdio.h>
#include <string.h>

#define MESSAGE_SIZE 256

int main(int argc, char *argv[])
{
    int width, height;
    char msg[MESSAGE_SIZE];

    scanf("%s", msg);

    unsigned char *pixels = img_load_pixels(argv[1], &width, &height, IMG_FMT_RGBA32);

    printf("Width: %i\n", width);
    printf("Height: %i\n", height);

    int i, j;
    for (i = 0; i < strlen(msg); i++) {
        for (j = 7; j >= 0; j--) {
            if ((msg[i] >> j & 1) == 1)
                pixels[i * 8 + (7 - j)] |= 1;
            else
                pixels[i * 8 + (7 - j)] &= ~1;
        }
    }

    img_save_pixels(argv[2], pixels, width, height, IMG_FMT_RGBA32);

    img_free_pixels(pixels);

    return 0;
}
