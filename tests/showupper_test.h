#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <sys/io.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

extern "C" {
#include "common.h"
}

TEST(showUpperTest, num0) {
    FILE *outputData = fopen("output1.txt", "wb");
    int oldstdOut = dup(1);
    close(1);
    dup2(fileno(outputData), 1);

    text txt = create_text();
    char inFile[1024];
    strcpy(inFile, "input1.txt");
    load(txt, inFile);
    showupper(txt);

    fflush(stdout);
    fclose(outputData);
    dup2(oldstdOut, 1);
}

#endif // FIBONACHI_H
