#include <cstddef>

struct vector{
    int len;
    int rsize;
    int elsize;
    void *data;
};

inline void vector_init(vector *v, size_t elsize){
    v->elsize = elsize;
    v->len = 0;
    v->rsize = 0;
    v->data = NULL;
}

inline void vec_push(vector *v, void *data){

}
