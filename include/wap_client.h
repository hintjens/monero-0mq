/*  =========================================================================
    wap_client - Wallet Client API

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: wap_client.xml, or
     * The code generation script that built this file: zproto_client_c
    ************************************************************************
    Copyright (c) the Contributors as noted in the AUTHORS file.
                                                                
    (insert license text here)                                  
    =========================================================================
*/

#ifndef WAP_CLIENT_H_INCLUDED
#define WAP_CLIENT_H_INCLUDED

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef WAP_CLIENT_T_DEFINED
typedef struct _wap_client_t wap_client_t;
#define WAP_CLIENT_T_DEFINED
#endif

//  @interface
//  Create a new wap_client, return the reference if successful, or NULL
//  if construction failed due to lack of available memory.
WAP_EXPORT wap_client_t *
    wap_client_new (void);

//  Destroy the wap_client and free all memory used by the object.
WAP_EXPORT void
    wap_client_destroy (wap_client_t **self_p);

//  Return actor, when caller wants to work with multiple actors and/or
//  input sockets asynchronously.
WAP_EXPORT zactor_t *
    wap_client_actor (wap_client_t *self);

//  Return message pipe for asynchronous message I/O. In the high-volume case,
//  we send methods and get replies to the actor, in a synchronous manner, and
//  we send/recv high volume message data to a second pipe, the msgpipe. In
//  the low-volume case we can do everything over the actor pipe, if traffic
//  is never ambiguous.
WAP_EXPORT zsock_t *
    wap_client_msgpipe (wap_client_t *self);

//  Return true if client is currently connected, else false. Note that the
//  client will automatically re-connect if the server dies and restarts after
//  a successful first connection.
WAP_EXPORT bool
    wap_client_connected (wap_client_t *self);

//  Connect to server endpoint, with specified timeout in msecs (zero means wait    
//  forever). Constructor succeeds if connection is successful. The caller may      
//  specify its address.                                                            
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_connect (wap_client_t *self, const char *endpoint, uint32_t timeout, const char *identity);

//  Request a set of blocks from the server.                                        
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_blocks (wap_client_t *self, zlist_t **block_ids_p, uint64_t start_height);

//  Send a raw transaction to the daemon.                                           
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_put (wap_client_t *self, const char *tx_as_hex);

//  Request a set of blocks from the server.                                        
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_get (wap_client_t *self, const char *tx_id);

//  Request a set of blocks from the server.                                        
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_save (wap_client_t *self);

//  Ask for tx output indexes.                                                      
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_output_indexes (wap_client_t *self, const char *tx_id);

//  Ask for tx output indexes.                                                      
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_random_outs (wap_client_t *self, uint64_t outs_count, zframe_t **amounts_p);

//  Send start command to server.                                                   
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_start (wap_client_t *self, const char *address, uint64_t thread_count);

//  Send stop command to server.                                                    
//  Returns >= 0 if successful, -1 if interrupted.
WAP_EXPORT int 
    wap_client_stop (wap_client_t *self);

//  Return last received status
WAP_EXPORT int 
    wap_client_status (wap_client_t *self);

//  Return last received reason
WAP_EXPORT const char *
    wap_client_reason (wap_client_t *self);

//  Return last received start_height
WAP_EXPORT uint64_t 
    wap_client_start_height (wap_client_t *self);

//  Return last received curr_height
WAP_EXPORT uint64_t 
    wap_client_curr_height (wap_client_t *self);

//  Return last received block_data
WAP_EXPORT zmsg_t *
    wap_client_block_data (wap_client_t *self);

//  Return last received tx_data
WAP_EXPORT zchunk_t *
    wap_client_tx_data (wap_client_t *self);

//  Return last received o_indexes
WAP_EXPORT zframe_t *
    wap_client_o_indexes (wap_client_t *self);

//  Return last received random_outputs
WAP_EXPORT zframe_t *
    wap_client_random_outputs (wap_client_t *self);

//  Self test of this class
WAP_EXPORT void
    wap_client_test (bool verbose);

//  To enable verbose tracing (animation) of wap_client instances, set
//  this to true. This lets you trace from and including construction.
WAP_EXPORT extern volatile int
    wap_client_verbose;
//  @end

#ifdef __cplusplus
}
#endif

#endif
