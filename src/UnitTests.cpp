/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Frank Quinn (http://fquinner.github.io)
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

#include <gtest/gtest.h>
#include <mama/mama.h>
#include <mama/integration/bridge/omnmmsgpayloadfunctions.h>
#include "msgpackmsgpayloadfunctions.h"
#include "bridge.h"

int main (int argc, char **argv)
{
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}

class MsgpackTests: public ::testing::Test
{
protected:
    MsgpackTests ()
    {
    }

    virtual ~MsgpackTests ()
    {
    }

    virtual void SetUp ()
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
        msgpackmsgPayload_create (&mPayloadBase);
        mama_setLogLevel(MAMA_LOG_LEVEL_NORMAL);
        mama_loadPayloadBridge(&mPayloadBridge, "msgpackmsg");
    }

    virtual void TearDown ()
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
        msgpackmsgPayload_destroy (mPayloadBase);
    }
    mamaPayloadBridge mPayloadBridge;
    char mPayloadBridgeId;
    msgPayload mPayloadBase;
};

// Really just a test to make sure the OMNMMSG deferral stuff works
TEST_F(MsgpackTests, CreatePayloadWithNatives)
{
    mama_i64_t actual = 0;
    mama_i64_t expected = 12398;
    msgpackmsgPayload_addI64 (mPayloadBase, "banana", 666, expected);
    msgpackmsgPayload_getI64 (mPayloadBase, "banana", 666, &actual);
    ASSERT_EQ (expected, actual);
}

