#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Graph.h"
#define MAX_LINE 1024

void ReadFile(char*, int);
int main(){
    char name[] = "./source/graph_source5.txt";
    ReadFile(name,strlen(name));
    system("pause");
    return 0;
}
void ReadFile(char* _filePath, int length)
{
    printf("%s\n",_filePath);
    FILE * fp;
    // FILE is a struct, it contains
    // struct FILE{
    //     void (*open)(char* name, int mode);
    //     void (*close)();
    //     int (*read)();
    //     void (*write)(char);
    //     void (*seek)(long index, int mode);
    // }
    char *line = NULL;
    char buf[MAX_LINE];
    size_t len = 0;
    // ssize_t read;
    fp = fopen(_filePath,"r");

    if(fp==NULL)
        return;
    
    // getline(&line,&len,fp);

    // int graphSize=strlen(line)/2;
    fgets(buf,MAX_LINE,fp);
    int graphSize = strlen(buf)/2;

    int** graphData = (int**)malloc(graphSize*sizeof(int*));
    Graph* g2 = new_Graph(graphSize);

    int k;
    for(k=0; k<graphSize;k++)
        graphData[k] = (int*)malloc(graphSize*sizeof(int));
    // move read pointer to the beginning position
    fseek(fp, 0, SEEK_SET);
    
    int i,j;
    for(i=0; i<graphSize;i++){
        // read single line
        // getline(&line,&len,fp);

        fgets(buf,MAX_LINE,fp);
        for(j=0; j<strlen(buf);j+=2)
            graphData[i][j/2] = buf[j]-48;
    }

    for(i=0; i<graphSize;i++){
        for(j=0;j<graphSize;j++){
            printf("%d ",graphData[i][j]);
            if(graphData[i][j]!=0){
                AddEdgeList(g2,i,j);
            }
        }
        printf("\n");
    }
    fclose(fp);
    // make depth-first search
    DFS(g2,0);
    BFS(g2,3);
    return;
}