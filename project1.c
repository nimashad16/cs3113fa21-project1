//
//  main.c
//  Project1
//
//  Created by Nima $wagaram on 11/1/21.
//  Copyright © 2021 Nima $wagaram. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process{
    int processQueue[98307];
    int processId[98307];
    int PID;
    int size;
    int bVar;
    int priorID;
    int sum;
};

struct ProcessInfo{
    int array[98307];
    int size;
    int counter;
    int waitingTime;
    int turnAroundTime;
    int PID;
    int totalBurstTime;
    int bVar;
    int sum;
    int priorID;
};

float getThroughput(struct ProcessInfo *array, int size){
    struct ProcessInfo newArray[size];
    int sum =0;;
    int a = 0;
    
    for(int x = 0; a< size;x++){           //runs a for loop to get the the every third variable after
                                            // the first burst input
        newArray[a].bVar = array[x].bVar;
        a++;
    }
    
    for(int b =0; b <= 4;b++){              //Adds all of them up together from the new array
        sum += newArray[b].bVar;
    }
    
    double test = a-1;
    test/=sum;                              //Divides them by the total number of elements

   int c, r, m;
     m = sum*1000;
     c = m%10; // c = 4
     r = m/10; //
     if(c>=5)
     r++;
     sum = (float)r/100;

    return  test;
}


int getWaitingTime(struct Process processQueue[],struct ProcessInfo array[], int pQSize, int arrSize){
    
    int x = 0;
    int y=0;
    while(x < arrSize){
        y = 0;
        while(y < pQSize && array[x].counter > 0){
            if (processQueue[y].PID == array[x].PID){
                array[x].counter -= 1;
                continue;
             }
            array[x].waitingTime += processQueue[y].size;
            y++;
    }
        x++;
}
    int sum =0;
    for(int a =0; a < arrSize;a++){
        sum += array[a].waitingTime;
    }
    sum /= arrSize;
    
     return sum;
}

int getTurnAroundTime(struct Process processQueue[],struct ProcessInfo array[], int pQSize, int arrSize){
    int count =0;
    
    return 0;
}

    
/*int getResponseTime(struct Process processQueue[],struct ProcessInfo array[], int pQSize){                      //First time - Arrival Time
    
    int count;
    for(int x =0; x< pQSize; x++){
            if(newP == arrayNums[x]){
                count++;
            }
        }
    int sum =0;
    for(int idx =0; idx < pQSize; idx++){
        sum += array[idx];
    }
    
    sum /= count;
    
    return sum;
    
    }
*/

int main(int argc, const char * argv[]) {
    int start;
    
    int a;
     FILE *fp = fopen(argv[1],"r");
    
    int newP;
    int numVals;
    
    struct ProcessInfo arrayStore[98307];
    
    fscanf(fp,"%d", &start);
    fscanf(fp,"%d", &newP);
    fscanf(fp,"%d", &numVals);
    
    
    for(a =0; a<numVals; ++a ){
        fscanf(fp,"%d %d %d", &arrayStore[a].PID, &arrayStore[a].bVar,&arrayStore[a].priorID);
    }
    
    int check = 0;

    printf("%d\n",start);                       //Gets voluntary context switch
 
    printf("100.0\n");                              //CPU Utilization
    
    float result = getThroughput(arrayStore, numVals);      //Gets throughput
    printf("%.02f\n",result);
    //float wait = getWaitingTime(arrayStore.PID,arrayStore.bVar,numVals);
    //getResponseTime(, , numVals);
    //printf("0.02f\n",wait);
                           //Throughput
   
    return 0;
}


