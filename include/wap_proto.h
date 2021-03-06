/*  =========================================================================
    wap_proto - Wallet Access Protocol

    Codec header for wap_proto.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: wap_proto.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    Copyright (c) the Contributors as noted in the AUTHORS file.
                                                                
    (insert license text here)                                  
    =========================================================================
*/

#ifndef WAP_PROTO_H_INCLUDED
#define WAP_PROTO_H_INCLUDED

/*  These are the wap_proto messages:

    OPEN - Wallet opens a connection to the daemon.
        protocol            string      
        version             number 2    Protocol version 1
        identity            string      Wallet identity

    OPEN_OK - Daemon accepts wallet open request.

    BLOCKS - Wallet requests a set of blocks from the daemon. Daemon replies with
BLOCKS-OK, or ERROR if the request is invalid.
        block_ids           strings     
        start_height        number 8    

    BLOCKS_OK - Daemon returns a set of blocks to the wallet.
        status              number 8    
        start_height        number 8    
        curr_height         number 8    
        block_data          msg         Frames of block data

    PUT - Wallet sends a raw transaction to the daemon. Daemon replies with
PUT-OK, or ERROR.
        tx_as_hex           longstr     Transaction as hex

    PUT_OK - Daemon confirms that it accepted the raw transaction.
        status              number 8    Transaction ID

    OUTPUT_INDEXES - Ask for tx output indexes.
        tx_id               string      Transaction ID

    OUTPUT_INDEXES_OK - Daemon returns tx output indexes.
        status              number 8    Status
        o_indexes           frame       Output Indexes

    RANDOM_OUTS - Get random outputs for amounts.
        outs_count          number 8    Outs count
        amounts             frame       Amounts

    RANDOM_OUTS_OK - Daemon returns random outputs for amounts.
        status              number 8    Status
        random_outputs      frame       Outputs

    GET - Wallet requests transaction data from the daemon. Daemon replies
with GET-OK, or ERROR.
        tx_id               string      Transaction ID

    GET_OK - Daemon replies with transaction data.
        tx_data             chunk       Transaction data

    SAVE - save_bc command. Details tbd.

    SAVE_OK - Daemon replies to a save_bc command.

    START - Wallet asks daemon to start mining. Daemon replies with START-OK, or
ERROR.
        address             string      
        thread_count        number 8    

    START_OK - Daemon replies to a start mining request.
        status              number 8    

    STOP - Wallet asks daemon to start mining. Daemon replies with START-OK, or
ERROR.

    STOP_OK - Daemon replies to a stop mining request.

    CLOSE - Wallet closes the connection. This is polite though not mandatory.
Daemon will reply with CLOSE-OK or ERROR.

    CLOSE_OK - Daemon replies to a wallet connection close request.

    PING - Wallet heartbeats an idle connection.

    PING_OK - Daemon replies to a wallet ping request.

    ERROR - Daemon replies with failure status. Status codes tbd.
        status              number 2    Error status
        reason              string      Printable explanation
*/

#define WAP_PROTO_SUCCESS                   200
#define WAP_PROTO_NOT_DELIVERED             300
#define WAP_PROTO_CONTENT_TOO_LARGE         301
#define WAP_PROTO_TIMEOUT_EXPIRED           302
#define WAP_PROTO_CONNECTION_REFUSED        303
#define WAP_PROTO_RESOURCE_LOCKED           400
#define WAP_PROTO_ACCESS_REFUSED            401
#define WAP_PROTO_NOT_FOUND                 404
#define WAP_PROTO_COMMAND_INVALID           500
#define WAP_PROTO_NOT_IMPLEMENTED           501
#define WAP_PROTO_INTERNAL_ERROR            502

#define WAP_PROTO_OPEN                      1
#define WAP_PROTO_OPEN_OK                   2
#define WAP_PROTO_BLOCKS                    3
#define WAP_PROTO_BLOCKS_OK                 4
#define WAP_PROTO_PUT                       5
#define WAP_PROTO_PUT_OK                    6
#define WAP_PROTO_OUTPUT_INDEXES            7
#define WAP_PROTO_OUTPUT_INDEXES_OK         8
#define WAP_PROTO_RANDOM_OUTS               9
#define WAP_PROTO_RANDOM_OUTS_OK            10
#define WAP_PROTO_GET                       11
#define WAP_PROTO_GET_OK                    12
#define WAP_PROTO_SAVE                      13
#define WAP_PROTO_SAVE_OK                   14
#define WAP_PROTO_START                     15
#define WAP_PROTO_START_OK                  16
#define WAP_PROTO_STOP                      17
#define WAP_PROTO_STOP_OK                   18
#define WAP_PROTO_CLOSE                     19
#define WAP_PROTO_CLOSE_OK                  20
#define WAP_PROTO_PING                      21
#define WAP_PROTO_PING_OK                   22
#define WAP_PROTO_ERROR                     23

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef WAP_PROTO_T_DEFINED
typedef struct _wap_proto_t wap_proto_t;
#define WAP_PROTO_T_DEFINED
#endif

//  @interface
//  Create a new empty wap_proto
wap_proto_t *
    wap_proto_new (void);

