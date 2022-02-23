/**
 * Implement functions for PageTable.h
 *
 * @author Brett Perry
 * @version 2.23.22
 */

#include "PageTable.h"

struct page_table_entry {
    int frame;
    unsigned int flags;
    unsigned int order;
    int last;
    unsigned int freq;
};

struct page_table {
    enum replacement_algorithm type;
    int num_pages;
    struct page_table_entry *pages;
    int num_frames;
    int *frames;
    int page_faults;
    int head;
    int count;
    int verbose;
};

/**
 * Creates a new page table object. Returns a pointer to created page table.
 *
 * @param page_count Number of pages.
 * @param frame_count Numbers of frames.
 * @param algorithm Page replacement algorithm
 * @param verbose Enables showing verbose table contents.
 * @return A page table object.
 */
struct page_table* page_table_create(int page_count, int frame_count, enum replacement_algorithm algorithm, int verbose) {
    struct page_table *p = malloc(sizeof(struct page_table));
    p->num_pages = page_count;
    p->num_frames = frame_count;
    p->type = algorithm;
    p->verbose = verbose;
    return p;
}

/**
 * Destroys an existing page table object. Sets outside variable to NULL.
 *
 * @param pt A page table object.
 */
void page_table_destroy(struct page_table** pt) {
    free(*pt);
    pt = NULL;
}

/**
 * Simulates an instruction accessing a particular page in the page table.
 *
 * @param pt A page table object.
 * @param page The page being accessed.
 */
void page_table_access_page(struct page_table *pt, int page) {
    //FIFO = 0, LRU = 1, MFU = 2

    //FIFO
    if (pt->type == 0) {
        printf("running FIFO\n");
        //iterate through frames

        //if a spot is open

        // enter the page in that spot
        // add a page fault

        //iterate through frames again
        //if value matches an existing frame
        // do nothing
        //else
        //find the frame currently in the longest
        // enter the page in that spot
        //add a page fault
    }

    //LRU
    if (pt->type == 1) {
        printf("running LRU\n");
    }

    //MFU
    if (pt->type == 2) {
        printf("running MFU\n");
    }

}

/**
 * Displays page table replacement algorithm, number of page faults, and the
 * current contents of the page table.
 *
 * @param pt A page table object.
 */
void page_table_display(struct page_table* pt) {

}

/**
 * Displays the current contents of the page table.
 *
 * @param pt A page table object.
 */
void page_table_display_contents(struct page_table *pt) {
    /*
    printf("====Page Table====\n");
    printf("Mode: %u\n", pt->type);
    printf("Page Faults: %d\n", pt->page_faults);
    printf("page\tframe | dirty\tvalid\n");
    for (int i = 0; i < pt->num_pages; i++) {
        printf("%d\t\t%d\t  | %d\t\t%d\n", i, 0, 0, 0); //TODO: fix entries
    }
    */
}

