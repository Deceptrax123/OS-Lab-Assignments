#include <stdio.h>
#include <stdlib.h>

void fifo(int pages[], int frames)
{
    int window[3];
    int wc = 0;
    int hits = 0;
    int hc = 0;

    int replace_counter = 0;
    int fault = 0;

    int entry = 0;
    for (int i = 0; i < 6; i++)
    {
        int page_request = pages[i];

        // check size
        if (wc != frames)
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
                }
            }
        }

        if (hc == 0)
        {
            // replace the oldest page in memory
            fault++;
            window[replace_counter] = page_request;

            replace_counter++;
        }

        // reset variables
        hc = 0;
        entry = 0;
        if (replace_counter == frames - 1)
        {
            replace_counter = 0;
        }
    }

    printf("Total number of hits - %d\n", hits);

    printf("Total number of faults - %d\n", fault);
    double ratio = (double)(fault / 6.0);

    printf("Page fault  ratio - %0.2f\n", ratio);
}

int main()
{
    int frames = 3;
    int pages[6] = {2, 3, 4, 2, 5, 7};

    fifo(pages, frames);

    return 0;
}