//  Destroy a wap_proto instance
void
    wap_proto_destroy (wap_proto_t **self_p);

//  Receive a wap_proto from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.
int
    wap_proto_recv (wap_proto_t *self, zsock_t *input);

//  Send the wap_proto to the output socket, does not destroy it
int
    wap_proto_send (wap_proto_t *self, zsock_t *output);

//  Print contents of message to stdout
void
    wap_proto_print (wap_proto_t *self);

//  Get/set the message routing id
zframe_t *
    wap_proto_routing_id (wap_proto_t *self);
void
    wap_proto_set_routing_id (wap_proto_t *self, zframe_t *routing_id);

//  Get the wap_proto id and printable command
int
    wap_proto_id (wap_proto_t *self);
void
    wap_proto_set_id (wap_proto_t *self, int id);
const char *
    wap_proto_command (wap_proto_t *self);

//  Get/set the identity field
const char *
    wap_proto_identity (wap_proto_t *self);
void
    wap_proto_set_identity (wap_proto_t *self, const char *value);

//  Get/set the block_ids field
zlist_t *
    wap_proto_block_ids (wap_proto_t *self);
//  Get the block_ids field and transfer ownership to caller
zlist_t *
    wap_proto_get_block_ids (wap_proto_t *self);
//  Set the block_ids field, transferring ownership from caller
void
    wap_proto_set_block_ids (wap_proto_t *self, zlist_t **block_ids_p);

//  Get/set the start_height field
uint64_t
    wap_proto_start_height (wap_proto_t *self);
void
    wap_proto_set_start_height (wap_proto_t *self, uint64_t start_height);

//  Get/set the status field
uint64_t
    wap_proto_status (wap_proto_t *self);
void
    wap_proto_set_status (wap_proto_t *self, uint64_t status);

//  Get/set the curr_height field
uint64_t
    wap_proto_curr_height (wap_proto_t *self);
void
    wap_proto_set_curr_height (wap_proto_t *self, uint64_t curr_height);

//  Get a copy of the block_data field
zmsg_t *
    wap_proto_block_data (wap_proto_t *self);
//  Get the block_data field and transfer ownership to caller
zmsg_t *
    wap_proto_get_block_data (wap_proto_t *self);
//  Set the block_data field, transferring ownership from caller
void
    wap_proto_set_block_data (wap_proto_t *self, zmsg_t **msg_p);

//  Get/set the tx_as_hex field
const char *
    wap_proto_tx_as_hex (wap_proto_t *self);
void
    wap_proto_set_tx_as_hex (wap_proto_t *self, const char *value);

//  Get/set the tx_id field
const char *
    wap_proto_tx_id (wap_proto_t *self);
void
    wap_proto_set_tx_id (wap_proto_t *self, const char *value);

//  Get a copy of the o_indexes field
zframe_t *
    wap_proto_o_indexes (wap_proto_t *self);
//  Get the o_indexes field and transfer ownership to caller
zframe_t *
    wap_proto_get_o_indexes (wap_proto_t *self);
//  Set the o_indexes field, transferring ownership from caller
void
    wap_proto_set_o_indexes (wap_proto_t *self, zframe_t **frame_p);

//  Get/set the outs_count field
uint64_t
    wap_proto_outs_count (wap_proto_t *self);
void
    wap_proto_set_outs_count (wap_proto_t *self, uint64_t outs_count);

//  Get a copy of the amounts field
zframe_t *
    wap_proto_amounts (wap_proto_t *self);
//  Get the amounts field and transfer ownership to caller
zframe_t *
    wap_proto_get_amounts (wap_proto_t *self);
//  Set the amounts field, transferring ownership from caller
void
    wap_proto_set_amounts (wap_proto_t *self, zframe_t **frame_p);

//  Get a copy of the random_outputs field
zframe_t *
    wap_proto_random_outputs (wap_proto_t *self);
//  Get the random_outputs field and transfer ownership to caller
zframe_t *
    wap_proto_get_random_outputs (wap_proto_t *self);
//  Set the random_outputs field, transferring ownership from caller
void
    wap_proto_set_random_outputs (wap_proto_t *self, zframe_t **frame_p);

//  Get a copy of the tx_data field
zchunk_t *
    wap_proto_tx_data (wap_proto_t *self);
//  Get the tx_data field and transfer ownership to caller
zchunk_t *
    wap_proto_get_tx_data (wap_proto_t *self);
//  Set the tx_data field, transferring ownership from caller
void
    wap_proto_set_tx_data (wap_proto_t *self, zchunk_t **chunk_p);

//  Get/set the address field
const char *
    wap_proto_address (wap_proto_t *self);
void
    wap_proto_set_address (wap_proto_t *self, const char *value);

//  Get/set the thread_count field
uint64_t
    wap_proto_thread_count (wap_proto_t *self);
void
    wap_proto_set_thread_count (wap_proto_t *self, uint64_t thread_count);

//  Get/set the reason field
const char *
    wap_proto_reason (wap_proto_t *self);
void
    wap_proto_set_reason (wap_proto_t *self, const char *value);

//  Self test of this class
int
    wap_proto_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define wap_proto_dump      wap_proto_print

#ifdef __cplusplus
}
#endif

#endif
