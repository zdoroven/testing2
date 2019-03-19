#ifndef SHOWUPPER_TEST_H
#define SHOWUPPER_TEST_H

#include <gtest/gtest.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//#define MAX 1024

#define TRAVIS 1

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

int executeTest(FILE* expectedData, FILE* outputData) {
    if (expectedData == NULL) {
        printf("Cannot open expected file \n");
        return 0;
    }
    if (outputData == NULL) {
        printf("Cannot open output file \n");
        return 0;
    }

    char expectedLine[MAXLINE+1];
    char outputLine[MAXLINE+1];

    while ((fgets(expectedLine, MAXLINE, expectedData) != NULL) | (fgets(outputLine, MAXLINE, outputData) != NULL)) {
        expectedLine[strlen(expectedLine) - 1] = '\0';
        outputLine[strlen(outputLine) - 1] = '\0';
        printf("Expected line: \"%s\", output line: \"%s\" \n", expectedLine, outputLine);
        if (strcmp(expectedLine, outputLine) != 0) return 0;
    }

    return 1;
}



TEST(showUpperTest, test1) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output1.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output1.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input1.txt", 50) : strncpy(inFile, "../../testing2/tests/input/input1.txt", 50);
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
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected1.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected1.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output1.txt", "r") : outputData = fopen("../../testing2/tests/output/output1.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(showUpperTest, test2) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output2.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output2.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input2.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input2.txt", MAXLINE);
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
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected2.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected2.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output2.txt", "r") : outputData = fopen("../../testing2/tests/output/output2.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(showUpperTest, test3) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output3.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output3.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input3.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input3.txt", MAXLINE);
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
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected3.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected3.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output3.txt", "r") : outputData = fopen("../../testing2/tests/output/output3.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(showUpperTest, test4) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output4.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output4.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input4.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input4.txt", MAXLINE);
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
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected4.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected4.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output4.txt", "r") : outputData = fopen("../../testing2/tests/output/output4.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(showUpperTest, test5) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output5.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output5.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input5.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input5.txt", MAXLINE);
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
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected5.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected5.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output5.txt", "r") : outputData = fopen("../../testing2/tests/output/output5.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}


#endif // SHOWUPPER_TEST_H
