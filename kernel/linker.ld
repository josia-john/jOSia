/*
So far all this linker script does is
to put the main() function at the top.
*/

OUTPUT_FORMAT(binary)


SECTIONS
{
    .text :
    {
        *(.text.main)
    } 
}
