/**
 * Implement functions for DataLoader.h
 *
 * @author Brett Perry
 * @version 2.23.22
 */

#include <stdio.h>
#include <stdlib.h>
#include "DataLoader.h"

/**
 * Loads a test_scenario strut from a textfile.
 *
 * @param filename The name of the file to load.
 * @return A struct containing the loaded file.
 */
struct test_scenario* load_test_data(char* filename) {
    struct test_scenario *data = malloc(sizeof(struct test_scenario));
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: No file to load\n");
    }

    //line 1: # of num_pages
    fscanf(fp, "%d", &data->page_count);
    //printf("%d\n", data->page_count);
    //line 2: # of num_frames
    fscanf(fp, "%d", &data->frame_count);
    //printf("%d\n", data->frame_count);
    //line 3: # of num_entries in reference string
    fscanf(fp, "%d", &data->refstr_len);
    //printf("%d\n", data->refstr_len);
    //line 4 -> n: page in reference string
    int i = 0;
    data->refstr[data->refstr_len] = malloc(sizeof(int) * data->refstr_len);
    while (i < data->refstr_len) {
        fscanf(fp, "%d", &data->refstr[i]);
        //printf("%d\n", data->refstr[i]);
        i++;
    }

    return data;
}

