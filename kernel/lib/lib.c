void emptyScreen(char* VGA_text) {
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