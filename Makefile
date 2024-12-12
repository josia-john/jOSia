BUILD_DIR = build

ENTRY_SRC =		boot/entry.s
ENTRY_DEPS =	$(wildcard	boot/realmode_lib/*.s	\
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

KERNEL_ASM =		$(wildcard kernel/interrupts/*.s\
					)
KERNEL_ASM_OBJ = 	$(patsubst %.s, ${BUILD_DIR}/%.o, $(KERNEL_ASM))

LINKER_SCRIPT = kernel/linker.ld
LD =			ld
LDFLAGS =		-m elf_i386 -Ttext 0x7e00 -T ${LINKER_SCRIPT}
KERNEL_BIN = 	${BUILD_DIR}/kernel.bin

IMAGE =			${BUILD_DIR}/jOSia


all: ${IMAGE}

${IMAGE}: ${ASM_BIN} ${KERNEL_BIN}
	@mkdir -p ${BUILD_DIR}
	cat $(ASM_BIN) > $(IMAGE)
	cat $(KERNEL_BIN) >> $(IMAGE)

${ASM_BIN}: ${ENTRY_SRC} ${ENTRY_DEPS}
	@mkdir -p ${BUILD_DIR}
	nasm -f bin $(ENTRY_SRC) -o $(ASM_BIN)

${KERNEL_BIN}: ${C_OBJ} ${KERNEL_ASM_OBJ}
	${LD} ${LDFLAGS} ${C_OBJ} ${KERNEL_ASM_OBJ} -o ${KERNEL_BIN}

${BUILD_DIR}/%.o: %.c ${C_HEADER}
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} $< -o $@

${BUILD_DIR}/%.o: %.s ${C_HEADER}
	@mkdir -p ${dir $@}
	nasm -f elf32 $< -o $@


run: ${IMAGE}
	qemu-system-x86_64 -drive format=raw,file=${IMAGE}


clean:
	rm -rf build