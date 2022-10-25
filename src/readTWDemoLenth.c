#include "STDIO.H"

//#define DEBUG
//const char* fn="0 KBeeeR S - 2_2022-04-15_19-34-17.demo";

int readLen(char* filename);

int main(int argc, char** argv){
    #if defined(DEBUG)
    printf("%s\n",argv[0]);
    return 0;
    #else
    printf("%50s",argv[1]);
    int len=readLen(argv[1]);
    
    unsigned int h=0,m=0,s=0;
    char hhmmss[8],mmss[5],ss[2];
    s=len%60;
    m=len%3600/60;
    h=len/3600;
    if (len<=0) {
        char er[5]="null";
        printf("%12s",er);
        len=-1;
    }
    else if(m==0&&h==0){
        printf("%12d",s);
    }
    else if(h==0){
        printf("%9d:%02d",m,s);
    }
    else{
        printf("%6d:%02d:%02d",h,m,s);
    }

    printf("%10d\n",len);
    return len;
    #endif
}

int readLen(char* filename){
    FILE* demo=NULL;
    demo=fopen(filename,"rb");
    int res=0x00;
    fseek(demo,152,SEEK_SET);
    for(int i=0;i<4;i++){
        res+=((int)(fgetc(demo))<<(8*(3-i)));
    }
    fclose(demo);
    return res;
}