TARGET=simplinho-os.bin

GNU=as
CXX=gcc

DEBUG=-g
OPT=-O1
WARN=-Wall -Werror

LD=ld

CXXFLAGS = $(DEBUG) $(OPT) $(WARN)
CXXFLAGS = -g -O1 -Wall -Werror -w -m32 -nostdlib -fno-builtin -fno-leading-underscore

ASFLAGS = --32
LDFLAGS = -melf_i386

objs = loader.o kernel.o

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.s
	$(GNU) $(ASFLAGS) $< -o $@

$(TARGET): linker.ld $(objs)
	$(LD) $(LDFLAGS) -T $< -o $@ $(objs)

clean:
	rm -f $(objs) $(TARGET)