// Actually try serialization and deserialization
TEST_F(MsgpackTests, TestCodecI8)
{
    mama_i8_t values[5] = {10, -10, INT8_MIN, 0, INT8_MAX};
    for (int i = 0; i < 5; i++) {
        mama_i8_t expected = values[i];
        mama_i8_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);
        msgpackmsgPayload_addI8(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getI8(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

// Actually try serialization and deserialization
TEST_F(MsgpackTests, TestCodecI16)
{
    mama_i16_t values[5] = {10, -10, INT16_MIN, 0, INT16_MAX};
    for (int i = 0; i < 5; i++) {
        mama_i16_t expected = values[i];
        mama_i16_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);
        msgpackmsgPayload_addI16(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getI16(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

// Actually try serialization and deserialization
TEST_F(MsgpackTests, TestCodecI32)
{
    mama_i32_t values[5] = {10, -10, INT32_MIN, 0, INT32_MAX};
    for (int i = 0; i < 5; i++) {
        mama_i32_t expected = values[i];
        mama_i32_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);
        msgpackmsgPayload_addI32(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getI32(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

// Actually try serialization and deserialization
TEST_F(MsgpackTests, TestCodecI64)
{
    mama_i64_t values[5] = {10, -10, INT8_MIN, 0, INT8_MAX};
    for (int i = 0; i < 5; i++) {
        mama_i64_t expected = values[i];
        mama_i64_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);
        msgpackmsgPayload_addI64(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getI64(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

// Actually try serialization and deserialization
TEST_F(MsgpackTests, TestCodecU8)
{
    mama_u8_t values[3] = {10, 0, UINT8_MAX};
    for (int i = 0; i < 3; i++) {
        mama_u8_t expected = values[i];
        mama_u8_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addU8(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getU8(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecU16)
{
    mama_u16_t values[3] = {10, 0, UINT16_MAX};
    for (int i = 0; i < 3; i++) {
        mama_u16_t expected = values[i];
        mama_u16_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addU16(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getU16(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecU32)
{
    mama_u32_t values[3] = {10, 0, UINT32_MAX};
    for (int i = 0; i < 3; i++) {
        mama_u32_t expected = values[i];
        mama_u32_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addU32(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getU32(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecU64)
{
    mama_u64_t values[3] = {10, 0, UINT64_MAX};
    for (int i = 0; i < 3; i++) {
        mama_u64_t expected = values[i];
        mama_u64_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addU64(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getU64(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecBool)
{
    mama_bool_t values[2] = {1, 0};
    for (int i = 0; i < 2; i++) {
        mama_bool_t expected = values[i];
        mama_bool_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addBool(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getBool(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecStr)
{
    const char* values[2] = {"ALKSJDLKAJLDKJALKJDLKASLDKJALKJDLAKJSDLJA", "VALUE1"};
    for (int i = 0; i < 2; i++) {
        const char* expected = values[i];
        const char* actual = nullptr;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addString(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getString(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_STREQ(expected, actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecF32)
{
    mama_f32_t values[2] = {0.3F, 0.9F};
    for (int i = 0; i < 2; i++) {
        mama_f32_t expected = values[i];
        mama_f32_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addF32(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getF32(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_NEAR(expected, actual, 0.00000001);
        msgpackmsgPayload_destroy(msg);
    }
}


TEST_F(MsgpackTests, TestCodecF64)
{
    mama_f64_t values[2] = {0.3F, 0.9F};
    for (int i = 0; i < 2; i++) {
        mama_f64_t expected = values[i];
        mama_f64_t actual = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addF64(mPayloadBase, nullptr, 1, expected);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getF64(msg, nullptr, 1, &actual);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_NEAR(expected, actual, MAMA_PRICE_EPSILON);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestCodecOpaque)
{
    const char* values[2] = {"ALKSJDLKAJLDKJALKJDLKASLDKJALKJDLAKJSDLJA", "VALUE1"};
    for (int i = 0; i < 2; i++) {
        const void* expected = (const void*) values[i];
        mama_size_t expectedLen = strlen(values[i]) + 1;
        const void* actual = nullptr;
        mama_size_t actualLen = 0;
        msgpackmsgPayload_destroy (mPayloadBase);
        msgpackmsgPayload_create (&mPayloadBase);

        msgpackmsgPayload_addOpaque(mPayloadBase, nullptr, 1, expected, expectedLen);
        const void *buffer = nullptr;
        mama_size_t len = 0;
        msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

        msgPayload msg;
        msgpackmsgPayload_create(&msg);
        msgpackmsgPayload_unSerialize(msg, buffer, len);

        mama_size_t numFields;
        msgpackmsgPayload_getNumFields(msg, &numFields);
        ASSERT_EQ(1, numFields);

        // Msgpack deserializes all signed integers as int64
        mama_status status = msgpackmsgPayload_getOpaque(msg, nullptr, 1, &actual, &actualLen);
        ASSERT_EQ(MAMA_STATUS_OK, status);
        ASSERT_EQ(expectedLen, actualLen);
        ASSERT_STREQ((const char*)expected, (const char*)actual);
        msgpackmsgPayload_destroy(msg);
    }
}

TEST_F(MsgpackTests, TestMamaDateTime)
{
    mamaDateTime expected = nullptr, actual = nullptr;
    mamaDateTimeHints expectedHints = MAMA_DATE_TIME_HAS_DATE, actualHints;
    mamaDateTimePrecision expectedPrecision = MAMA_DATE_TIME_PREC_NANOSECONDS, actualPrecision;
    mamaDateTime_create(&expected);
    mamaDateTime_setToNow(expected);
    mamaDateTime_setHints(expected, expectedHints);
    mamaDateTime_setPrecision(expected, expectedPrecision);
    mamaDateTime_create(&actual);

    msgpackmsgPayload_addDateTime(mPayloadBase, nullptr, 1, expected);
    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    mama_status status = msgpackmsgPayload_getDateTime(msg, nullptr, 1, actual);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_TRUE(mamaDateTime_equal(actual, expected));

    mamaDateTime_getPrecision(actual, &actualPrecision);
    mamaDateTime_getHints(actual, &actualHints);

    ASSERT_EQ(expectedHints, actualHints);
    ASSERT_EQ(expectedPrecision, actualPrecision);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaPrice)
{
    double expectedVal = 0.99, actualVal;
    mamaPrice expected = nullptr, actual = nullptr;
    mamaPriceHints expectedHints = 0x0c, actualHints;
    mamaPricePrecision expectedPrecision = MAMA_PRICE_PREC_100000000, actualPrecision;
    mamaPrice_create(&expected);
    mamaPrice_setValue(expected, expectedVal);
    mamaPrice_setHints(expected, expectedHints);
    mamaPrice_setPrecision(expected, expectedPrecision);
    // Precision may have changed hints under hood so get new value
    mamaPrice_getHints(expected, &expectedHints);
    mamaPrice_create(&actual);

    msgpackmsgPayload_addPrice(mPayloadBase, nullptr, 1, expected);
    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    mama_status status = msgpackmsgPayload_getPrice(msg, nullptr, 1, actual);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_TRUE(mamaPrice_equal(actual, expected));

    mamaPrice_getPrecision(actual, &actualPrecision);
    mamaPrice_getHints(actual, &actualHints);
    mamaPrice_getValue(actual, &actualVal);

    ASSERT_EQ(expectedHints, actualHints);
    ASSERT_EQ(expectedPrecision, actualPrecision);
    ASSERT_NEAR(expectedVal, actualVal, 0.0000001);

    msgpackmsgPayload_destroy(msg);
}

#define VECTOR_ITEM_COUNT 10

TEST_F(MsgpackTests, TestMamaVectorBool)
{
    mama_bool_t expected[VECTOR_ITEM_COUNT];
    const mama_bool_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < sizeof(expected); i++)
        expected[i] = i % 2;

    status = msgpackmsgPayload_addVectorBool(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorBool(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorU8)
{
    mama_u8_t expected[VECTOR_ITEM_COUNT];
    const mama_u8_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    status = msgpackmsgPayload_addVectorU8(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorU8(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorU16)
{
    mama_u16_t expected[VECTOR_ITEM_COUNT];
    const mama_u16_t* actual = nullptr;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = (uint16_t)i;

    expected[0] = UINT16_MAX;

    status = msgpackmsgPayload_addVectorU16(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorU16(msg, nullptr, 1, (const mama_u16_t**)&actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorU32)
{
    mama_u32_t expected[VECTOR_ITEM_COUNT];
    const mama_u32_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = UINT32_MAX;

    status = msgpackmsgPayload_addVectorU32(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorU32(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorU64)
{
    mama_u64_t expected[VECTOR_ITEM_COUNT];
    const mama_u64_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = UINT64_MAX;

    status = msgpackmsgPayload_addVectorU64(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorU64(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorI8)
{
    mama_i8_t expected[VECTOR_ITEM_COUNT];
    const mama_i8_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = INT8_MIN;
    expected[1] = INT8_MAX;

    status = msgpackmsgPayload_addVectorI8(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorI8(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorI16)
{
    mama_i16_t expected[VECTOR_ITEM_COUNT];
    const mama_i16_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = INT16_MIN;
    expected[1] = INT16_MAX;

    status = msgpackmsgPayload_addVectorI16(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorI16(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorI32)
{
    mama_i32_t expected[VECTOR_ITEM_COUNT];
    const mama_i32_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = INT32_MIN;
    expected[1] = INT32_MAX;

    status = msgpackmsgPayload_addVectorI32(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorI32(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorI64)
{
    mama_i64_t expected[VECTOR_ITEM_COUNT];
    const mama_i64_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = INT64_MIN;
    expected[1] = INT64_MAX;

    status = msgpackmsgPayload_addVectorI64(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorI64(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorF32)
{
    mama_f32_t expected[VECTOR_ITEM_COUNT];
    const mama_f32_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    expected[0] = 6.0;
    expected[1] = 5.0;

    status = msgpackmsgPayload_addVectorF32(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorF32(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorF64)
{
    mama_f64_t expected[VECTOR_ITEM_COUNT];
    const mama_f64_t* actual;
    mama_size_t actualLen;
    mama_status status;

    for(int i = 0; i < VECTOR_ITEM_COUNT; i++)
        expected[i] = i % 2;

    status = msgpackmsgPayload_addVectorF64(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorF64(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_EQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaVectorString)
{
    const char* expected[VECTOR_ITEM_COUNT] = {
            "First Item",
            "Second Item",
            "Third Item",
            "Fourth Item",
            "Fifth Item",
            "Sixth Item",
            "Seventh Item",
            "Eighth Item",
            "Ninth Item",
            "Tenth Item"
    };
    const char** actual;
    mama_size_t actualLen;
    mama_status status;

    status = msgpackmsgPayload_addVectorString(mPayloadBase, nullptr, 1, expected, VECTOR_ITEM_COUNT);
    ASSERT_EQ(MAMA_STATUS_OK, status);

    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    // Msgpack deserializes all signed integers as int64
    status = msgpackmsgPayload_getVectorString(msg, nullptr, 1, &actual, &actualLen);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(VECTOR_ITEM_COUNT, actualLen);
    for(int i = 0; i < actualLen; i++)
        ASSERT_STREQ(expected[i], actual[i]);

    msgpackmsgPayload_destroy(msg);
}

TEST_F(MsgpackTests, TestMamaSubMsg)
{
    mamaMsg expected;
    msgPayload actual;
    mama_u32_t expectedSubVal = UINT32_MAX;
    mama_u32_t actualSubVal;

    mamaMsg_createForPayloadBridge(&expected, mPayloadBridge);
    mamaMsg_addU32(expected, nullptr, 2, expectedSubVal);

    msgpackmsgPayload_destroy (mPayloadBase);
    msgpackmsgPayload_create (&mPayloadBase);

    msgpackmsgPayload_addMsg(mPayloadBase, nullptr, 1, expected);
    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    mama_status status = msgpackmsgPayload_getMsg(msg, nullptr, 1, &actual);

    msgpackmsgPayload_getU32(actual, nullptr, 2, &actualSubVal);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(expectedSubVal, actualSubVal);
    msgpackmsgPayload_destroy(msg);
    mamaMsg_destroy(expected);
}

TEST_F(MsgpackTests, TestMamaVectorMsg)
{
    mamaMsg expected[2];
    mama_u32_t expectedSubVal[2] = { UINT32_MAX, UINT32_MAX-1 };
    mama_u32_t actualSubVal[2];

    mamaMsg_createForPayloadBridge(&expected[0], mPayloadBridge);
    mamaMsg_addU32(expected[0], nullptr, 10, expectedSubVal[0]);

    mamaMsg_createForPayloadBridge(&expected[1], mPayloadBridge);
    mamaMsg_addU32(expected[1], nullptr, 11, expectedSubVal[1]);

    msgpackmsgPayload_destroy (mPayloadBase);
    msgpackmsgPayload_create (&mPayloadBase);

    msgpackmsgPayload_addVectorMsg(mPayloadBase, nullptr, 1, expected, 2);
    const void *buffer = nullptr;
    mama_size_t len = 0;
    msgpackmsgPayload_serialize(mPayloadBase, &buffer, &len);

    uint8_t c = ((uint8_t*)buffer)[0];

    mama_size_t actualVectorLen;
    const msgPayload* actual;
    mama_status status = msgpackmsgPayload_getVectorMsg(mPayloadBase, nullptr, 1, &actual, &actualVectorLen);

    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(2, actualVectorLen);
    msgPayload msg;
    msgpackmsgPayload_create(&msg);
    msgpackmsgPayload_unSerialize(msg, buffer, len);

    mama_size_t numFields;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    ASSERT_EQ(1, numFields);

    status = msgpackmsgPayload_getVectorMsg(msg, nullptr, 1, &actual, &actualVectorLen);

    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(2, actualVectorLen);

    status = msgpackmsgPayload_getU32(actual[0], nullptr, 10, &actualSubVal[0]);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(expectedSubVal[0], actualSubVal[0]);

    status = msgpackmsgPayload_getU32(actual[1], nullptr, 11, &actualSubVal[1]);
    ASSERT_EQ(MAMA_STATUS_OK, status);
    ASSERT_EQ(expectedSubVal[1], actualSubVal[1]);

    msgpackmsgPayload_destroy(msg);
    mamaMsg_destroy(expected[0]);
    mamaMsg_destroy(expected[1]);
}
