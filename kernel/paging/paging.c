#include "paging.h"


/*
    We need 4KB for the page directory.
    We set up our first page table (also 4KB) to be identity.
    This gives us 4MB (0x000000 - 0x3FFFFF).
    It is kernel only.

    page directory and first page table both fit into that.
*/


unsigned int __attribute__((aligned(4096))) page_directory[1024] ;
unsigned int __attribute__((aligned(4096))) identity_page_table[1024];
unsigned int __attribute__((aligned(4096))) test_page_table[1024];

PDE_abstract read_PDE(int PDE) {
    PDE_abstract res;
    res.address = PDE&(0xFFFFF000);
    res.pagesize = (PDE & (1<<7))>0;
    res.accessed = (PDE & (1<<5))>0;
    res.chache_disable = (PDE & (1<<4))>0;
    res.write_through = (PDE & (1<<3))>0;
    res.user_allowed = (PDE & (1<<2))>0;
    res.write_allowed = (PDE & (1<<1))>0;
    res.present = (PDE & 1)>0;

    res.available = (PDE & (0x00000F00))>>7;
    res.available += res.accessed = (PDE & (1<<6))>>6;

    return res;
}

int write_PDE(PDE_abstract PDE) {
    int res = 0;

    res += PDE.address&(0xFFFFF000);
    res += (PDE.pagesize&1)<<7;
    res += (PDE.accessed&1)<<5;
    res += (PDE.chache_disable&1)<<4;
    res += (PDE.write_through&1)<<3;
    res += (PDE.user_allowed&1)<<2;
    res += (PDE.write_allowed&1)<<1;
    res += (PDE.present&1);

    res += (PDE.available & 0b11110)<<7;
    res += (PDE.available & 1)<<6;

    return res;
}

PTE_abstract read_PTE(int PTE) {
    PTE_abstract res;
    res.address = PTE&(0xFFFFF000);
    res.global = (PTE & (1<<8))>0;
    res.page_attribute_table = (PTE & (1<<7))>0;
    res.dirty = (PTE & (1<<6))>0;
    res.accessed = (PTE & (1<<5))>0;
    res.chache_disable = (PTE & (1<<4))>0;
    res.write_through = (PTE & (1<<3))>0;
    res.user_allowed = (PTE & (1<<2))>0;
    res.write_allowed = (PTE & (1<<1))>0;
    res.present = (PTE & 1)>0;

    res.available = (PTE & (0x00000E00))>>9;

    return res;
}

int write_PTE(PTE_abstract PTE) {
    int res = 0;

    res += PTE.address&(0xFFFFF000);
    res += (PTE.global&1)<<8;
    res += (PTE.page_attribute_table&1)<<7;
    res += (PTE.dirty&1)<<6;
    res += (PTE.accessed&1)<<5;
    res += (PTE.chache_disable&1)<<4;
    res += (PTE.write_through&1)<<3;
    res += (PTE.user_allowed&1)<<2;
    res += (PTE.write_allowed&1)<<1;
    res += (PTE.present&1);

    res += (PTE.available & 0b111)<<9;

    return res;
}


void initialize_paging() {
    // initialize PD to *NOT PRESENT* for all entries.
    for (int i = 0; i<1024; i++) {
        page_directory[i] = 0;
    }

    PDE_abstract first_pde;
    first_pde.address = (unsigned int)&identity_page_table;
    first_pde.pagesize = 0;
    first_pde.available = 0;
    first_pde.accessed = 0;
    first_pde.chache_disable = 0;
    first_pde.write_through = 0;
    first_pde.user_allowed = 0;
    first_pde.write_allowed = 1;
    first_pde.present = 1;

    page_directory[0] = write_PDE(first_pde);
    first_pde.address = (unsigned int)&test_page_table;
    page_directory[1] = write_PDE(first_pde);


    PTE_abstract identity_pte;
    identity_pte.available = 0;
    identity_pte.global = 1;
    identity_pte.page_attribute_table = 0;
    identity_pte.dirty = 0;
    identity_pte.accessed = 0;
    identity_pte.chache_disable = 0;
    identity_pte.write_through = 0;
    identity_pte.user_allowed = 0;
    identity_pte.write_allowed = 1;
    identity_pte.present = 1;

    for (int i = 0; i<1024; i++) {
        identity_pte.address = (1<<12)*(i);
        identity_page_table[i] = write_PTE(identity_pte);
    }


    for (int i = 0; i<1024; i++) {
        identity_pte.address = 0x800000;
        test_page_table[i] = write_PTE(identity_pte);
    }



    __asm__ volatile (
        "mov %0, %%eax; mov %%eax, %%cr3;"  // Load GDTR
        :                           // output: None
        : "memory"(&page_directory)  // input page_directory
        : "%eax"                   // clobbered
    );
    __asm__ volatile (
        "mov %%cr0, %%eax; or $0x80000001, %%eax; mov %%eax, %%cr0"  // Load GDTR
        :                           // output: None
        :                           // input: None
        : "%eax"                   // clobbered
    );

}


