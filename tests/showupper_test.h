#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//#define MAX 1024

extern "C" {
#include "common.h"
}

int changeStream(FILE* file) {
    int oldstdOut = dup(1);
    close(1);
    dup2(fileno(file), 1);

    return oldstdOut;
}

void returnStream(FILE* file, int oldstdOut) {
    fflush(stdout);
    fclose(file);
    dup2(oldstdOut, 1);
}



TEST(showUpperTest, test1) {
    /*
        Open output file
    */
    FILE *outputFile = fopen("../../testing2/tests/output/output1.txt", "wb");
    if (outputFile == NULL) FAIL();
    int oldstdOut = changeStream(outputFile);

    /*
        Test load
    */

    text txt = create_text();
    char inFile[MAXLINE];
    strcpy(inFile, "../../testing2/tests/input/input1.txt");
    load(txt, inFile);

    /*
        Run test function
    */

    showupper(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Check output and expected data
    */

    FILE *expectedData = fopen("../../testing2/tests/expected/expected1.txt", "r");
    if (expectedData == NULL) FAIL();
    char expectedLine[MAXLINE];

    FILE *outputData = fopen("../../testing2/tests/output/output1.txt", "r");
    if (outputData == NULL) FAIL();
    char outputLine[MAXLINE];

    while (fgets(expectedLine, MAXLINE, expectedData) != NULL || fgets(outputLine, MAXLINE, outputData) != NULL) {
        expectedLine[strlen(expectedLine) - 1] = '\0';
        outputLine[strlen(outputLine) - 1] = '\0';
        printf("Expected line: %s, output line: %s", expectedLine, outputLine);
        //if (strcmp(expectedLine, outputLine) != 0) FAIL();
    }
}

TEST(showUpperTest, test2) {
    /*
        Open output file
    */
    FILE *outputData = fopen("../../testing2/tests/output/output2.txt", "wb");
    if (outputData == NULL) FAIL();
    int oldstdOut = changeStream(outputData);

    /*
        Test load
    */

    text txt = create_text();
    char inFile[1024];
    strcpy(inFile, "../../testing2/tests/input/input2.txt");
    load(txt, inFile);

    /*
        Run test function
    */

    showupper(txt);

    /*
        Close output file
    */

    returnStream(outputData, oldstdOut);
}

TEST(showUpperTest, test3) {
    /*
        Open output file
    */
    FILE *outputData = fopen("../../testing2/tests/output/output3.txt", "wb");
    if (outputData == NULL) FAIL();
    int oldstdOut = changeStream(outputData);

    /*
        Test load
    */

    text txt = create_text();
    char inFile[1024];
    strcpy(inFile, "../../testing2/tests/input/input3.txt");
    load(txt, inFile);

    /*
        Run test function
    */

    showupper(txt);

    /*
        Close output file
    */

    returnStream(outputData, oldstdOut);
}

TEST(showUpperTest, test4) {
    /*
        Open output file
    */
    FILE *outputData = fopen("../../testing2/tests/output/output4.txt", "wb");
    if (outputData == NULL) FAIL();
    int oldstdOut = changeStream(outputData);

    /*
        Test load
    */

    text txt = create_text();
    char inFile[1024];
    strcpy(inFile, "../../testing2/tests/input/input4.txt");
    load(txt, inFile);

    /*
        Run test function
    */

    showupper(txt);

    /*
        Close output file
    */

    returnStream(outputData, oldstdOut);
}

TEST(showUpperTest, test5) {
    /*
        Open output file
    */
    FILE *outputData = fopen("../../testing2/tests/output/output5.txt", "wb");
    if (outputData == NULL) FAIL();
    int oldstdOut = changeStream(outputData);

    /*
        Test load
    */

    text txt = create_text();
    char inFile[1024];
    strcpy(inFile, "../../testing2/tests/input/input5.txt");
    load(txt, inFile);

    /*
        Run test function
    */

    showupper(txt);

    /*
        Close output file
    */

    returnStream(outputData, oldstdOut);
}


#endif // FIBONACHI_H
