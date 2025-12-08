#ifndef BUSZ
#define BUSZ

typedef struct Megallo
{
    char* nev;
    int x;
    int y;
} Megallo_t;

void show_map(Megallo_t* tomb, int size);
void print_bus_stop(Megallo_t* tomb, int size);
Megallo_t* create_bus_stop();
void delete_bus_stop(Megallo_t* tomb, int size);
void save_list(Megallo_t* tomb, int size);
#endif