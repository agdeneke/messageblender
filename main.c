#include <imago2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_SIZE 256

void encode_message(char *msg, unsigned char *pixels)
{
    int i, j;
    for (i = 0; i < strlen(msg); i++) {
        for (j = 7; j >= 0; j--) {
            if ((msg[i] >> j & 1) == 1)
                pixels[i * 8 + (7 - j)] |= 1;
            else
                pixels[i * 8 + (7 - j)] &= ~1;
        }
    }
}

void decode_message(char *msg, unsigned char *pixels)
{
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        msg[i] = 0;
        for (j = 7; j >= 0; j--)
            msg[i] |= (pixels[i * 8 + (7 - j)] & 1) << j;
    }
}

int main(int argc, char *argv[])
{
    int width, height;
    char msg[MESSAGE_SIZE];

    if (argc < 2) {
        printf("Usage: messageblender <input file> [-e output file]\n");
        exit(1);
    }

    unsigned char *pixels = img_load_pixels(argv[1], &width, &height, IMG_FMT_RGBA32);

    if (argc >= 4 && !strcmp(argv[2], "-e")) {
        fgets(msg, MESSAGE_SIZE, stdin);
        encode_message(msg, pixels);
        img_save_pixels(argv[3], pixels, width, height, IMG_FMT_RGBA32);
    } else {
        decode_message(msg, pixels);
        printf("Hidden Message: %s\n", msg);
    }

    img_free_pixels(pixels);

    return 0;
}
