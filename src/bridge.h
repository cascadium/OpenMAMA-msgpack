/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Cascadium Ltd (http://cascadium.io)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MAMA_BRIDGE_MSGPACK_MSG_PAYLOAD_H__
#define MAMA_BRIDGE_MSGPACK_MSG_PAYLOAD_H__

#include <mama/mama.h>
#include <mama/price.h>
#include <wombat/strutils.h>
#include <mama/integration/types.h>
#include <msgpack.h>

// 0xde is the msgpack format for Map16 (up to UINT16_MAX members - should be more than enough)
#define MAMA_PAYLOAD_ID_MSGPACK     0xde
#define MSGPACK_CHUNK_SIZE          2048

typedef struct msgpackPayloadImpl {
    msgPayload mOmnmPayload;
    msgpack_sbuffer mBuffer;
    msgpack_packer mPacker;
    msgpack_zone mDeserializationZone;
    msgpack_object mDeserializedObj;
} msgpackPayloadImpl;

#endif /* MAMA_BRIDGE_MSGPACK_MSG_PAYLOAD_H__ */
