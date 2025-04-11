#include <imago2.h>
#include <stdio.h>

#define MESSAGE_SIZE 256

int main(int argc, char *argv[])
{
    int width, height;
    char msg[MESSAGE_SIZE];

    scanf("%s", msg);

    unsigned char *pixels = img_load_pixels(argv[1], &width, &height, IMG_FMT_RGBA32);

    printf("Width: %i\n", width);
    printf("Height: %i\n", height);

    img_save_pixels(argv[2], pixels, width, height, IMG_FMT_RGBA32);

    img_free_pixels(pixels);

    return 0;
}
