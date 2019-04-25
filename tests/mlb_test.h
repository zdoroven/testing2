#ifndef MLB_TEST_H
#define MLB_TEST_H
#include "shared.h"

extern "C" {
#include "common.h"
}

TEST(mlb_test, test1) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output9.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output9.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input9.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input9.txt", MAXLINE);
    load(txt, inFile);

    /*
        Run test function
    */

   mwcrsr(txt, 1, 3);
   cursor_to_begin(txt);
   show(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected9.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected9.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output9.txt", "r") : outputData = fopen("../../testing2/tests/output/output9.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(mlb_test, test2) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output10.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output10.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input10.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input10.txt", MAXLINE);
    load(txt, inFile);

    /*
        Run test function
    */

   mwcrsr(txt, 3, 3);
   cursor_to_begin(txt);
   show(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected10.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected10.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output10.txt", "r") : outputData = fopen("../../testing2/tests/output/output10.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(mlb_test, test3) {
    /*
        Open output file
    */
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output11.txt", "wb") : outputFile = fopen("../../testing2/tests/output/output11.txt", "wb");
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
    TRAVIS ? strncpy(inFile, "tests/input/input11.txt", MAXLINE) : strncpy(inFile, "../../testing2/tests/input/input11.txt", MAXLINE);
    load(txt, inFile);

    /*
        Run test function
    */

   cursor_to_begin(txt);
   show(txt);

    /*
        Close output file
    */

    returnStream(outputFile, oldstdOut);

    /*
        Execute test
    */

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected11.txt", "r") : expectedData = fopen("../../testing2/tests/expected/expected11.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output11.txt", "r") : outputData = fopen("../../testing2/tests/output/output11.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}




#endif // MLB_TEST_H
