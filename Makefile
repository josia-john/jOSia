BUILD_DIR = build

ASM_SRC =	boot/entry.s
ASM_DEPS =	$(wildcard	boot/realmode_lib/*.s	\
			)

ASM_BIN = ${BUILD_DIR}/entry.bin

C_SRC =		$(wildcard 	kernel/*.c				\
						kernel/lib/*.c			\
						kernel/interrupts/*.c	\
			)
C_HEADER = 	$(wildcard 	kernel/*.h				\
						kernel/lib/*.h			\
						kernel/interrupts/*.h	\
			)

C_OBJ =		${patsubst %.c, ${BUILD_DIR}/%.o, $(C_SRC)}
CC = 		i386-elf-gcc
CFLAGS =	-ffreestanding -c

LINKER_SCRIPT = kernel/linker.ld
LD =			ld
LDFLAGS =		-m elf_i386 -Ttext 0x7e00 -T ${LINKER_SCRIPT}
KERNEL_BIN = 	${BUILD_DIR}/kernel.bin

IMAGE =			${BUILD_DIR}/jOSia


all: ${IMAGE}

${IMAGE}: ${ASM_BIN} ${KERNEL_BIN}
	mkdir -p ${BUILD_DIR}
	cat $(ASM_BIN) > $(IMAGE)
	cat $(KERNEL_BIN) >> $(IMAGE)

${ASM_BIN}: ${ASM_SRC} ${ASM_DEPS}
	mkdir -p ${BUILD_DIR}
	nasm -f bin $(ASM_SRC) -o $(ASM_BIN)

${KERNEL_BIN}: ${C_OBJ}
	${LD} ${LDFLAGS} ${C_OBJ} -o ${KERNEL_BIN}

${BUILD_DIR}/%.o: %.c ${C_HEADER}
	mkdir -p ${dir $@}
	${CC} ${CFLAGS} $< -o $@


run: ${IMAGE}
	qemu-system-x86_64 ${IMAGE}


clean:
	rm -rf build