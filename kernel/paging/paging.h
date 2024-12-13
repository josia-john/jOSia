#ifndef __PAGING_H_
#define __PAGING_H_

typedef struct PDE_abstract_struct {
    unsigned int address;       // only using bits 31-12
    unsigned char pagesize;     // should always be 0 for now (4KB pages); other settings depend on this.
    unsigned char available;    // bits 11-8, 6 (so upper 3 bits will deleted)
    unsigned char accessed;
    unsigned char chache_disable;
    unsigned char write_through;
    unsigned char user_allowed;
    unsigned char write_allowed;
    unsigned char present;    
} PDE_abstract;

typedef struct PTE_abstract_struct {
    unsigned int address;       // only using bits 31-12
    unsigned char available;    // bits 11-9 (so upper 5 bits will deleted)
    unsigned char global;
    unsigned char page_attribute_table;     // should be 0 for now
    unsigned char dirty;
    unsigned char accessed;
    unsigned char chache_disable;
    unsigned char write_through;
    unsigned char user_allowed;
    unsigned char write_allowed;
    unsigned char present;    
} PTE_abstract;

void initialize_paging();


#endif
