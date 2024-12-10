BUILD_DIR = build

ENTRY_SRC = boot/entry.s
ENTRY_LIBS = $(wildcard boot/realmode_lib/*.s)
KERNEL_SRC = kernel/main.c
KERNEL_LINKER_SCRIPT = kernel/linker.ld

ENTRY_BIN = $(BUILD_DIR)/entry.bin
OS_IMG = $(BUILD_DIR)/jOSia
KERNEL_OBJ = $(BUILD_DIR)/main.o
KERNEL_BIN = $(BUILD_DIR)/main.bin


# Default target
all: $(OS_IMG)

$(OS_IMG): $(ENTRY_BIN) $(KERNEL_BIN)
	cat $(ENTRY_BIN) > $(OS_IMG)
	cat $(KERNEL_BIN) >> $(OS_IMG)

# Assemble the entry code using NASM, and 
$(ENTRY_BIN): $(ENTRY_SRC) $(ENTRY_LIBS)
	nasm -f bin $(ENTRY_SRC) -o $(ENTRY_BIN)

# Compile the kernel to an object file
$(KERNEL_OBJ): $(KERNEL_SRC)
	i386-elf-gcc -ffreestanding -c $(KERNEL_SRC) -o $(KERNEL_OBJ)

# Step 3: Link the C object file into a binary
$(KERNEL_BIN): $(KERNEL_OBJ) $(KERNEL_LINKER_SCRIPT)
	ld -m elf_i386 -Ttext 0x7e00 -T $(KERNEL_LINKER_SCRIPT) $(KERNEL_OBJ) -o $(KERNEL_BIN)

# Clean up build artifacts
clean:
	rm -f $(OS_IMG) $(ENTRY_BIN) $(KERNEL_BIN) $(KERNEL_OBJ)
