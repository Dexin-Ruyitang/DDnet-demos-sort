#include "STDIO.H"

//#define DEBUG

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
    if(m==0&&h==0){
        printf("%12d",s);
    }
    else if(h==0){
        printf("%9d:%2d",m,s);
    }
    else{
        printf("%6d:%2d:%2d",h,m,s);
    }

    printf("%10d\n",len);
    return len;
    #endif
}

int readLen(char* filename){
    FILE* demo=NULL;
    demo=fopen(filename,"r");
    int res=0;
    fseek(demo,152,SEEK_SET);
    for(int i=0;i<4;i++){
        res+=(int)fgetc(demo);
    }
    fclose(demo);
    return res;
}