#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define USAGE fprintf(stderr, "Usage:\n\t %s -n NUM_VERTICES -e NUM_EDGES \
        NUM_GRAPHS\n", argv[0])

int main(int argc, char *argv[])
{
    int n, e, num_g;
    char c;

    n = e = num_g = -1;

    while ((c = getopt(argc, argv, "n:e:")) != -1) {
        switch(c) {
            case 'n':
                if (!sscanf(optarg, "%d", &n)) {
                    fprintf(stderr, "Invalid option for '%c': %s\n", c, optarg);
                }
                break;
            case 'e':
                if (!sscanf(optarg, "%d", &e)) {
                    fprintf(stderr, "Invalid option for '%c': %s\n", c, optarg);
                }
                break;
            case '?':
                fprintf(stderr, "Unrecognized option: '-%c'\n", optopt);
                break;
        }
    }

    if (!access(argv[optind], R_OK) || !sscanf(argv[optind], "%d", &num_g)) {
        USAGE;
    }

    return 0;
}
