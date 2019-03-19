#ifndef R1E_TEST_H
#define R1E_TEST_H

#include <gtest/gtest.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//#define MAX 1024

#define TRAVIS 0

extern "C" {
#include "common.h"
}

/*int changeStream(FILE* file) {
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

int executeTest(FILE* expectedData, FILE* outputData) {
    if (expectedData == NULL) {
        printf("Cannot open expected file \n");
        return 0;
    }
    if (outputData == NULL) {
        printf("Cannot open output file \n");
        return 0;
    }

    char expectedLine[MAXLINE];
    char outputLine[MAXLINE];

    while ((fgets(expectedLine, MAXLINE, expectedData) != NULL) | (fgets(outputLine, MAXLINE, outputData) != NULL)) {
        expectedLine[strlen(expectedLine) - 1] = '\0';
        outputLine[strlen(outputLine) - 1] = '\0';
        printf("Expected line: \"%s\", output line: \"%s\" \n", expectedLine, outputLine);
        if (strcmp(expectedLine, outputLine) != 0) return 0;
    }

    return 1;
}*/



TEST(r1e_test, test1) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output6.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output6.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    /*
        Load input data
    */

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strcpy(inFile, "tests/input/input6.txt") : strcpy(inFile, "../../testing2/tests/input/input6.txt");
    load(txt, inFile);

    /*
        Run test function
    */

   remove_first_entry_line(txt);
   show(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected6.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected6.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output6.txt", "r") : outputData = fopen("../../testing2/tests/output/output6.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(r1e_test, test2) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output7.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output7.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    /*
        Load input data
    */

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strcpy(inFile, "tests/input/input7.txt") : strcpy(inFile, "../../testing2/tests/input/input7.txt");
    load(txt, inFile);

    /*
        Run test function
    */

   remove_first_entry_line(txt);
   show(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected7.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected7.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output7.txt", "r") : outputData = fopen("../../testing2/tests/output/output7.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(r1e_test, test3) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output8.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output8.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    /*
        Load input data
    */

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strcpy(inFile, "tests/input/input8.txt") : strcpy(inFile, "../../testing2/tests/input/input8.txt");
    load(txt, inFile);

    /*
        Run test function
    */

   remove_first_entry_line(txt);
   show(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected8.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected8.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output8.txt", "r") : outputData = fopen("../../testing2/tests/output/output8.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}




#endif // R1E_TEST_H
