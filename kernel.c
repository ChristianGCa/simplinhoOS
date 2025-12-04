// Compilar: g++ kernel.cpp

void print(char* str) {
    char *video = (char*)0xB8000;
    const char *msg = "Hello world!";
    for (int i = 0; msg[1] != 0; i++) {
        video[i * 2] = msg[i];
        video[i * 2 + 1] = 0x0F;
    }
    while (1) {}
}

void kmain(void) {
    print("Hello, World!");
    while (1);
}