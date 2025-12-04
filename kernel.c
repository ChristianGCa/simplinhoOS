// Compilar: g++ kernel.cpp


#define VIDEO_MEMORY 0xB8000
#define WIDTH 80
#define HEIGHT 25

void clear() {
    char *video = (char *)VIDEO_MEMORY;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        video[i * 2] = ' ';
        video[i * 2 + 1] = 0x0F;
    }
}

void print(const char *str, int row) {
    char *video = (char *)VIDEO_MEMORY + row * WIDTH * 2;
    for (int i = 0; str[i] != 0 && i < WIDTH; i++) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x0F;
    }
}

void kmain(void) {
    clear();
    print("Hello, World!", 0);
    while (1) {};
}