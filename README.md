# simplinhoOS

Este é um projeto educacional de um kernel básico escrito em C e Assembly para arquitetura x86.

## Recursos

- Boot em modo protegido compatível com Multiboot (pode ser iniciado pelo GRUB ou QEMU)
- Manipulação direta da tela pela memória de vídeo (VGA)

## Estrutura dos Arquivos

- `kernel.c` — Código principal do kernel em C, imprime algo na tela assim que é iniciado.
- `loader.s` — Código Assembly para cabeçalho Multiboot. Inicia a pilha e chama o kernel.
- `linker.ld` — Indica o layout de memória para o kernel.
- `Makefile` — Automatiza a compilação com o comando "make".

## Para testar

Compilar:
```bash
    make
```

Executar:
```bash
    qemu-system-i386 -kernel simplinho-os.bin
```
