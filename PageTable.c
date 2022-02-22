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
    free(pt);
    pt = NULL;
}

/**
 * Simulates an instruction accessing a particular page in the page table.
 *
 * @param pt A page table object.
 * @param page The page being accessed.
 */
void page_table_access_page(struct page_table *pt, int page) {

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

}

