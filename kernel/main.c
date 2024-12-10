char* VGA_text = (char*)0xB8000;

void emptyScreen() {
    for (int i = 0; i<2*80*20; i++) {
        *(VGA_text+i)=0;
    }

}

void printString(char s[], char color, char* ptr) {

    int i = 0;
    while (s[i]) {
        *(ptr+2*i) = s[i];
        *(ptr+1+2*i) = color;
        i++;
    }    
}

void intToStr(int x, char* buf) {
    char tmp[20];
    int i = 0;
    while (x) {
        tmp[i] = (x%10)+'0';
        x/=10;
        i++;
    }
    int j = i;
    buf[j]=0;
    while (j) {
        j--;
        buf[j]=tmp[i-j-1];
    }
}

__attribute__((section(".text.main"))) 
int main() {
    emptyScreen();
    char s[] = "Hello World with function calls";
    char mycoolint[15];
    intToStr(100, mycoolint);
    printString(s, 0xe, VGA_text);
    printString(mycoolint, 0xe, VGA_text+160);

    // *(VGA_text+2) = *(VGA_text);
    // emptyScreen();

    // char* ptr = (char*)0xB8000;
    // for (int i = 0; i<2*80*20; i++) {
    //     *(ptr+i)=0;
    // }

    // // char s[] = "This Sucks!";
    // int i = 0;
    // while (s[i]) {
    //     *(ptr+2*i) = s[i];
    //     *(ptr+1+2*i) = 0xe;
    //     i++;
    // }    
    while(1){printString("HI", 0x2, VGA_text+320);}
}