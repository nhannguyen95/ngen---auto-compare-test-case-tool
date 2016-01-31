// @author: nhannguyen95.wordpress.com
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int MAX_LEN = 252;

char * getPath( const char * fullPath ) {
    char * ans = new char[MAX_LEN];
    char * fs = strrchr( fullPath, '/' );
    strncpy( ans, fullPath, fs-fullPath );
    ans[fs-fullPath] = '\0';
    
    return ans;
}

char * getFullFilePath( const char * path, const char * name ) {
    char * ans = new char[MAX_LEN];
    strcpy( ans, path );
    strcat( ans, "/" );
    strcat( ans, name );
    return ans;
}

void crtFile( const char * fullpath ) {
    char cm[MAX_LEN] = "touch ";
    strcat(cm, fullpath);
    system(cm);
}

void delFileContent( const char * fullpath ) {
    char cm[MAX_LEN] = "> ";
    strcat(cm, fullpath);
    system(cm);
}

char * getFileContent( const char * fullpath ) {
    std::ifstream file(fullpath, std::ios::binary);
    std::streambuf * raw_buffer = file.rdbuf();
    char * block = new char[MAX_LEN];
    raw_buffer->sgetn(block, MAX_LEN);
    file.close();
    return block;
}

int main(int argc, const char * argv[]) {
    
    if ( argc != 5 ) {
        printf("usage: ./ngen.out gen_file your_file their_file num_case\n");
        return 1;
    }
    
    // get gen file's dir
    char * genFilePath = getPath(argv[1]);
    
    // create tmp.txt, tmp2.txt, tmp3.txt
    // in gen file's dir
    // tmp.txt: tmply store input
    // tmp2.txt: tmply store your output
    // tmp3.txt: tmply store their output
    char * tmpFileFullPath  = getFullFilePath( genFilePath, "tmp.txt" );
    char * tmp2FileFullPath = getFullFilePath( genFilePath, "tmp2.txt");
    char * tmp3FileFullPath = getFullFilePath( genFilePath, "tmp3.txt");
    crtFile( tmpFileFullPath );
    crtFile( tmp2FileFullPath);
    crtFile( tmp3FileFullPath);
    
    char cm[MAX_LEN] = "";
    bool check = false;
    for( int i = 0; i < atoi(argv[4]); i++ ) {
        
        printf("\n========================\n");
        
        // write auto-generate input to tmp.txt
        // input also appears in terminal
        strcpy(cm, argv[1]);
        strcat(cm, " 2>&1 | tee ");
        strcat(cm, tmpFileFullPath);
        system(cm);
        
        // pass input to your file
        // output appears in terminal & tmp2.txt
        printf("\nyour file:\n");
        strcpy(cm, "cat ");
        strcat(cm, tmpFileFullPath);
        strcat(cm, " | ");
        strcat(cm, argv[2]);
        strcat(cm, " 2>&1 | tee ");
        strcat(cm, tmp2FileFullPath);
        system(cm);
        
        // pass input to their file
        // output appears in terminal & tmp3.txt
        printf(" \ntheir file:\n");
        strcpy(cm, "cat ");
        strcat(cm, tmpFileFullPath);
        strcat(cm, " | ");
        strcat(cm, argv[3]);
        strcat(cm, " 2>&1 | tee ");
        strcat(cm, tmp3FileFullPath);
        system(cm);
        
        // get outputs to compare
        char * output2 = getFileContent( tmp2FileFullPath );
        char * output3 = getFileContent( tmp3FileFullPath );
        if ( strcmp(output2, output3)==0 ) check = true;
        else check = false;
        delete [] output2;
        delete [] output3;
        
        if ( check ) printf("\nYES!");
        else printf("\nNO!");
        
        // delete used-input in tmp files
        delFileContent( tmpFileFullPath );
        delFileContent( tmp2FileFullPath );
        delFileContent( tmp3FileFullPath );
    }
    
    printf("\n");
    
    // delete tmp files
    remove( tmpFileFullPath );
    remove( tmp2FileFullPath );
    remove( tmp3FileFullPath );
    
    // free memory
    delete [] genFilePath;
    delete [] tmpFileFullPath;
    delete [] tmp2FileFullPath;
    delete [] tmp3FileFullPath;
    
    return 0;
}
