# jOSia

My own and very small "OS".

This project originated because I wanted to understand what kind of magic goes
on in a computer when it boots an operating system. I had enough spare time, so
I just wrote some code which is actually bootable.

jOSia is far from an actual OS, but here are the things I got running:

- A bootsector, which is able to load more code from disk using BIOS. (see `/boot`)
- Switch to 32-bit mode. (see `/boot`)
- Basic printing functions, using VGA in text mode. (see `/kernel/lib`)
- Support for Interrupts. (see `/kernel/interrupts`)
    - System timer
    - Keyboard (see `/kernel/drivers`)
- Enabling paging. (see `/kernel/paging`)

Features that would be next:

- Context Switches
- Userspace
- Shell
- ...

If you flash jOSia onto a USB, you can boot from it using legacy BIOS.

To build use `make`, to test using QEMU use `make run`. (For dependencies see `Makefile`.)