/**
 * link list interface header file src/cel_link.h.
 *
 * @author adan-shaw<adan_shaw@qq.com>
 */
#ifndef _cel_link_h
#define _cel_link_h

#include "cel_api.h"

struct cel_link_node_struct
{
	void *value;
	struct cel_link_node_struct *_prev;
	struct cel_link_node_struct *_next;
};
typedef struct cel_link_node_struct cel_link_node_t;

typedef struct
{
	uint_t size;
	cel_link_node_t *head;
	cel_link_node_t *tail;
} cel_link_t;

/**
 * create a new cel link list .
 *
 * @return    cel_link_t
 */
CEL_API cel_link_t *new_cel_link (void);

/**
 * free the specified link list .
 *
 * @param    cel_link_t *
 */
CEL_API void free_cel_link (cel_link_t **, cel_release_callback_fn_t);

/*
 * create the specified cel_link_t
 *
 * @param    cel_link_t *
 * @return    int 1 for success and 0 for failed
 */
CEL_API int cel_link_init (cel_link_t *);

/*
 * destroy the specified cel_link_t
 *
 * @param    cel_link_t *
 * @return    int 1 for success and 0 for failed
 */
CEL_API int cel_link_destroy (cel_link_t *, cel_release_callback_fn_t);

//add a element from the head .
CEL_API void cel_link_add_first (cel_link_t *, void *);

//append element from the tail
CEL_API void cel_link_add_last (cel_link_t *, void *);

/**
 * insert the element at a specified position .
 *
 * @param    uint_t
 * @param    void *
 */
CEL_API void cel_link_insert (cel_link_t *, uint_t, void *);

/**
 * remove the element at a specified position .
 *
 * @param    uint_t
 * @return    void *
 */
CEL_API void *cel_link_remove (cel_link_t *, uint_t);

//remove the element from the head
CEL_API void *cel_link_remove_first (cel_link_t *);

//remove the element from the tail
CEL_API void *cel_link_remove_last (cel_link_t *);

/**
 * remove the element equals the given one .
 *
 * @param    void *
 * @param    cel_compare_fn_t
 * @return    void *
 */
CEL_API void *cel_link_remove_obj (cel_link_t *, void *, cel_compare_fn_t);

//get the element at the specified postion.
CEL_API void *cel_link_get (cel_link_t *, uint_t);

/**
 * set the element at the specified position with
 *     the specified value .
 *
 * @param    uint_t
 * @param    void *
 * @return    void *
 */
CEL_API void *cel_link_set (cel_link_t *, uint_t, void *);

//search the element and replace it with a new one.
CEL_API void *cel_link_set_obj (cel_link_t *, void *, void *, cel_compare_fn_t);

//link struct quick getter macro define
#define cel_link_size( link ) link->size
#define cel_link_head( link ) link->head
#define cel_link_tail( link ) link->tail

#endif /*end ifndef */
