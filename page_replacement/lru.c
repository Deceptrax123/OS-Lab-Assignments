#include <stdio.h>
#include <stdlib.h>

int lru(int pages[], int frames)
{
    int window[frames];
    int checked_pages[6];
    int ctr = 0;
    int wc = 0;
    int hits = 0;
    int hc = 0;

    int lru_index = 0;
    int replace_counter = 0;
    int fault = 0;

    int entry = 0;

    for (int i = 0; i < 6; i++)
    {
        int page_request = pages[i];

        // check size
        if (wc < frames)
        {
            window[wc] = page_request;
            wc++;

            fault++;
            entry = 1;
            hc = 1;
        }

        // check for hit
        if (entry == 0)
        {
            for (int j = 0; j < frames; j++)
            {
                if (page_request == window[j])
                {
                    hc = 1;
                    hits++;

                    checked_pages[ctr] = page_request;
                    ctr++;
                }
            }
        }

        // replace lru
        if (hc == 0)
        {

            // lru replacement
            int f = 0;
            while (1)
            {
                int page = window[lru_index];
                for (int t = 0; t < 6; t++)
                {
                    if (page == checked_pages[t])
                    {
                        lru_index++;
                        f = 1;
                    }
                }
                if (f == 0)
                {
                    break;
                }
                f = 0;
            }
            // replace the oldest page in memory
            fault++;
            window[lru_index] = page_request;

            lru_index++;
        }
        hc = 0;
        entry = 0;
    }

    printf("Total number of hits - %d\n", hits);

    printf("Total number of faults - %d\n", fault);
    double ratio = (double)(fault / 6.0);

    printf("Page fault  ratio - %0.2f\n", ratio);

    printf("Current page requests in  memory : \n");
    for (int i = 0; i < frames; i++)
    {
        printf("%d ", window[i]);
    }
}

int main()
{
    int frames = 3;
    int pages[6] = {2, 3, 4, 2, 5, 7};

    lru(pages, frames);
}